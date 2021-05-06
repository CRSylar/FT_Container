
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

template <typename T1, typename T2>
void	_print_node(T1 begin, T1 end, T2 __begin, T2 __end)
			{
				for (; begin != end; ++begin)
					std::cout << (*begin).first << " - ";
				std::cout << std::endl;
				std::cout << std::endl;
				for (; __begin != __end; ++__begin)
					std::cout << (*__begin).first << " - ";
				std::cout << std::endl;
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
		std::cout << "mymap_max_size() == remap_max_size()	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "mymap_max_size() == remap_max_size()	" << _RED << FAIL << NC << std::endl;
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


	std::multimap<int, int> m2;
	m2.insert(std::make_pair(10, 42));
	m2.insert(std::make_pair(10, 42));
	m2.insert(std::make_pair(13, 21));
	m2.insert(std::make_pair(13, 21));
	m2.insert(std::make_pair(18, 14));
	m2.insert(std::make_pair(1, 7));

	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());
}

static void	test_erase(void)
{
	ft::MultiMap<int, int> m1;
	std::multimap<int, int> m2;
	bool count = false;
	print_header("Erase");

	m1.insert(std::make_pair(10, 42));
	m1.insert(std::make_pair(13, 21));
	m1.insert(std::make_pair(18, 14));

	m1.insert(std::make_pair(1, 7));
	m1.insert(std::make_pair(1, 7));
	m1.insert(std::make_pair(1, 7));

	m2.insert(std::make_pair(10, 42));
	m2.insert(std::make_pair(13, 21));
	m2.insert(std::make_pair(18, 14));

	m2.insert(std::make_pair(1, 7));
	m2.insert(std::make_pair(1, 7));
	m2.insert(std::make_pair(1, 7));
	if (m1.count(1) ==  m2.count(1))
		count = true;
	std::cout << "tree before erasing" << std::endl;
	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());


	std::cout << "tree after erasing the element with key = 1" << std::endl;
	m1.erase(1);
	m2.erase(1);

	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());

	print_header("Count");

	if (count)
		std::cout << "mymap.count(1) == remap.count(1)	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "mymap.count(1) == remap.count(1)	" << _RED << FAIL << NC << std::endl;

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

	m2.insert(std::make_pair(2, 512));
	m2.insert(std::make_pair(4, 128));
	m2.insert(std::make_pair(8, 1024));
	m2.insert(std::make_pair(16, 64));
	m2.insert(std::make_pair(32, 2048));
	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());
	std::cout << "m2 tree : " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "swapping m1 - m2.... " << std::endl;
	m1.swap(m2);
	std::cout << std::endl;
	std::cout << "m1 tree : " << std::endl;

	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());
	std::cout << "m2 tree : " << std::endl;
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
