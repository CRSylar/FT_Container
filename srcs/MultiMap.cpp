
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MultiMap.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:16:59 by cromalde          #+#    #+#             */
/*   Updated: 2021/05/04 16:57:39 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

static void	print_header(std::string _test)
{
	if (_test == "")
	{
		std::cout << "**************************************" << std::endl;
		std::cout << "*	  Testing MultiMaps	  *" << std::endl;
		std::cout << "**************************************" << std::endl;
	}
	else
	{
		std::cout << CYAN << "**************************************" << std::endl;
		std::cout << "*	  Testing "<< _test << "	*" << std::endl;
		std::cout << CYAN << "**************************************" << NC << std::endl;
	}
}

static void	test_constructor(void)
{
	ft::MultiMap<std::string, int> mymap;

	print_header("Constructor");
	std::cout << "mymap instanciated	" << GRN << GOOD << NC << std::endl;

}

static void	test_max_size(void)
{
	ft::MultiMap<std::string, int> v1;
	std::multimap<std::string, int> v2;

	print_header("Max_size");
	if (v1.max_size() == v2.max_size())
		std::cout << "myvec_max_size() == revec_max_size()	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec_max_size() == revec_max_size()	" << _RED << FAIL << NC << std::endl;
}

static void	test_insertion(void)
{
	ft::MultiMap<int, int> m1;
	print_header("Insertion");

	m1.insert(std::make_pair(10, 42));
	m1.insert(std::make_pair(10, 42));
	m1.insert(std::make_pair(13, 21));
	m1.insert(std::make_pair(13, 21));
	m1.insert(std::make_pair(18, 14));

	m1.insert(std::make_pair(1, 7));
	std::cout << "m1 : " << std::endl << std::endl;
	m1.print();
}

static void	test_erase(void)
{
	ft::MultiMap<int, int> m1;
	print_header("Erase");

	m1.insert(std::make_pair(10, 42));
	m1.insert(std::make_pair(13, 21));
	m1.insert(std::make_pair(18, 14));

	m1.insert(std::make_pair(1, 7));
	m1.insert(std::make_pair(1, 7));
	m1.insert(std::make_pair(1, 7));
	std::cout << "tree before erasing" << std::endl;
	m1.print();

	std::cout << "number of key 1 -> " << m1.count(1) << std::endl;

	std::cout << "tree after erasing the element with key = 1" << std::endl;
	m1.erase(1);
	m1.print();

}

static void	test_swap(void)
{
	ft::MultiMap<int, int> m1;
	ft::MultiMap<int, int> m2;
	print_header("Swap");

	m1.insert(std::make_pair(10, 42));
	m1.insert(std::make_pair(13, 21));
	m1.insert(std::make_pair(18, 14));
	m1.insert(std::make_pair(1, 7));

	std::cout << "m1 tree : " << std::endl;
	m1.print();

	m2.insert(std::make_pair(2, 512));
	m2.insert(std::make_pair(4, 128));
	m2.insert(std::make_pair(8, 1024));
	m2.insert(std::make_pair(16, 64));
	m2.insert(std::make_pair(32, 2048));
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "m2 tree : " << std::endl;
	m2.print();
	std::cout << "swapping m1 - m2.... " << std::endl;
	m1.swap(m2);
	std::cout << "m1 tree : " << std::endl;
	m1.print();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "m2 tree : " << std::endl;
	m2.print();


}

void	testMultimap()
{
	print_header("");

	test_constructor();
	test_max_size();
	test_insertion();
	test_erase();
	test_swap();


	print_header(" END ");
	std::cout << std::endl << std::endl;
}
