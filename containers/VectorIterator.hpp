/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:04:31 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/27 12:29:26 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

namespace ft
{

	template <class T>
	class VectorIterator
	{
		public:
			typedef T	val_type;
			typedef	T&	val_ref;
			typedef	T*	val_ptr;

		protected:
			val_ptr	ptr;

		public:
			VectorIterator(void)	{};
			VectorIterator(const VectorIterator& src)
			{
				*this = src;
			}
			VectorIterator(val_ptr _ptr) : ptr(_ptr) {}
			~VectorIterator(void)	{}
			VectorIterator&		operator=(const VectorIterator& src)
			{
				ptr = src.ptr;
				return *this;
			}
			VectorIterator&		operator++(void)
			{
				ptr++;
				return *this;
			}
			VectorIterator&		operator--(void)
			{
				ptr--;
				return *this;
			}
			VectorIterator		operator++(int)
			{
				VectorIterator tmp(*this);
				operator++();
				return tmp;
			}
			VectorIterator		operator--(int)
			{
				VectorIterator	tmp(*this);
				operator--();
				return tmp;
			}
			bool	operator==(const VectorIterator& vec) const
			{
				return (ptr == vec.ptr);
			}
			bool	operator!=(const VectorIterator& vec) const
			{
				return (ptr != vec.ptr);
			}
			bool	operator<(const VectorIterator& vec) const
			{
				return (ptr < vec.ptr);
			}
			bool	operator>(const VectorIterator& vec) const
			{
				return (ptr > vec.ptr);
			}
			bool	operator<=(const VectorIterator& vec) const
			{
				return (ptr <= vec.ptr);
			}
			bool	operator>=(const VectorIterator& vec) const
			{
				return (ptr >= vec.ptr);
			}
			val_type&	operator*(void)
			{
				return (*ptr);
			}
			val_type*	operator->(void)
			{
				return ptr;
			}
			VectorIterator	operator+(int n) const
			{
				VectorIterator tmp(*this);
				tmp += n;
				return tmp;
			}
			VectorIterator	operator-(int n) const
			{
				VectorIterator tmp(*this);
				tmp -= n;
				return tmp;
			}
			VectorIterator&	operator+=(int n)
			{
				while (n < 0)
				{
					(*this)--;
					n++;
				}
				while (n > 0)
				{
					(*this)++;
					n--;
				}
				return (*this);
			}
			VectorIterator&	operator-=(int n)
			{
				while (n < 0)
				{
					(*this)++;
					n++;
				}
				while (n > 0)
				{
					(*this)--;
					n--;
				}
				return *this;
			}
			val_type&	operator[](int n) const
			{
				return (*(*this + n));
			}
	};

	template <class T>
	class ReverseVectorIterator
	{
		public:
			typedef T	val_type;
			typedef	T&	val_ref;
			typedef	T*	val_ptr;

		protected:
			val_ptr	ptr;

		public:
			ReverseVectorIterator(void)	{};
			ReverseVectorIterator(const ReverseVectorIterator& src)
			{
				*this = src;
			}
			ReverseVectorIterator(val_ptr _ptr) : ptr(_ptr) {}
			~ReverseVectorIterator(void)	{}
			ReverseVectorIterator&		operator=(const ReverseVectorIterator& src)
			{
				ptr = src.ptr;
				return *this;
			}
			ReverseVectorIterator&		operator++(void)
			{
				ptr--;
				return *this;
			}
			ReverseVectorIterator&		operator--(void)
			{
				ptr++;
				return *this;
			}
			ReverseVectorIterator		operator++(int)
			{
				ReverseVectorIterator tmp(*this);
				operator--();
				return tmp;
			}
			ReverseVectorIterator		operator--(int)
			{
				ReverseVectorIterator	tmp(*this);
				operator++();
				return tmp;
			}
			bool	operator==(const ReverseVectorIterator& vec) const
			{
				return (ptr == vec.ptr);
			}
			bool	operator!=(const ReverseVectorIterator& vec) const
			{
				return (ptr != vec.ptr);
			}
			bool	operator<(const ReverseVectorIterator& vec) const
			{
				return (ptr < vec.ptr);
			}
			bool	operator>(const ReverseVectorIterator& vec) const
			{
				return (ptr > vec.ptr);
			}
			bool	operator<=(const ReverseVectorIterator& vec) const
			{
				return (ptr <= vec.ptr);
			}
			bool	operator>=(const ReverseVectorIterator& vec) const
			{
				return (ptr >= vec.ptr);
			}
			val_type&	operator*(void)
			{
				return (ptr);
			}
			val_type*	operator->(void)
			{
				return ptr;
			}
			ReverseVectorIterator	operator+(int n) const
			{
				ReverseVectorIterator tmp(*this);
				tmp += n;
				return tmp;
			}
			ReverseVectorIterator	operator-(int n) const
			{
				ReverseVectorIterator tmp(*this);
				tmp -= n;
				return tmp;
			}
			ReverseVectorIterator&	operator+=(int n)
			{
				while (n < 0)
				{
					(*this)--;
					n++;
				}
				while (n > 0)
				{
					(*this)++;
					n--;
				}
				return (*this);
			}
			ReverseVectorIterator&	operator-=(int n)
			{
				while (n < 0)
				{
					(*this)++;
					n++;
				}
				while (n > 0)
				{
					(*this)--;
					n--;
				}
				return *this;
			}
			val_type&	operator[](int n) const
			{
				return (*(*this - n));
			}
	};

	template <class T>
	class ConstVectorIterator : public VectorIterator<T>
	{
		public:
			typedef T	val_type;
			typedef T&	val_ref;
			typedef	T*	val_ptr;
			ConstVectorIterator(void) {}
			ConstVectorIterator(val_ptr _ptr)
			{
				this->ptr = _ptr;
			}
			ConstVectorIterator(const ConstVectorIterator& src)
			{
				*this = src;
			}
			~ConstVectorIterator(void)	{}
			ConstVectorIterator&	operator=(const ConstVectorIterator& vec)
			{
				this->ptr = vec.ptr;
				return *this;
			}
			const	val_type&	operator*(void)
			{
				return *this->ptr;
			}
			const	val_type&	operator[](int n) const
			{
				return (*(this + n));
			}
	};

	template <class T>
	class ConstReverseVectorIterator : public ReverseVectorIterator<T>
	{
		public:
			typedef T	val_type;
			typedef T&	val_ref;
			typedef	T*	val_ptr;
			ConstReverseVectorIterator(void) {}
			ConstReverseVectorIterator(val_ptr _ptr)
			{
				this->ptr = _ptr;
			}
			ConstReverseVectorIterator(const ConstReverseVectorIterator& vec)
			{
				*this = vec;
			}
			~ConstReverseVectorIterator(void)	{}
			ConstReverseVectorIterator&	operator=(const ConstReverseVectorIterator& vec)
			{
				this->ptr = vec.ptr;
				return *this;
			}
		const val_type&	operator*(void)
		{
			return (*this->ptr);
		}
		const val_type&	operator[](int n) const
		{
			return (*(*this - n));
		}
	};
};

#endif
