/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 08:04:33 by cromalde          #+#    #+#             */
/*   Updated: 2021/05/03 17:44:37 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <iomanip>
# include "./containers/Map.hpp"

int main(void)
{
	ft::Map<int, int> m1;
	ft::Map<int, int> m2;

	m1.insert(std::make_pair(10, 42));
	m1.insert(std::make_pair(13, 21));
	m1.insert(std::make_pair(18, 14));

	m1.insert(std::make_pair(1, 7));


	m2.insert(m1.begin(), m1.end());
	m2.insert(std::make_pair(-3, 45));
	m2.insert(std::make_pair(3, 45));
	m2.print();

	ft::Map<int, int>::iterator it = m2.begin();
	++it;
	m2.erase(it);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	m2.print();
	return 0;
}
