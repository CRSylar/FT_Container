/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Multiset.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:16:59 by cromalde          #+#    #+#             */
/*   Updated: 2021/05/06 17:06:07 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

static void	print_header(std::string _test)
{
	if (_test == "")
	{
		std::cout << "**************************************" << std::endl;
		std::cout << "*	  Testing MultiSets	  *" << std::endl;
		std::cout << "**************************************" << std::endl;
	}
	else
	{
		std::cout << CYAN << "**************************************" << std::endl;
		std::cout << "*	  Testing "<< _test << "	*" << std::endl;
		std::cout << CYAN << "**************************************" << NC << std::endl;
	}
}

template <typename T1, typename T2>
static void	_print_node(T1 begin, T1 end, T2 __begin, T2 __end)
			{
				for (; begin != end; ++begin)
					std::cout << (*begin) << " - ";
				std::cout << std::endl;
				std::cout << std::endl;
				for (; __begin != __end; ++__begin)
					std::cout << (*__begin) << " - ";
				std::cout << std::endl;
			}

static void	test_constructor(void)
{
	ft::MultiSet<int> mySet;
	std::multiset<int> reSet;

	print_header("Constructor");
	std::cout << "mySet instanciated	" << GRN << GOOD << NC << std::endl;

}

static void	test_max_size(void)
{
	ft::MultiSet<std::string> v1;
	std::multiset<std::string> v2;

	print_header("Max_size");
	if (v1.max_size() == v2.max_size())
		std::cout << "myvec_max_size() == revec_max_size()	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec_max_size() == revec_max_size()	" << _RED << FAIL << NC << std::endl;
}

static void	test_insertion(void)
{
	ft::MultiSet<int> m1;
	std::multiset<int> m2;
	print_header("Insertion");

	m1.insert(42);
	m1.insert(21);
	m1.insert(21);
	m1.insert(14);

	m1.insert(7);
	m1.insert(7);

	m2.insert(42);
	m2.insert(21);
	m2.insert(21);
	m2.insert(14);

	m2.insert(7);
	m2.insert(7);
	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());

	}

static void	test_erase(void)
{
	ft::MultiSet<int> m1;
	std::multiset<int> m2;
	print_header("Erase");

	m1.insert(42);
	m1.insert(21);
	m1.insert(21);
	m1.insert(21);
	m1.insert(14);
	m1.insert(14);
	m1.insert(7);

	m2.insert(42);
	m2.insert(21);
	m2.insert(21);
	m2.insert(21);
	m2.insert(14);
	m2.insert(14);
	m2.insert(7);
	std::cout << "tree before erasing" << std::endl;
	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());


	std::cout << "tree after erasing the element with key = 21" << std::endl;
	m1.erase(21);
	m2.erase(21);
	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());

}

static void	test_swap(void)
{
	ft::MultiSet<int> m1;
	ft::MultiSet<int> m2;
	print_header("Swap");

	m1.insert(42);
	m1.insert(21);
	m1.insert(14);
	m1.insert(7);

	std::cout << "m1 tree : " << std::endl;

	m2.insert(512);
	m2.insert(128);
	m2.insert(1024);
	m2.insert(64);
	m2.insert(2048);
	std::cout << std::endl;
	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());
	std::cout << std::endl;
	std::cout << "m2 tree : " << std::endl;
	std::cout << "swapping m1 - m2.... " << std::endl;
	m1.swap(m2);
	std::cout << "m1 tree : " << std::endl;
	std::cout << std::endl;
	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "m2 tree : " << std::endl;



}

void	testMultiSet()
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
