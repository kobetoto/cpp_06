/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 07:14:27 by thodavid          #+#    #+#             */
/*   Updated: 2026/01/22 09:12:55 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int ac, char **av)
{
  (void)ac;
  (void)av;

  t_data *data = new t_data;

  data->t0 = "4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b";
  data->t1 = "0e3e2357e806b6cdb1f70b54c3a3a17b6714ee1f0e68bebb44a74b1efd512098";
  data->t2 = "9b0fc92260312ce44e74ef369f5c66bbb85848f2eddd5a7a1cde251e54ccfdd5";

  std::cout << "data: " << data->t0 << '\n';
  std::cout << "data: " << data->t1 << '\n';
  std::cout << "data: " << data->t2 << '\n'
            << '\n';

  // convert data to uintptr_t
  uintptr_t uint_ptr = Serializer::serialize(data);

  t_data *new_data_ptr = Serializer::deserialize(uint_ptr);

  std::cout << "t_data data: " << data << '\n';
  std::cout << "t_data *new_data_ptr: " << new_data_ptr << '\n';
  std::cout << "uintptr *uint_p: " << uint_ptr << '\n'
            << '\n';

  std::cout << "new_data_ptr: " << new_data_ptr->t0 << '\n';
  std::cout << "new_data_ptr: " << new_data_ptr->t1 << '\n';
  std::cout << "new_data_ptr: " << new_data_ptr->t2 << '\n';

  delete data;
  return (0);
}




/* uintptr_t */ /*
                 *defined in the <cstdint> header
                 *unsigned integer type capable of holding a pointer convert to an int without loss of information
                 *objetif: manipulate addresses
                 */

// int main(){

//   int *ptr = new int(42);

//   //convert ptr to uintptr_t
//   uintptr_t ptrInteger = reinterpret_cast<uintptr_t>(ptr);

//   //operation on the uintptr
//   ptrInteger += 16;

//   //Convert back to ptr type
//   int *modifiedPtr = reinterpret_cast<int*>(ptrInteger);

//   std::cout << "ptr: " << ptr << '\n';
//   std::cout << "ptrInteger: " << ptrInteger << '\n';
//   std::cout << "modifiedPtr: " << modifiedPtr << '\n';

//   return (0);
// }
