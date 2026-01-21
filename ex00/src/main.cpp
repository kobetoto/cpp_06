/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 07:14:27 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/21 09:58:23 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
  if (ac != 2 || *av[1] == '\0')
    return (std::cerr << "please entre an Argument" << '\n', 1);
  std::string s = av[1];
  ScalarConverter::convert(s);
  return (0);
}
