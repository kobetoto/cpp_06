/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 08:52:10 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/21 10:03:36 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* Prototype */
void conv_to_int(double value, bool impossible);
void conv_to_char(double value, bool impossible);
void conv_to_float(double value, bool impossible);
void conv_to_double(double value, bool impossible);
bool isSpecial(const std::string& str);

/* Canonical form */
ScalarConverter::ScalarConverter(void) {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; };
ScalarConverter &ScalarConverter::operator=(ScalarConverter &src){(void)src;return (*this);};
ScalarConverter::~ScalarConverter() {}

/* Convert */

// strod() Convert string to double
// Parses the C-string str interpreting its content as a floating point number and returns its value as a double.
// If pEnd is not a null pointer, the function also sets the value of pEnd to point to the first character after the number!
void ScalarConverter::convert(std::string str)
{
	double value = 0.0;
	bool impossible = false;

	char *pEnd;
	const char *pStr = str.c_str();

	// Literal char
	if (str.size() == 3 && str[0] == '\'' && str[2] == '\'')
	{
		unsigned char c = static_cast<unsigned char>(str[1]);
		double value = static_cast<double>(c);

		std::cout << "char: ";
		conv_to_char(value, false);
		std::cout << "int: ";
		conv_to_int(value, false);
		std::cout << "float: ";
		conv_to_float(value, false);
		std::cout << "double: ";
		conv_to_double(value, false);
		return;
	}

	//-inf/+inf -inff/+inff nanf
	if (isSpecial(str))
		return;

	value = std::strtod(pStr, &pEnd);

	// check empty str
	if (pStr == pEnd)
		impossible = true;
	// if its non interpretable
	else if (*pEnd != '\0')
	{
		if (!(*pEnd == 'f' && pEnd[1] == '\0'))
			impossible = true;
	}
	// go to convert
	std::cout << "char: ";
	conv_to_char(value, impossible);

	std::cout << "int: ";
	conv_to_int(value, impossible);

	std::cout << "float: ";
	conv_to_float(value, impossible);

	std::cout << "double: ";
	conv_to_double(value, impossible);
	return;
}

/* Utils */

// isnan() Determines if the given number num is a not-a-number (NaN) value.
// isfinite() Determines if the given number num has finite value i.e. it is normal, subnormal or zero, but not infinite or NaN.
void conv_to_char(double value, bool impossible)
{
	if (value < 0 || value > 127 || !std::isfinite(value) || impossible)
		std::cout << "impossible";
	else
	{
		char c = static_cast<char>(value);
		unsigned char uc = static_cast<unsigned char>(c); // UB if isprint(signed char c)
		if (!(isprint(uc)))
			std::cout << "Non displayable";
		else
			std::cout << "'" << uc << "'";
	}
	std::cout << '\n';
	return;
}

// isinf()  Determines if the given floating-point number num is a positive or negative infinity.
void conv_to_int(double value, bool impossible)
{
	if (!std::isfinite(value) || value > INT_MAX || value < INT_MIN || impossible)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << '\n';
	return;
}

// setprecision() When used in an expression out << setprecision(n), sets the precision parameter of the stream out to exactly n.
void conv_to_float(double value, bool impossible)
{
	if (impossible || abs(value) > MAXFLOAT)
		std::cout << "impossible";
	else
	{
		double iptr;
		if (std::isfinite(value) && (std::modf(value, &iptr) == 0))
		{
			float f = static_cast<float>(value);
			std::cout << f << ".0f";
		}
		else
		{
			float f = static_cast<float>(value);
			// save old stream config
			std::streamsize old_prec = std::cout.precision();
			std::ios::fmtflags old_flags = std::cout.flags();

			std::cout << std::setprecision(8) << f << "f";

			// restore
			std::cout.precision(old_prec);
			std::cout.flags(old_flags);
		}
	}
	std::cout << '\n';
	return;
}

// Decomposes given floating point value num into integral and fractional parts, each having the same type and sign as num.
// The integral part (in floating-point format) is stored in the object pointed to by iptr
void conv_to_double(double value, bool impossible)
{
	if (impossible)
		std::cout << "impossible";
	else
	{
		double iptr;
		if (std::isfinite(value) && (std::modf(value, &iptr) == 0))
			std::cout << value << ".0";
		else
		{
			std::ostringstream oss;
			oss << std::setprecision(8) << value;
			std::cout << oss.str();
			// auto restore config at the end
		}
	}
	std::cout << '\n';
	return;
}

bool isSpecial(const std::string& str)
{
    if (str == "nan" || str == "nanf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
        return true;
    }
    if (str == "+inf" || str == "inf" || str == "+inff" || str == "inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: +inff\n";
        std::cout << "double: +inf\n";
        return true;
    }
    if (str == "-inf" || str == "-inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
        return true;
    }
    return false;
}
