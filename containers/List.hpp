/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 09:40:44 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/26 11:12:03 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

namespace ft
{
	template <typename T>
	class List
	{
		public:
			List();
			List(size_t n, const T& val);
		//	List(iterator begin, iterator end);
			List(const List& src);
			~List();
		private:

	};
}
#endif
