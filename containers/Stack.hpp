/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:23:05 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/28 14:38:24 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "List.hpp"

namespace ft
{
	template <class T, class Container = ft::List<T> >
	class Stack
	{
		public:
			typedef T				val_type;
			typedef Container		cont_type;
			typedef unsigned long	size_type;

		protected:
			cont_type	c;

		public:
			explicit	Stack(const cont_type& cont = cont_type()) : c(cont) {}
						Stack(const Stack& src)
						{
							*this = src;
						}
						~Stack(void)	{}
			Stack&		operator=(const Stack& src)
			{
				c = src.c;
				return *this;
			}
			bool 		empty(void) const
			{
				return c.empty();
			}
			size_type	size(void) const
			{
				return c.size();
			}
			val_type&	top(void)
			{
				return c.back();
			}
			const val_type&	top(void) const
			{
				return c.back();
			}
			void		push(const val_type& val)
			{
				c.push_back(val);
			}
			void		pop(void)
			{
				c.pop_back();
			}
		private:
			template <class A, class B>
			friend bool	operator==(const Stack<A, B>& left, const Stack<A, B>& right);
			template <class A, class B>
			friend bool	operator!=(const Stack<A, B>& left, const Stack<A, B>& right);
			template <class A, class B>
			friend bool	operator<(const Stack<A, B>& left, const Stack<A, B>& right);
			template <class A, class B>
			friend bool	operator<=(const Stack<A, B>& left, const Stack<A, B>& right);
			template <class A, class B>
			friend bool	operator>(const Stack<A, B>& left, const Stack<A, B>& right);
			template <class A, class B>
			friend bool	operator>=(const Stack<A, B>& left, const Stack<A, B>& right);
	};
	template <class A, class B>
	bool	operator==(const Stack<A, B>& left, const Stack<A, B>& right)
	{
		return (left.c == right.c);
	}
	template <class A, class B>
	bool	operator!=(const Stack<A, B>& left, const Stack<A, B>& right)
	{
		return (left.c != right.c);
	}
	template <class A, class B>
	bool	operator<(const Stack<A, B>& left, const Stack<A, B>& right)
	{
		return (left.c < right.c);
	}
	template <class A, class B>
	bool	operator<=(const Stack<A, B>& left, const Stack<A, B>& right)
	{
		return (left.c <= right.c);
	}
	template <class A, class B>
	bool	operator>(const Stack<A, B>& left, const Stack<A, B>& right)
	{
		return (left.c > right.c);
	}
	template <class A, class B>
	bool	operator>=(const Stack<A, B>& left, const Stack<A, B>& right)
	{
		return (left.c >= right.c);
	}
}

#endif
