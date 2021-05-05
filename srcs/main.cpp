/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:08:14 by cromalde          #+#    #+#             */
/*   Updated: 2021/05/05 14:01:49 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

int		main(int ac, char **av)
{
	std::string		testname;
	if (ac < 2)
		testname = "all";
	else if (ac == 2)
		testname = av[1];
	else
		std::cout << "ERROR: usage -> ./tester [container da testare(1) oppure all per tutti i container base oppure bonus per includere bonus]" << std::endl;

	if (testname == "all" || testname == "bonus")
	{
		testVector();
		testList();
		testStack();
		testQueue();
		testMap();
		/*if (testname == "bonus")
			testDequeue();
			testSet();
			testMultiset();
		*/
		testMultimap();
	}
	else if (testname == "vector")
		testVector();
	else if (testname == "list")
		testList();
	else if (testname == "stack")
		testStack();
	else if (testname == "queue")
		testQueue();
	else if (testname == "map")
		testMap();
	else if (testname == "multimap")
		testMultimap();
	return (0);
}
