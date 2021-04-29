/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:16:59 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/29 13:28:28 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

void	print_header(std::string _test)
{
	if (_test == "")
	{
		std::cout << CYAN << "**************************************" << std::endl;
		std::cout << "*	  Testing Vectors	  *" << std::endl;
		std::cout << CYAN << "**************************************" << NC << std::endl;
	}
	else
	{
		std::cout << CYAN << "**************************************" << std::endl;
		std::cout << "*	  Testing "<< _test << "	*" << std::endl;
		std::cout << CYAN << "**************************************" << NC << std::endl;
	}
}

void	test_constructor(void)
{
	ft::Vector<int> myvec;
	std::vector<int> revec;

	print_header("Constructor");
	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << RED << FAIL << NC << std::endl;
	myvec.push_back(1);
	myvec.push_back(10);
	myvec.push_back(42);
	revec.push_back(1);
	revec.push_back(10);
	revec.push_back(42);
	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << RED << FAIL << NC << std::endl;
}


void	test_copy_constructor(void)
{
	ft::Vector<int> myvec;
	std::vector<int> revec;

	print_header("Copy_Constr");
	myvec.push_back(1);
	myvec.push_back(10);
	myvec.push_back(42);
	revec.push_back(1);
	revec.push_back(10);
	revec.push_back(42);

	ft::Vector<int> mycopy(myvec);
	std::vector<int> recopy(revec);

	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << RED << FAIL << NC << std::endl;
	if (myvec == mycopy)
		std::cout << "myvec == mycopy	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == mycopy	" << RED << FAIL << NC << std::endl;
	if (mycopy == revec)
		std::cout << "revec == mycopy	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "revec == mycopy	" << RED << FAIL << NC << std::endl;
}


void	test_max_size(void)
{
	ft::Vector<std::string> v1;
	std::vector<std::string> v2;

	print_header("Max_size");
	if (v1.max_size() == v2.max_size())
		std::cout << "myvec_max_size() == revec_max_size()	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec_max_size() == revec_max_size()	" << RED << FAIL << NC << std::endl;
}

void	test_resize(void)
{
	ft::Vector<std::string> myvec;
	std::vector<std::string> revec;

	print_header("Resize");
	myvec.resize(10, "test");
	revec.resize(10, "test");
	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << RED << FAIL << NC << std::endl;
	myvec.resize(2, "42");
	revec.resize(2, "42");
	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << RED << FAIL << NC << std::endl;

}

void	test_access_op(void)
{
	ft::Vector<int> myvec;
	std::vector<int> revec;

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
			std::cout << "myvec == revec	" << RED << FAIL << NC << std::endl;
	}
	for(int i = 100; i < 103; i++)
	{
		try
		{
			std::cout << myvec[i] << RED << FAIL << NC << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << ":" << std::string(10, ' ') << GRN << GOOD << NC << std::endl;
		}
	}
	try
	{
		std::cout << myvec[-1] << RED << FAIL << NC << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ":" << std::string(10, ' ') << GRN << GOOD << NC << std::endl;
	}
}

void	test_front_back(void)
{
	ft::Vector<int> myvec;
	std::vector<int> revec;

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
		std::cout << "myvec == revec	" << RED << FAIL << NC << std::endl;
	if (myvec.back() == revec.back())
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << RED << FAIL << NC << std::endl;
}

void	test_assign(void)
{
	ft::Vector<std::string> myvec;
	std::vector<std::string> revec;

	print_header("Assign");
	myvec.push_back("2");
	revec.push_back("2");
	myvec.assign(3, "42");
	revec.assign(3, "42");
	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << RED << FAIL << NC << std::endl;
}

void	test_insert(void)
{
	ft::Vector<std::string> myvec;
	std::vector<std::string> revec;

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
		std::cout << "myvec == revec	" << RED << FAIL << NC << std::endl;
}

void	test_erase(void)
{
	ft::Vector<std::string> myvec(3, "test");
	std::vector<std::string> revec(3, "test");

	print_header("Erase");
	myvec.push_back("prova");
	revec.push_back("prova");
	myvec.erase(myvec.begin());
	revec.erase(revec.begin());

	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << RED << FAIL << NC << std::endl;
}

void	test_swap(void)
{
	ft::Vector<int> myvec;
	std::vector<int> revec;
	ft::Vector<int> myswap;
	std::vector<int> reswap;

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
		std::cout << "myvec == revec		" << RED << FAIL << NC << std::endl;
	if (myswap == reswap)
		std::cout << "myswap == reswap	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myswap == reswap	" << RED << FAIL << NC << std::endl;
}

void	testVector(void)
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
//	test_operators();
}
