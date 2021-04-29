/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:26:46 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/29 12:41:02 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	UTILS_HPP
# define UTILS_HPP

namespace ft
{
	template<typename Iterator>
	size_t	distance(Iterator first, Iterator last)
	{
		size_t diff = 0;
		while (first != last)
		{
			first++;
			diff++;
		}
		return diff;
	}

	template<typename T>
	void	swap(T& a, T&b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template<class T>
	struct Node
	{
		T		data;
		Node	*prev;
		Node	*next;
	};

}

#endif
