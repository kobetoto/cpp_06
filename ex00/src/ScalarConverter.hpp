/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 08:02:59 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/21 09:26:23 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <stdlib.h>	//strtol
#include <cmath> 	//isnan
#include <iomanip> 	//setprecision
#include <climits>
#include <limits>
#include <sstream>	//std::ostringstream
#include <cerrno>


class ScalarConverter{
	
	private:	ScalarConverter( void );
	private:	ScalarConverter(const ScalarConverter &src);
	private:	ScalarConverter &operator=(ScalarConverter &src);
	private:	~ScalarConverter();

	public: static void convert(std::string str);
	//virtual void f() = 0; ~~ bad way to do this
};


#endif // SCALARCONVERTER_HPP


/*
static= linkage interne: chaque .cpp a sa version privée.
*/
