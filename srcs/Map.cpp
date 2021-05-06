/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:16:59 by cromalde          #+#    #+#             */
/*   Updated: 2021/05/06 17:09:34 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

template <typename T1, typename T2>
static void	_print_node(T1 begin, T1 end, T2 __begin, T2 __end)
			{
				for (; begin != end; ++begin)
					std::cout << (*begin).first << " - ";
				std::cout << std::endl;
				std::cout << std::endl;
				for (; __begin != __end; ++__begin)
					std::cout << (*__begin).first << " - ";
				std::cout << std::endl;
			}

static void	print_header(std::string _test)
{
	if (_test == "")
	{
		std::cout << "**************************************" << std::endl;
		std::cout << "*	  Testing Maps	  *" << std::endl;
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
	ft::Map<std::string, int> mymap;
	std::map<std::string, int> remap;

	print_header("Constructor");
	std::cout << "mymap instanciated	" << GRN << GOOD << NC << std::endl;

}

static void	test_max_size(void)
{
	ft::Map<std::string, int> v1;
	std::map<std::string, int> v2;

	print_header("Max_size");
	if (v1.max_size() == v2.max_size())
		std::cout << "myvec_max_size() == revec_max_size()	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec_max_size() == revec_max_size()	" << _RED << FAIL << NC << std::endl;
}

static void	test_insertion(void)
{
	ft::Map<int, std::string> m1;
	print_header("Insertion");

	m1.insert(std::make_pair(10, "42"));
	m1.insert(std::make_pair(13, "21"));
	m1.insert(std::make_pair(18, "14"));
	m1.insert(std::make_pair(1, "7"));

	std::map<int, std::string> m2;
	m2.insert(std::make_pair(10, "42"));
	m2.insert(std::make_pair(13, "21"));
	m2.insert(std::make_pair(18, "14"));
	m2.insert(std::make_pair(1, "7"));

	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());
}

static void	test_access_op(void)
{
	ft::Map<int, int> m1;
	print_header("Operator[]");

	m1.insert(std::make_pair(10, 42));
	m1.insert(std::make_pair(13, 21));
	m1.insert(std::make_pair(18, 14));
	m1.insert(std::make_pair(1, 7));
	std::map<int, std::string> m2;
	m2.insert(std::make_pair(10, "42"));
	m2.insert(std::make_pair(13, "21"));
	m2.insert(std::make_pair(18, "14"));
	m2.insert(std::make_pair(1, "7"));

	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());
	std::cout << std::endl;

	std::cout << "m1[10] : " << m1[10] << "  <- If 42 is ok" << std::endl;
	std::cout << std::endl;
	std::cout << "now testing insertion with [] " << std::endl << std::endl;
	m1[5];
	m2[5];
	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());

}

static void	test_erase(void)
{
	ft::Map<int, int> m1;
	print_header("Erase");

	m1.insert(std::make_pair(10, 42));
	m1.insert(std::make_pair(13, 21));
	m1.insert(std::make_pair(18, 14));
	m1.insert(std::make_pair(1, 7));

	std::map<int, std::string> m2;
	m2.insert(std::make_pair(10, "42"));
	m2.insert(std::make_pair(13, "21"));
	m2.insert(std::make_pair(18, "14"));
	m2.insert(std::make_pair(1, "7"));

	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());

	std::cout << "tree before erasing" << std::endl;

	std::cout << "tree after erasing the element with key = 13" << std::endl;
	m1.erase(13);
	m2.erase(13);
	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());
}

static void	test_swap(void)
{
	ft::Map<int, int> m1;
	ft::Map<int, int> m2;
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
	std::cout << "m1 tree : " << std::endl;
	_print_node(m1.begin(), m1.end(), m2.begin(), m2.end());
	std::cout << "m2 tree : " << std::endl;
}

void	testMap()
{
	print_header("");

	test_constructor();
	test_max_size();
	test_insertion();
	test_access_op();
	test_erase();
	test_swap();


	print_header(" END ");
	std::cout << std::endl << std::endl;
}
