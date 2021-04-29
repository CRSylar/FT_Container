/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 08:47:15 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/29 08:58:45 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "List.hpp"

namespace ft
{
	template <class T, class Container = ft::List<T> >
	class Queue
	{
		public:
			typedef	T				val_type;
			typedef Container		cont_type;
			typedef unsigned long	size_type;

		protected:
			cont_type	c;

		public:
			explicit	Queue(const cont_type& cont = cont_type()) :
				c(cont)	{}
			Queue(const Queue& src)
			{
				*this = src;
			}
			~Queue(void)	{}
			Queue&		operator=(const Queue& src)
			{
				this->c = src.c;
				return *this;
			}
			bool		empty(void)
			{
				return c.empty();
			}
			size_type	size(void)
			{
				return c.size();
			}
			val_type&	front(void)
			{
				return c.front();
			}
			const val_type&	front(void) const
			{
				return c.front();
			}
			val_type&	back(void)
			{
				return c.back();
			}
			const val_type&	back(void) const
			{
				return c.back();
			}
			void	push(const val_type& value)
			{
				c.push_back(value);
			}
			void	pop(void)
			{
				c.pop_front();
			}

		private:
			template <class A, class B>
			friend bool	operator==(const Queue<A, B>& left, const Queue<A, B>& right);
			template <class A, class B>
			friend bool	operator!=(const Queue<A, B>& left, const Queue<A, B>& right);
			template <class A, class B>
			friend bool	operator<(const Queue<A, B>& left, const Queue<A, B>& right);
			template <class A, class B>
			friend bool	operator<=(const Queue<A, B>& left, const Queue<A, B>& right);
			template <class A, class B>
			friend bool	operator>(const Queue<A, B>& left, const Queue<A, B>& right);
			template <class A, class B>
			friend bool	operator>=(const Queue<A, B>& left, const Queue<A, B>& right);
	};
	template <class A, class Container>
	bool	operator==(const Queue<A, Container>& left, const Queue<A, Container>& right)
	{
		return (left.c == right.c);
	}
	template <class A, class Container>
	bool	operator!=(const Queue<A, Container>& left, const Queue<A, Container>& right)
	{
		return (left.c != right.c);
	}
	template <class A, class Container>
	bool	operator<(const Queue<A, Container>& left, const Queue<A, Container>& right)
	{
		return (left.c < right.c);
	}
	template <class A, class Container>
	bool	operator<=(const Queue<A, Container>& left, const Queue<A, Container>& right)
	{
		return (left.c <= right.c);
	}
	template <class A, class Container>
	bool	operator>(const Queue<A, Container>& left, const Queue<A, Container>& right)
	{
		return (left.c > right.c);
	}
	template <class A, class Container>
	bool	operator>=(const Queue<A, Container>& left, const Queue<A, Container>& right)
	{
		return (left.c >= right.c);
	}
}

#endif
