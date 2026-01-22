/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 07:14:27 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/22 09:29:18 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> //rand()
#include <ctime>

Base *generate(void)
{

  int r = std::rand();
  int m = r % 3;
  if (m == 0)
    return (new A());
  else if (m == 1)
    return (new B());
  else
    return (new C());
}

void identify(Base *p)
{
  if (dynamic_cast<A *>(p))
    std::cout << "A\n";
  else if (dynamic_cast<B *>(p))
    std::cout << "B\n";
  else if (dynamic_cast<C *>(p))
    std::cout << "C\n";
}

void identify(Base &p)
{
  try
  {
    (void)dynamic_cast<A &>(p);
    std::cout << "A\n";
    return;
  }
  catch (...){}
  try
  {
    (void)dynamic_cast<B &>(p);
    std::cout << "B\n";
    return;
  }
  catch (...){}
  try
  {
    (void)dynamic_cast<C &>(p);
    std::cout << "C\n";
    return;
  }
  catch (...){}
}


int main()
{
  std::srand(std::time(NULL)); // for rand()

  Base *ran = generate();
  identify(ran);
  identify(*ran);

  delete ran;
  return (0);
}
