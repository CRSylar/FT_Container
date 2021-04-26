/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:25:24 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/26 11:52:50 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTOPERATOR_HPP
# define LISTOPERATOR_HPP

# include "List.hpp"
# include "Utils.hpp"

namespace ft
{
	template<class T>
	class ListIterator
	{
		public:
			typedef	T			val_type;
			typedef T&			val_ref;
			typedef Node<T>*	Node_ptr;

		protected:
			Node_ptr	ptr;

		private:
			ListIterator(void)	{};
			ListIterator(const ListIterator& src)
			{
				*this = src;
			};
			ListIterator(Node_ptr _ptr)	: ptr(_ptr) {};
			~ListIterator(void)	{};
			Node_ptr	node(void) const
			{
				return ptr;
			};
			ListIterator&	operator=(const ListIterator& _it)
			{
				ptr = _it.ptr;
				return *this;
			};
			ListIterator&	operator++(void)
			{
				ptr = ptr->next;
				return *this;
			};
			ListIterator	operator++(int _n)
			{
				(void)_n;
				ListIterator ret(*this);
				ptr = ptr->next;
				return ret;
			};
			ListIterator&	operator--(void)
			{
				ptr = ptr->prev
				return *this;
			};
			ListIterator	operator--(int _n)
			{
				(void)_n;
				ListIterator ret(*this);
				ptr = ptr->prev;
				return ret;
			};
			bool	operator==(const ListIterator& _it) const
			{
				return (ptr == _it.ptr);
			};
			bool	operator!=(const ListIterator& _it) const
			{
				return (ptr != _it.ptr);
			};
			bool	operator>(const ListIterator& _it) const
			{
				return (ptr > _it.ptr);
			};
			bool	operator<(const ListIterator& _it) const
			{
				return (ptr < _it.ptr);
			};
			bool	operator<=(const ListIterator& _it) const
			{
				return (ptr <= _it.ptr);
			};
			bool	operator>=(const ListIterator& _it) const
			{
				return (ptr >= _it.ptr);
			};
			val_type&	operator*(void)
			{
				return ptr->data;
			};
			val_type*	operator->(void)
			{
				return ptr->data;
			};
			ListIterator	operator+(int _n) const
			{
				ListIterator ret(*this);
				ret += n;
				return ret;
			};
			ListIterator	operator-(int _n) const
			{
				ListIterator ret(*this);
				ret -= n;
				return ret;
			};
			ListIterator&	operator+=(int _n)
			{
				while (_n < 0)
				{
					(*this)--;
					n--;
				}
				while (_n > 0)
				{
					(*this)++;
					n++;
				}
				return *this;
			};
			ListIterator&	operator-=(int _n)
			{
				while (_n > 0)
				{
					(*this)--;
					n--;
				}
				while (_n < 0)
				{
					(*this)++;
					n++;
				}
				return *this;
			};
	};

	template<class T>
	class ConstListIterator
	{
		public:
			typedef	T			val_type;
			typedef T&			val_ref;
			typedef Node<T>*	Node_ptr;

		protected:
			Node_ptr	ptr;

		private:
			ConstListIterator(void)	{};
			ConstListIterator(const ConstListIterator& src)
			{
				*this = src;
			};
			ConstListIterator(Node_ptr _ptr)	: ptr(_ptr) {};
			~ConstListIterator(void)	{};
			Node_ptr	node(void) const
			{
				return ptr;
			};
			ConstListIterator&	operator=(const ConstListIterator& _it)
			{
				ptr = _it.ptr;
				return *this;
			};
			ConstListIterator&	operator++(void)
			{
				ptr = ptr->next;
				return *this;
			};
			ConstListIterator	operator++(int _n)
			{
				(void)_n;
				ConstListIterator ret(*this);
				ptr = ptr->next;
				return ret;
			};
			ConstListIterator&	operator--(void)
			{
				ptr = ptr->prev
				return *this;
			};
			ConstListIterator	operator--(int _n)
			{
				(void)_n;
				ConstListIterator ret(*this);
				ptr = ptr->prev;
				return ret;
			};
			bool	operator==(const ConstListIterator& _it) const
			{
				return (ptr == _it.ptr);
			};
			bool	operator!=(const ConstListIterator& _it) const
			{
				return (ptr != _it.ptr);
			};
			bool	operator>(const ConstListIterator& _it) const
			{
				return (ptr > _it.ptr);
			};
			bool	operator<(const ConstListIterator& _it) const
			{
				return (ptr < _it.ptr);
			};
			bool	operator<=(const ConstListIterator& _it) const
			{
				return (ptr <= _it.ptr);
			};
			bool	operator>=(const ConstListIterator& _it) const
			{
				return (ptr >= _it.ptr);
			};
			val_type&	operator*(void)
			{
				return ptr->data;
			};
			val_type*	operator->(void)
			{
				return ptr->data;
			};
			ConstListIterator	operator+(int _n) const
			{
				ConstListIterator ret(*this);
				ret += n;
				return ret;
			};
			ConstListIterator	operator-(int _n) const
			{
				ConstListIterator ret(*this);
				ret -= n;
				return ret;
			};
			ConstListIterator&	operator+=(int _n)
			{
				while (_n < 0)
				{
					(*this)--;
					n--;
				}
				while (_n > 0)
				{
					(*this)++;
					n++;
				}
				return *this;
			};
			ConstListIterator&	operator-=(int _n)
			{
				while (_n > 0)
				{
					(*this)--;
					n--;
				}
				while (_n < 0)
				{
					(*this)++;
					n++;
				}
				return *this;
			};
	};


}


#endif
