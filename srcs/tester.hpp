/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:17:39 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/29 11:19:47 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
# define TESTER_HPP

# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <queue>
# include <stack>
# include "../containers/List.hpp"
# include "../containers/Vector.hpp"
# include "../containers/Stack.hpp"
# include "../containers/Queue.hpp"

# define GOOD "✓"
# define FAIL "❌"

# define CYAN	"\x1B[36m"
# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define NC		"\033[0m"

void	testVector(void);
void	testList(void);
void	testStack(void);
void	testQueue(void);
//void	testMap(void);

template <typename T>
bool operator==(ft::Vector<T> &a, std::vector<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return (false);
	}
	return (true);
}

template <typename T>
bool operator==(ft::List<T> &a, std::list<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::List<T>::iterator it = a.begin();
	typename std::list<T>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (*it != *it2)
			return (false);
		++it;
		++it2;
	}
	return (true);
}

#endif
