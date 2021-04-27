/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:50:37 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/27 17:15:33 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <limits>
# include <memory>
# include "VectorIterator.hpp"
# include "Utils.hpp"

namespace ft
{

	template <typename T, typename Alloc = std::allocator<T> >
	class Vector
	{
		public:
			typedef T 						val_type;
			typedef Alloc					Alloc_type;
			typedef T&						val_ref;
			typedef const T&				const_val_ref;
			typedef T*						val_ptr;
			typedef	const T*				const_val_ptr;
			typedef	ft::VectorIterator<T>	iterator;
			typedef	ft::ConstVectorIterator<T>	const_iterator;
			typedef	ft::ReverseVectorIterator<T>	reverse_iterator;
			typedef	ft::ConstReverseVectorIterator<T>	const_reverse_iterator;
			typedef	unsigned long	size_type;

		private:
			size_type	vec_len;
			size_type	vec_size;
			val_ptr		vec;
			Alloc_type	alloc;

		public:
			explicit	Vector(const Alloc_type& allocator= Alloc_type()) :
				vec_len(0), vec_size(0), vec(0), alloc(allocator)
				{
					vec = alloc.allocate(0);
				}
			template <class InputIterator>
			Vector(InputIterator start, InputIterator end, const Alloc_type& allocator= Alloc_type()) :
				vec_len(0), vec_size(0), vec(0), alloc(allocator)
				{
					vec = alloc.allocate(0);
					assign(start, end);
				}
			Vector(size_type n, const_val_ref val = val_type(), const Alloc_type& allocator = Alloc_type()) :
				vec_len(0), vec_size(0), vec(0), alloc(allocator)
				{
					vec = alloc.allocate(0);
					assign(n, val);
				}
			Vector(const Vector& src) :
				vec_len(0), vec_size(0), vec(0), alloc(src.alloc)
				{
					*this = src;
				}
			Vector&		operator=(const Vector& src)
			{
				if (vec != 0)
					alloc.deallocate(vec, vec_size);
				alloc = src.alloc;
				vec_size = 0;
				vec_len = 0;
				vec = alloc.allocate(0);
				assign(src.begin(), src.end());
				return *this;
			}
			val_ref		operator[](size_type n)
			{
				return vec[n];
			}
			const_val_ref	operator[](size_type n) const
			{
				return vec[n];
			}
			iterator begin(void)
			{
				return (iterator(vec));
			}
			const_iterator begin(void) const
			{
				return (const_iterator(vec));
			}
			iterator end(void)
			{
				return (iterator(vec + vec_len));
			}
			const_iterator end(void) const
			{
				return (const_iterator(vec + vec_len));
			}
			reverse_iterator	rbegin(void)
			{
				return (reverse_iterator(vec + vec_len - 1));
			}
			const_reverse_iterator	rbegin(void) const
			{
				return (const_reverse_iterator(vec + vec_len - 1));
			}
			reverse_iterator	rend(void)
			{
				return (reverse_iterator(vec - 1));
			}
			const_reverse_iterator	rend(void) const
			{
				return (const_reverse_iterator(vec - 1));
			}
			void	reserve(size_type n)
			{
				if (n > vec_size)
				{
					size_type i = 0;
					val_ptr tmp;
					tmp = alloc.allocate(n);
					vec_size = n;
					while (i < vec_len)
					{
						tmp[i] = vec[i];
						i++;
					}
					alloc.deallocate(vec, vec_size);
					vec = tmp;
				}
			}
			void	push_back(const val_type& val)
			{
				if (vec_len + 1 > vec_size)
					reserve((vec_size == 0) ? 1 : vec_size * 2);
				vec[vec_len] = val;
				vec_len++;
			}
			size_type	size(void) const
			{
				return vec_len;
			}
			size_type	capacity(void) const
			{
				return vec_size;
			}
			bool empty(void) const
			{
				return (vec_len == 0);
			}
			iterator	insert(iterator pos, const val_type& val)
			{
				size_type	i = 0;
				iterator	it = begin();
				while (it + i != pos && i < vec_len)
					i++;
				if (vec_size < vec_len + 1)
					reserve (vec_size * 2);
				size_type j = vec_size - 1;
				while (j > i)
				{
					vec[j] = vec[j - 1];
					j--;
				}
				vec[i] = val;
				vec_len++;
				return (iterator(&vec[i]));
			}
			void	insert(iterator pos, size_type n, const val_type& val)
			{
				while (n--)
					pos = insert(pos, val);
			}
			template <class InputIterator>
			void	insert(iterator pos, InputIterator start, InputIterator end)
			{
				while (start != end)
				{
					pos = insert(pos, *start) + 1;
					start++;
				}
			}
			size_type	max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(val_type));
			}
			val_ref		at(size_type n)
			{
				if (n >= vec_len || n < 0)
					throw std::length_error("index out of bounds");
				return vec[n];
			}
			const_val_ref	at(size_type n) const
			{
				if (n >= vec_len || n < 0)
					throw std::length_error("index out of bounds");
				return vec[n];
			}
			iterator	erase(iterator pos)
			{
				iterator it = pos;
				while (it + 1 != end())
				{
					*it = *(it + 1);
					it++;
				}
				vec_len--;
				return (iterator(pos));
			}
			iterator	erase(iterator start, iterator end)
			{
				while (start != end)
				{
					erase(start);
					end--;
				}
				return (iterator(start));
			}
			void		clear(void)
			{
				erase(begin(), end());
			}
			template <class InputIterator>
			void	assign(InputIterator start, InputIterator end)
			{
				clear()
				while (start != end)
				{
					push_back(*start);
					start++;
				}
			}
			void	assign(size_type n, const val_type& val)
			{
				clear();
				while (n)
				{
					push_back(val);
					n--;
				}
			}
			val_ref		front(void)
			{
				return vec[0];
			}
			const_val_ref	front(void) const
			{
				return vec[0];
			}
			val_ref		back(void)
			{
				return vec[vec_len - 1];
			}
			const_val_ref		back(void) const
			{
				return vec[vec_len - 1];
			}
			void	pop_back(void)
			{
				if (vec_len != 0)
					vec_len--;
			}
			void	resize(size_type n, val_type val= val_type())
			{
				while (n < vec_len)
					pop_back();
				while (n > vec_len)
					push_back(val);
			}
			void	swap(Vector& rgt)
			{
				ft::swap(vec, rgt.vec);
				ft::swap(vec_size, rgt.vec_size);
				ft::swap(vec_len, rgt.vec_len);
			}
	};
	template <class T, class Alloc>
	void	swap(Vector<T, Alloc>& a, Vector<T, Alloc>& b)
	{
		a.swap(b);
	}
	template <class T, class Alloc>
	bool	operator==(const Vector<T, Alloc>& a, const Vector<T, Alloc>& b)
	{
		if (a.size() != b.size())
			return false;
		unsigned long i = -1;
		while (++i < a.size())
		{
			if (a[i] != b[i])
				return false;
		}
		return true;
	}
	template <class T, class Alloc>
	bool	operator!=(const Vector<T, Alloc>& a, const Vector<T, Alloc>& b)
	{
		return (!(a == b));
	}
	template <class T, class Alloc>
	bool	operator<(const Vector<T, Alloc>& a, const Vector<T, Alloc>& b)
	{
		size_t	i = 0;
		size_t	j = 0;

		if (a.size() > b.size())
			j = b.size() - 1;
		else
			j = a.size() - 1;
		while (i < j)
		{
			if (a.at(i) != b.at(i))
				return (a.at(i) < b.at(i));
			i++;
		}
		return (a.at(i) < b.at(i));
	}
	template <class T, class Alloc>
	bool	operator<=(const Vector<T, Alloc>& a, const Vector<T, Alloc>& b)
	{
		return (a == b || a < b);
	}
	template <class T, class Alloc>
	bool	operator>(const Vector<T, Alloc>& a, const Vector<T, Alloc>& b)
	{
		return (!(a == b) && !(a < b));
	}
	template <class T, class Alloc>
	bool	operator>=(const Vector<T, Alloc>& a, const Vector<T, Alloc>& b)
	{
		return (!(a < b));
	}
};

#endif
