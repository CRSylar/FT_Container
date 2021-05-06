/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeIterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:25:24 by cromalde          #+#    #+#             */
/*   Updated: 2021/05/06 15:18:54 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUEITERATOR_HPP
# define DEQUEITERATOR_HPP

# include "Utils.hpp"

namespace ft
{
	template <class T>
	class DequeIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef DQNode<T>* pointer;
		protected:
			pointer _ptr;
		public:
			DequeIterator(void)
			{
				_ptr->__first = _ptr->_data;
				_ptr->__ptr = _ptr->__first;
				_ptr->__last = _ptr->_data;
			}
			DequeIterator(const DequeIterator &other)
			{
				*this = other;
			}
			DequeIterator(pointer ptr)
			: _ptr(ptr)
			{}
			~DequeIterator(void)
			{}
			pointer node(void) const
			{
				return (_ptr);
			}
			DequeIterator &operator=(const DequeIterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			}
			DequeIterator &operator++(void)
			{
				if (_ptr->__ptr - _ptr->_data < 32)
					_ptr->__ptr += 1;
				else
					_ptr = _ptr->next;
				return (*this);
			}
			DequeIterator &operator--(void)
			{
				if (_ptr->__ptr - _ptr->_data > 0)
					_ptr->__ptr -= 1;
				else
					_ptr = _ptr->prev;
				return (*this);
			}
			DequeIterator operator++(int)
			{
				DequeIterator tmp(*this);
				operator++();
				return (tmp);
			}
			DequeIterator operator--(int)
			{
				DequeIterator tmp(*this);
				operator--();
				return (tmp);
			}
			bool operator==(const DequeIterator &other) const
			{
				return (_ptr == other._ptr);
			}
			bool operator!=(const DequeIterator &other) const
			{
				return (_ptr != other._ptr);
			}
			bool operator>(const DequeIterator &other) const
			{
				return (_ptr > other._ptr);
			}
			bool operator>=(const DequeIterator &other) const
			{
				return (_ptr >= other._ptr);
			}
			bool operator<(const DequeIterator &other) const
			{
				return (_ptr < other._ptr);
			}
			bool operator<=(const DequeIterator &other) const
			{
				return (_ptr <= other._ptr);
			}
			value_type &operator*(void)
			{
				return (_ptr->__ptr);
			}
			value_type *operator->(void)
			{
				return (_ptr->__ptr);
			}
			DequeIterator operator+(int n) const
			{
				DequeIterator tmp(*this);
				tmp += n;
				return (tmp);
			}
			DequeIterator operator-(int n) const
			{
				DequeIterator tmp(*this);
				tmp -= n;
				return (tmp);
			}
			DequeIterator &operator+=(int n)
			{
				while (n < 0)
				{
					operator--();
					n++;
				}
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			DequeIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				while (n < 0)
				{
					operator++();
					n++;
				}
				return (*this);
			}
	};
	template <class T>
	class ConstDequeIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef Node<T>* pointer;
		protected:
			pointer _ptr;
		public:
			ConstDequeIterator(void)
			{}
			ConstDequeIterator(const ConstDequeIterator &other)
			{
				*this = other;
			}
			ConstDequeIterator(pointer ptr)
			: _ptr(ptr)
			{}
			~ConstDequeIterator(void)
			{}
			pointer node(void) const
			{
				return (_ptr);
			}
			ConstDequeIterator &operator=(const ConstDequeIterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			}
			ConstDequeIterator &operator++(void)
			{
				if (_ptr->__ptr - _ptr->data < 32)
					_ptr->__ptr += 1;
				else
					_ptr = _ptr->next;
				return (*this);
			}
			ConstDequeIterator &operator--(void)
			{
				if (_ptr->__ptr - _ptr->_data > 0)
					_ptr->__ptr -= 1;
				else
					_ptr = _ptr->prev;
				return (*this);
			}
			ConstDequeIterator operator++(int)
			{
				ConstDequeIterator tmp(*this);
				operator++();
				return (tmp);
			}
			ConstDequeIterator operator--(int)
			{
				ConstDequeIterator tmp(*this);
				operator--();
				return (tmp);
			}
			bool operator==(const ConstDequeIterator &other) const
			{
				return (_ptr == other._ptr);
			}
			bool operator!=(const ConstDequeIterator &other) const
			{
				return (_ptr != other._ptr);
			}
			bool operator>(const ConstDequeIterator &other) const
			{
				return (_ptr > other._ptr);
			}
			bool operator>=(const ConstDequeIterator &other) const
			{
				return (_ptr >= other._ptr);
			}
			bool operator<(const ConstDequeIterator &other) const
			{
				return (_ptr < other._ptr);
			}
			bool operator<=(const ConstDequeIterator &other) const
			{
				return (_ptr <= other._ptr);
			}
			const value_type &operator*(void)
			{
				return (_ptr->data);
			}
			const value_type *operator->(void)
			{
				return (_ptr->data);
			}
			ConstDequeIterator operator+(int n) const
			{
				ConstDequeIterator tmp(*this);
				tmp += n;
				return (tmp);
			}
			ConstDequeIterator operator-(int n) const
			{
				ConstDequeIterator tmp(*this);
				tmp -= n;
				return (tmp);
			}
			ConstDequeIterator &operator+=(int n)
			{
				while (n < 0)
				{
					operator--();
					n++;
				}
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			ConstDequeIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				while (n < 0)
				{
					operator++();
					n++;
				}
				return (*this);
			}
	};
	template <class T>
	class ReverseDequeIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef Node<T>* pointer;
		protected:
			pointer _ptr;
		public:
			ReverseDequeIterator(void)
			{}
			ReverseDequeIterator(const ReverseDequeIterator &other)
			{
				*this = other;
			}
			ReverseDequeIterator(pointer ptr)
			{
				this->_ptr = ptr;
			}
			~ReverseDequeIterator(void)
			{}
			ReverseDequeIterator &operator++(void)
			{
				if (_ptr->__ptr - _ptr->_data > 0)
					_ptr->__ptr -= 1;
				else
					_ptr = _ptr->prev;
				return (*this);
			}
			ReverseDequeIterator &operator--(void)
			{
				if (_ptr->__ptr - _ptr->data < 32)
					_ptr->__ptr += 1;
				else
					_ptr = _ptr->next;
				return (*this);
			}
			ReverseDequeIterator operator++(int)
			{
				ReverseDequeIterator tmp(*this);
				operator++();
				return (tmp);
			}
			ReverseDequeIterator operator--(int)
			{
				ReverseDequeIterator tmp(*this);
				operator--();
				return (tmp);
			}
			bool operator==(const ReverseDequeIterator &other) const
			{
				return (_ptr == other._ptr);
			}
			bool operator!=(const ReverseDequeIterator &other) const
			{
				return (_ptr != other._ptr);
			}
			bool operator>(const ReverseDequeIterator &other) const
			{
				return (_ptr > other._ptr);
			}
			bool operator>=(const ReverseDequeIterator &other) const
			{
				return (_ptr >= other._ptr);
			}
			bool operator<(const ReverseDequeIterator &other) const
			{
				return (_ptr < other._ptr);
			}
			bool operator<=(const ReverseDequeIterator &other) const
			{
				return (_ptr <= other._ptr);
			}
			value_type &operator*(void)
			{
				return (_ptr->data);
			}
			value_type *operator->(void)
			{
				return (_ptr->data);
			}
			ReverseDequeIterator operator+(int n) const
			{
				ReverseDequeIterator tmp(*this);
				tmp += n;
				return (tmp);
			}
			ReverseDequeIterator operator-(int n) const
			{
				ReverseDequeIterator tmp(*this);
				tmp -= n;
				return (tmp);
			}
			ReverseDequeIterator &operator+=(int n)
			{
				while (n < 0)
				{
					operator--();
					n++;
				}
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			ReverseDequeIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				while (n < 0)
				{
					operator++();
					n++;
				}
				return (*this);
			}
	};
	template <class T>
	class ConstReverseDequeIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef Node<T>* pointer;
		protected:
			pointer _ptr;
		public:
			ConstReverseDequeIterator(void)
			{}
			ConstReverseDequeIterator(const ConstReverseDequeIterator &other)
			{
				*this = other;
			}
			ConstReverseDequeIterator(pointer ptr)
			{
				this->_ptr = ptr;
			}
			~ConstReverseDequeIterator(void)
			{}
			ConstReverseDequeIterator &operator++(void)
			{
				if (_ptr->__ptr - _ptr->_data > 0)
					_ptr->__ptr -= 1;
				else
					_ptr = _ptr->prev;
				return (*this);
			}
			ConstReverseDequeIterator &operator--(void)
			{
				if (_ptr->__ptr - _ptr->data < 32)
					_ptr->__ptr += 1;
				else
					_ptr = _ptr->next;
				return (*this);
			}
			ConstReverseDequeIterator operator++(int)
			{

				ConstReverseDequeIterator tmp(*this);
				operator++();
				return (tmp);
			}
			ConstReverseDequeIterator operator--(int)
			{
				ConstReverseDequeIterator tmp(*this);
				operator--();
				return (tmp);
			}
			bool operator==(const ConstReverseDequeIterator &other) const
			{
				return (_ptr == other._ptr);
			}
			bool operator!=(const ConstReverseDequeIterator &other) const
			{
				return (_ptr != other._ptr);
			}
			bool operator>(const ConstReverseDequeIterator &other) const
			{
				return (_ptr > other._ptr);
			}
			bool operator>=(const ConstReverseDequeIterator &other) const
			{
				return (_ptr >= other._ptr);
			}
			bool operator<(const ConstReverseDequeIterator &other) const
			{
				return (_ptr < other._ptr);
			}
			bool operator<=(const ConstReverseDequeIterator &other) const
			{
				return (_ptr <= other._ptr);
			}
			value_type &operator*(void)
			{
				return (_ptr->data);
			}
			value_type *operator->(void)
			{
				return (_ptr->data);
			}
			ConstReverseDequeIterator operator+(int n) const
			{
				ConstReverseDequeIterator tmp(*this);
				tmp += n;
				return (tmp);
			}
			ConstReverseDequeIterator operator-(int n) const
			{
				ConstReverseDequeIterator tmp(*this);
				tmp -= n;
				return (tmp);
			}
			ConstReverseDequeIterator &operator+=(int n)
			{
				while (n < 0)
				{
					operator--();
					n++;
				}
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			}
			ConstReverseDequeIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				while (n < 0)
				{
					operator++();
					n++;
				}
				return (*this);
			}
	};
}

#endif
