/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:26:46 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/27 10:01:01 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	UTILS_HPP
# define UTILS_HPP

namespace ft
{
	template<typename T>
	void	swap(T& a, T&b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};

	template<class T>
	struct Node
	{
		T		data;
		Node	*prev;
		Node	*next;
	};

}

#endif
