/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 08:04:33 by cromalde          #+#    #+#             */
/*   Updated: 2021/05/04 12:23:13 by cromalde         ###   ########.fr       */
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
//	m1.print();


	std::cout << "m1.size() = " << m1.size() << std::endl;

	m2.insert(m1.begin(), m1.end());
	m2.insert(std::make_pair(-3, 45));
	m2.insert(std::make_pair(3, 45));
//	m2.print();

	std::cout << "m2.size() = " << m2.size() << std::endl;

	ft::Map<int, int>::iterator it = m2.begin();
	++it;
	m2.erase(it);
	std::cout << "m2.size() = " << m2.size() << std::endl;


	ft::Map<int, int>::reverse_iterator rit = m2.rbegin();
	++rit;
	m2.erase(rit);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	m2.insert(std::make_pair(13, 21));

//	if (m2.find(-3) != m2.end())
//		std::cout << "found!" << std::endl;


//	std::cout << "m2.size() = " << m2.size() <<  " / " << m2[2] << std::endl;
//	m2.print();

	m1.swap(m2);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	m1.print();
	std::cout << std::endl;
	m2.print();

	return 0;
}
