/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:16:59 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/29 14:40:58 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

static void	print_header(std::string _test)
{
	if (_test == "")
	{
		std::cout << CYAN << "**************************************" << std::endl;
		std::cout << "*	  Testing Lists	  *" << std::endl;
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
	ft::List<int> myvec;
	std::list<int> revec;

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


static void	test_copy_constructor(void)
{
	ft::List<int> myvec;
	std::list<int> revec;

	print_header("Copy_Constr");
	myvec.push_back(1);
	myvec.push_back(10);
	myvec.push_back(42);
	revec.push_back(1);
	revec.push_back(10);
	revec.push_back(42);

	ft::List<int> mycopy(myvec);
	std::list<int> recopy(revec);

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


static void	test_max_size(void)
{
	ft::List<std::string> v1;
	std::list<std::string> v2;

	print_header("Max_size");
	if (v1.max_size() == v2.max_size())
		std::cout << "myvec_max_size() == revec_max_size()	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec_max_size() == revec_max_size()	" << RED << FAIL << NC << std::endl;
}

static void	test_resize(void)
{
	ft::List<std::string> myvec;
	std::list<std::string> revec;

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

static void	test_front_back(void)
{
	ft::List<int> myvec;
	std::list<int> revec;

	print_header("Front & Back");
	myvec.push_back(1);
	revec.push_back(1);
	myvec.push_back(10);
	revec.push_back(10);
	myvec.push_front(42);
	revec.push_front(42);
	myvec.push_front(14);
	revec.push_front(14);
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

static void	test_assign(void)
{
	ft::List<std::string> myvec;
	std::list<std::string> revec;

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

static void	test_insert(void)
{
	ft::List<std::string> myvec;
	std::list<std::string> revec;

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

static void	test_erase(void)
{
	ft::List<std::string> myvec;
	std::list<std::string> revec;

	print_header("Erase");

	myvec.push_back("da eliminare");
	revec.push_back("da eliminare");
	myvec.push_back("test");
	revec.push_back("test");
	myvec.push_back("prova");
	revec.push_back("prova");
	std::cout << MAG;
	for (ft::List<std::string>::iterator it = myvec.begin(); it != myvec.end(); it++)
		std::cout << *it << " - ";
	std::cout << std::endl;
	for (std::list<std::string>::iterator it = revec.begin(); it != revec.end(); it++)
		std::cout << *it << " - ";
	std::cout << std::endl;
	myvec.erase(myvec.begin());
	revec.erase(revec.begin());
	for (ft::List<std::string>::iterator it = myvec.begin(); it != myvec.end(); it++)
		std::cout << *it << " - ";
	std::cout << std::endl;
	for (std::list<std::string>::iterator it = revec.begin(); it != revec.end(); it++)
		std::cout << *it << " - ";
	std::cout << std::endl;
	std::cout << NC;
	if (myvec == revec)
		std::cout << "myvec == revec	" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "myvec == revec	" << RED << FAIL << NC << std::endl;
}

static void	test_swap(void)
{
	ft::List<int> myvec;
	std::list<int> revec;
	ft::List<int> myswap;
	std::list<int> reswap;

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

static void	test_operators(void)
{
	print_header("Operators");
	ft::List<int> v1;
	std::list<int> v2;
	ft::List<int> v3;
	std::list<int> v4;

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
		std::cout << "v1 == v3		" << RED << FAIL << NC << std::endl;
	v3.push_back(42);
	if (v1 != v3)
		std::cout << "v1 != v3		" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "v1 != v3		" << RED << FAIL << NC << std::endl;

	if (v3 >= v1)
		std::cout << "v1 >= v3		" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "v1 >= v3		" << RED << FAIL << NC << std::endl;

	if (v1 <= v3)
		std::cout << "v1 <= v3		" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "v1 <= v3		" << RED << FAIL << NC << std::endl;
}

static void	test_reverse(void)
{
	print_header("Reverse");
	int test[] = {0,1, 2, 3, 4, 5, 6, 7, 8, 9, 42, 21};
	ft::List<int> l1(test, test + 12);
	std::list<int> l2(test, test + 12);
	l1.reverse();
	l2.reverse();
	if (l1 == l2)
		std::cout << "v1 <= v3		" << GRN << GOOD << NC << std::endl;
	else
		std::cout << "v1 <= v3		" << RED << FAIL << NC << std::endl;
}

void	testList(void)
{
	std::srand(time(0));
	print_header("");

	test_constructor();
	test_copy_constructor();
	test_max_size();
	test_resize();
	test_front_back();
	test_assign();
	test_insert();
	test_erase();
	test_swap();
	test_reverse();
	test_operators();

	print_header(" END ");
	std::cout << std::endl << std::endl;
}
