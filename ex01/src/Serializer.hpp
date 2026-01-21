/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:47:08 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/21 12:04:14 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h> // uintptr_t was not in C++. It's in C99
/*
an unsigned integer type with the property that any valid pointer to void can be converted to this type,
then converted back to pointer to void,
and the result will compare equal to the original pointer
*/

typedef struct s_data{
	std::string t0;
	std::string t1;
	std::string t2;
} t_data;

class Serializer
{
	private:	Serializer( void );
	private:	Serializer(const Serializer &src);
	private:	Serializer &operator=(Serializer &src);
	private:	~Serializer();

	public:		static uintptr_t serialize(t_data* ptr);
	public:		static t_data* deserialize(uintptr_t raw);
};

#endif //SERIALIZER_H
