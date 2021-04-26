/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:26:46 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/26 11:29:57 by cromalde         ###   ########.fr       */
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
		tmp = b;
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
