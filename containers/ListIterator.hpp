/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:25:24 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/26 18:07:55 by cromalde         ###   ########.fr       */
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

		public:
			ListIterator(void)	{};
			ListIterator(const ListIterator& src)
			{
				*this = src;
			};
			ListIterator(Node_ptr _ptr)	: ptr(_ptr) {};
			virtual ~ListIterator(void)	{};
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
				ptr = ptr->prev;
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
				ret += _n;
				return ret;
			};
			ListIterator	operator-(int _n) const
			{
				ListIterator ret(*this);
				ret -= _n;
				return ret;
			};
			ListIterator&	operator+=(int _n)
			{
				while (_n < 0)
				{
					(*this)--;
					_n--;
				}
				while (_n > 0)
				{
					(*this)++;
					_n++;
				}
				return *this;
			};
			ListIterator&	operator-=(int _n)
			{
				while (_n > 0)
				{
					(*this)--;
					_n--;
				}
				while (_n < 0)
				{
					(*this)++;
					_n++;
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
			const Node_ptr	ptr;

		public:
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
				ptr = ptr->prev;
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
				ret += _n;
				return ret;
			};
			ConstListIterator	operator-(int _n) const
			{
				ConstListIterator ret(*this);
				ret -= _n;
				return ret;
			};
			ConstListIterator&	operator+=(int _n)
			{
				while (_n < 0)
				{
					(*this)--;
					_n--;
				}
				while (_n > 0)
				{
					(*this)++;
					_n++;
				}
				return *this;
			};
			ConstListIterator&	operator-=(int _n)
			{
				while (_n > 0)
				{
					(*this)--;
					_n--;
				}
				while (_n < 0)
				{
					(*this)++;
					_n++;
				}
				return *this;
			};
	};
	template<class T>
	class ReverseListIterator
	{
		public:
			typedef	T			val_type;
			typedef T&			val_ref;
			typedef Node<T>*	Node_ptr;

		protected:
			Node_ptr	ptr;

		public:
			ReverseListIterator(void)	{};
			ReverseListIterator(const ReverseListIterator& src)
			{
				*this = src;
			};
			ReverseListIterator(Node_ptr _ptr)	: ptr(_ptr) {};
			~ReverseListIterator(void)	{};
			Node_ptr	node(void) const
			{
				return ptr;
			};
			ReverseListIterator&	operator=(const ReverseListIterator& _it)
			{
				ptr = _it.ptr;
				return *this;
			};
			ReverseListIterator&	operator++(void)
			{
				ptr = ptr->next;
				return *this;
			};
			ReverseListIterator	operator++(int _n)
			{
				(void)_n;
				ReverseListIterator ret(*this);
				ptr = ptr->next;
				return ret;
			};
			ReverseListIterator&	operator--(void)
			{
				ptr = ptr->prev;
				return *this;
			};
			ReverseListIterator	operator--(int _n)
			{
				(void)_n;
				ReverseListIterator ret(*this);
				ptr = ptr->prev;
				return ret;
			};
			bool	operator==(const ReverseListIterator& _it) const
			{
				return (ptr == _it.ptr);
			};
			bool	operator!=(const ReverseListIterator& _it) const
			{
				return (ptr != _it.ptr);
			};
			bool	operator>(const ReverseListIterator& _it) const
			{
				return (ptr > _it.ptr);
			};
			bool	operator<(const ReverseListIterator& _it) const
			{
				return (ptr < _it.ptr);
			};
			bool	operator<=(const ReverseListIterator& _it) const
			{
				return (ptr <= _it.ptr);
			};
			bool	operator>=(const ReverseListIterator& _it) const
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
			ReverseListIterator	operator+(int _n) const
			{
				ReverseListIterator ret(*this);
				ret += _n;
				return ret;
			};
			ReverseListIterator	operator-(int _n) const
			{
				ReverseListIterator ret(*this);
				ret -= _n;
				return ret;
			};
			ReverseListIterator&	operator+=(int _n) const
			{
				while (_n < 0)
				{
					(*this)--;
					_n--;
				}
				while (_n > 0)
				{
					(*this)++;
					_n++;
				}
				return *this;
			};
			ReverseListIterator&	operator-=(int _n) const
			{
				while (_n > 0)
				{
					(*this)--;
					_n--;
				}
				while (_n < 0)
				{
					(*this)++;
					_n++;
				}
				return *this;
			};
	};

		template<class T>
	class ConstReverseListIterator
	{
		public:
			typedef	T			val_type;
			typedef T&			val_ref;
			typedef Node<T>*	Node_ptr;

		protected:
			Node_ptr	ptr;

		public:
			ConstReverseListIterator(void)	{};
			ConstReverseListIterator(const ConstReverseListIterator& src)
			{
				*this = src;
			};
			ConstReverseListIterator(Node_ptr _ptr)	: ptr(_ptr) {};
			~ConstReverseListIterator(void)	{};
			Node_ptr	node(void) const
			{
				return ptr;
			};
			ConstReverseListIterator&	operator=(const ConstReverseListIterator& _it)
			{
				ptr = _it.ptr;
				return *this;
			};
			ConstReverseListIterator&	operator++(void)
			{
				ptr = ptr->next;
				return *this;
			};
			ConstReverseListIterator	operator++(int _n)
			{
				(void)_n;
				ConstReverseListIterator ret(*this);
				ptr = ptr->next;
				return ret;
			};
			ConstReverseListIterator&	operator--(void)
			{
				ptr = ptr->prev;
				return *this;
			};
			ConstReverseListIterator	operator--(int _n)
			{
				(void)_n;
				ConstReverseListIterator ret(*this);
				ptr = ptr->prev;
				return ret;
			};
			bool	operator==(const ConstReverseListIterator& _it) const
			{
				return (ptr == _it.ptr);
			};
			bool	operator!=(const ConstReverseListIterator& _it) const
			{
				return (ptr != _it.ptr);
			};
			bool	operator>(const ConstReverseListIterator& _it) const
			{
				return (ptr > _it.ptr);
			};
			bool	operator<(const ConstReverseListIterator& _it) const
			{
				return (ptr < _it.ptr);
			};
			bool	operator<=(const ConstReverseListIterator& _it) const
			{
				return (ptr <= _it.ptr);
			};
			bool	operator>=(const ConstReverseListIterator& _it) const
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
			ConstReverseListIterator	operator+(int _n) const
			{
				ConstReverseListIterator ret(*this);
				ret += _n;
				return ret;
			};
			ConstReverseListIterator	operator-(int _n) const
			{
				ConstReverseListIterator ret(*this);
				ret -= _n;
				return ret;
			};
			ConstReverseListIterator&	operator+=(int _n) const
			{
				while (_n < 0)
				{
					(*this)--;
					_n--;
				}
				while (_n > 0)
				{
					(*this)++;
					_n++;
				}
				return *this;
			};
			ConstReverseListIterator&	operator-=(int _n) const
			{
				while (_n > 0)
				{
					(*this)--;
					_n--;
				}
				while (_n < 0)
				{
					(*this)++;
					_n++;
				}
				return *this;
			};
	};
}

#endif
