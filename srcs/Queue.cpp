/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:16:59 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/29 15:11:13 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

static void	print_header(std::string _test)
{
	if (_test == "")
	{
		std::cout << MAG << "**************************************" << std::endl;
		std::cout << "*	  Testing Queues	  *" << std::endl;
		std::cout << MAG << "**************************************" << NC << std::endl;
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
	ft::Queue<int> myvec;
	std::queue<int> revec;

	print_header("Constructor");
	if (myvec.size() == revec.size())
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << _RED << FAIL << NC << std::endl;
	myvec.push(1);
	myvec.push(10);
	myvec.push(42);
	revec.push(1);
	revec.push(10);
	revec.push(42);
	if (myvec.size() == revec.size())
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << _RED << FAIL << NC << std::endl;
}


static void	test_front_back(void)
{
	ft::Queue<int> myvec;
	std::queue<int> revec;

	print_header("Front & Back");
	myvec.push(1);
	revec.push(1);
	myvec.push(10);
	revec.push(10);
	myvec.push(42);
	revec.push(42);
	myvec.push(14);
	revec.push(14);
	myvec.push(30);
	revec.push(30);
	if (myvec.front() == revec.front())
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << _RED << FAIL << NC << std::endl;
	if (myvec.back() == revec.back())
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << _RED << FAIL << NC << std::endl;
}

void	testQueue(void)
{
	std::srand(time(0));
	print_header("");

	test_constructor();
	test_front_back();

	print_header(" END ");
	std::cout << std::endl << std::endl;
}
