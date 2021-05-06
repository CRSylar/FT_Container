/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:16:59 by cromalde          #+#    #+#             */
/*   Updated: 2021/05/06 15:50:07 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

static void	print_header(std::string _test)
{
	if (_test == "")
	{
		std::cout << CYAN << "**************************************" << std::endl;
		std::cout << "*	  Testing Deque	  *" << std::endl;
		std::cout << CYAN << "**************************************" << NC << std::endl;
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
	ft::Deque<int> myvec;
	std::deque<int> revec;

	print_header("Constructor");
	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << _RED << FAIL << NC << std::endl;
	myvec.push_back(1);
	myvec.push_back(10);
	myvec.push_back(42);
	revec.push_back(1);
	revec.push_back(10);
	revec.push_back(42);
	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << _RED << FAIL << NC << std::endl;
}


static void	test_copy_constructor(void)
{
	ft::Deque<int> myvec;
	std::deque<int> revec;

	print_header("Copy_Constr");
	myvec.push_back(1);
	myvec.push_back(10);
	myvec.push_back(42);
	revec.push_back(1);
	revec.push_back(10);
	revec.push_back(42);

	ft::Deque<int> mycopy(myvec);
	std::deque<int> recopy(revec);

	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << _RED << FAIL << NC << std::endl;
	if (myvec == mycopy)
		std::cout << "myvec == mycopy	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == mycopy	" << _RED << FAIL << NC << std::endl;
	if (mycopy == revec)
		std::cout << "revec == mycopy	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "revec == mycopy	" << _RED << FAIL << NC << std::endl;
}


static void	test_max_size(void)
{
	ft::Deque<std::string> v1;
	std::deque<std::string> v2;

	print_header("Max_size");
	if (v1.max_size() == v2.max_size())
		std::cout << "myvec_max_size() == revec_max_size()	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec_max_size() == revec_max_size()	" << _RED << FAIL << NC << std::endl;
}

static void	test_resize(void)
{
	ft::Deque<std::string> myvec;
	std::deque<std::string> revec;

	print_header("Resize");
	myvec.resize(10, "test");
	revec.resize(10, "test");
	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << _RED << FAIL << NC << std::endl;
	myvec.resize(2, "42");
	revec.resize(2, "42");
	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << _RED << FAIL << NC << std::endl;

}

static void	test_access_op(void)
{
	ft::Deque<int> myvec;
	std::deque<int> revec;

	print_header("[] operator & at()");
	myvec.push_back(1);
	revec.push_back(1);
	myvec.push_back(10);
	revec.push_back(10);
	myvec.push_back(42);
	revec.push_back(42);
	myvec.push_back(14);
	revec.push_back(14);
	myvec.push_back(30);
	revec.push_back(30);
	for (int i = 0; i < 4; i++)
	{
		if (myvec[i] == revec[i])
			std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
		else
			std::cout << "myvec == revec	" << _RED << FAIL << NC << std::endl;
	}
	for(int i = 100; i < 103; i++)
	{
		try
		{
			std::cout << myvec[i] << _RED << FAIL << NC << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << ":" << std::string(10, ' ') << GRN << GOOD << NC << std::endl;
		}
	}
	try
	{
		std::cout << myvec[-1] << _RED << FAIL << NC << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ":" << std::string(10, ' ') << GRN << GOOD << NC << std::endl;
	}
}

static void	test_front_back(void)
{
	ft::Deque<int> myvec;
	std::deque<int> revec;

	print_header("Front & Back");
	myvec.push_back(1);
	revec.push_back(1);
	myvec.push_back(10);
	revec.push_back(10);
	myvec.push_back(42);
	revec.push_back(42);
	myvec.push_back(14);
	revec.push_back(14);
	myvec.push_back(30);
	revec.push_back(30);
	if (myvec.front() == revec.front())
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << _RED << FAIL << NC << std::endl;
	if (myvec.back() == revec.back())
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << _RED << FAIL << NC << std::endl;
}

static void	test_assign(void)
{
	ft::Deque<std::string> myvec;
	std::deque<std::string> revec;

	print_header("Assign");
	myvec.push_back("2");
	revec.push_back("2");
	myvec.assign(3, "42");
	revec.assign(3, "42");
	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << _RED << FAIL << NC << std::endl;
}

static void	test_insert(void)
{
	ft::Deque<std::string> myvec;
	std::deque<std::string> revec;

	print_header("Insert");
	myvec.push_back("ciao");
	myvec.push_back("ciao");
	myvec.push_back("ciao");
	myvec.push_back("ciao");
	revec.push_back("ciao");
	revec.push_back("ciao");
	revec.push_back("ciao");
	revec.push_back("ciao");
	myvec.insert(myvec.begin(), "inserito");
	revec.insert(revec.begin(), "inserito");
	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << _RED << FAIL << NC << std::endl;
}

static void	test_erase(void)
{
	ft::Deque<std::string> myvec;
	std::deque<std::string> revec;

	print_header("Erase");

	myvec.push_back("da eliminare");
	revec.push_back("da eliminare");
	myvec.push_back("test");
	revec.push_back("test");
	myvec.push_back("prova");
	revec.push_back("prova");
	std::cout << MAG;
	for (ft::Deque<std::string>::iterator it = myvec.begin(); it != myvec.end(); it++)
		std::cout << *it << " - ";
	std::cout << std::endl;
	for (std::deque<std::string>::iterator it = revec.begin(); it != revec.end(); it++)
		std::cout << *it << " - ";
	std::cout << std::endl;
	myvec.erase(myvec.begin());
	revec.erase(revec.begin());
	for (ft::Deque<std::string>::iterator it = myvec.begin(); it != myvec.end(); it++)
		std::cout << *it << " - ";
	std::cout << std::endl;
	for (std::deque<std::string>::iterator it = revec.begin(); it != revec.end(); it++)
		std::cout << *it << " - ";
	std::cout << std::endl;
	std::cout << NC;
	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << _RED << FAIL << NC << std::endl;
}

static void	test_swap(void)
{
	ft::Deque<int> myvec;
	std::deque<int> revec;
	ft::Deque<int> myswap;
	std::deque<int> reswap;

	print_header("Swap");
	myvec.push_back(1);
	revec.push_back(1);
	myvec.push_back(2);
	revec.push_back(2);
	myvec.push_back(42);
	revec.push_back(42);
	myswap.push_back(21);
	reswap.push_back(21);
	myswap.push_back(55);
	reswap.push_back(55);

	myvec.swap(myswap);
	revec.swap(reswap);
	if (myvec == revec)
		std::cout << "myvec == revec		" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec		" << _RED << FAIL << NC << std::endl;
	if (myswap == reswap)
		std::cout << "myswap == reswap	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myswap == reswap	" << _RED << FAIL << NC << std::endl;
}

static void	test_operators(void)
{
	print_header("Operators");
	ft::Deque<int> v1;
	std::deque<int> v2;
	ft::Deque<int> v3;
	std::deque<int> v4;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v3 = v1;
	v4 = v2;
	if (v1 == v3)
		std::cout << "v1 == v3		" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "v1 == v3		" << _RED << FAIL << NC << std::endl;
	v3.push_back(42);
	if (v1 != v3)
		std::cout << "v1 != v3		" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "v1 != v3		" << _RED << FAIL << NC << std::endl;

	if (v3 >= v1)
		std::cout << "v1 >= v3		" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "v1 >= v3		" << _RED << FAIL << NC << std::endl;

	if (v1 <= v3)
		std::cout << "v1 <= v3		" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "v1 <= v3		" << _RED << FAIL << NC << std::endl;
}

void	testDeque(void)
{
	print_header("");

	test_constructor();
	test_copy_constructor();
	test_max_size();
	test_resize();
	test_access_op();
	test_front_back();
	test_assign();
	test_insert();
	test_erase();
	test_swap();
	test_operators();

	print_header(" END ");
	std::cout << std::endl << std::endl;
}
