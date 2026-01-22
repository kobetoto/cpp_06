/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:58:12 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/22 09:13:54 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}
Serializer::Serializer(const Serializer &src) { (void)src; };
Serializer &Serializer::operator=(Serializer &src){(void)src; return (*this);};
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(t_data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

t_data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<t_data*>(raw));
}
