/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 07:14:27 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/21 14:52:15 by thodavid         ###   ########.fr       */
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
  A *a = dynamic_cast<A*>(p);
  if (a)
    std::cout << "Actual type of the object pointed by [p] is [A] " << '\n';
  B *b = dynamic_cast<B*>(p);
  if (b)
    std::cout << "Actual type of the object pointed by [p] is [B] " << '\n';
  C *c = dynamic_cast<C*>(p);
  if (c)
    std::cout << "Actual type of the object pointed by [p] is [C] " << '\n';
}

void identify(Base &p)
{
  try{
    A a = dynamic_cast<A&>(p);
    std::cout << "Type of the object referenced by [p] is [A] " << '\n';
    return;
  }
  catch(std::exception &e){
    std::cerr << e.what() << std::endl;
  }
    try{
    B b = dynamic_cast<B&>(p);
    std::cout << "Type of the object referenced by [p] is [B] " << '\n';
    return;
  }
  catch(std::exception &e){
    std::cerr << e.what() << std::endl;
  }
  try{
    C c = dynamic_cast<C&>(p);
    std::cout << "Type of the object referenced by [p] is [C] " << '\n';
    return;
  }
  catch(std::exception &e){
    std::cerr << e.what() << std::endl;
  }
}

int main()
{
  std::srand(std::time(NULL)); // for rand()

  Base *ran = generate();
  identify(ran);
  identify(ran);

  return (0);
}
