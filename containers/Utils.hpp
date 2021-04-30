/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:26:46 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/30 12:32:46 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	UTILS_HPP
# define UTILS_HPP

# include <utility>
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

	template <class Key, class T>
	struct RBNode
	{
		std::pair<Key, T> _pair;
		RBNode	*sx;
		RBNode	*dx;
		RBNode	*father;
		bool	color;
		bool	_nil;
	};

}

#endif
