/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 09:40:44 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/26 13:23:10 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include <limits>
# include "ListIterator.hpp"

namespace ft
{
	template <class T, class Alloc=std::allocator<T> >
	class List
	{
		public:
			typedef T						val_type;
			typedef T&						val_ref;
			typedef const T&				const_val_ref;
			typedef T*						val_ptr;
			typedef const T*				const_val_ptr;
			typedef unsigned long			size_type;
			typedef	Node<val_type>*			node;
			typedef	ListIterator<val_type>	iterator;
			typedef	ConstListIterator<val_type>	const_iterator;
			typedef	ReverseListIterator<val_type>	reverse_iterator;
			typedef	ConstReverseListIterator<val_type>	const_reverse_iterator;
			typedef Alloc	alloc_type;

		private:
			node		lst_head;
			node		lst_tail;
			alloc_type	_allocator;
			size_t		len;

			Node<val_type>*	new_node(val_type val, Node<val_type>* prev, Node<val_type>* next)
			{
				node ret = new Node<val_type>();
				ret->data = val;
				ret->prev = prev;
				ret->next = next;
				return ret;
			};
			void	init_list(void)
			{
				lst_head = new_node(val_type(), 0, 0);
				lst_tail = new_node(val_type(), lst_head, 0);
				lst_head->next = lst_tail;
			};
			template <typename N>
			struct same
			{
				bool	operator()(const N& a, const N& b)
				{
					return (a == b);
				}
			};
			template <typename N>
			struct less
			{
				bool	operator()(const N& a, const N& b)
				{
					return (a < b);
				}
			};

		public:
			explicit	List(const alloc_type& alloc =alloc_type()) :
				lst_head(0), lst_tail(0), _allocator(alloc), len(0)
				{
					init_list();
				};
			explicit	List(size_type n, const val_type& val = val_type(), const alloc_type& alloc = alloc_type()) :
				lst_head(0), lst_tail(0), _allocator(alloc), len(0)
				{
					init_list();
					assign(n, val);
				};
			template <class InputIterator>
			List(InputIterator begin, InputIterator end, const alloc_type& alloc = alloc_type()) :
				lst_head(0), lst_tail(0), _allocator(alloc), len(0)
				{
					init_list();
					assign(begin, end);
				};
			List(const List& src) :
			 lst_head(0), lst_tail(0), _allocator(src._allocator), len(0)
			{
				init_list();
				*this = src;
			};
			~List(void)
			{
				clear();
				delete lst_head;
				delete lst_tail;
			};
			List&	operator=(const List& src)
			{
				clear();
				assign(src.begin(), src.end());
				len = src.len;
				return *this;
			}
			iterator	begin(void) const
			{
				return iterator(lst_head->next);
			}
			const_iterator	begin(void) const
			{
				return const_iterator(lst_head->next);
			}
			iterator	end(void) const
			{
				return iterator(lst_tail);
			}
			const_iterator	end(void) const
			{
				return const_iterator(lst_tail);
			}
			reverse_iterator	rbegin(void) const
			{
				return reverse_iterator(lst_tail->prev);
			}
			const_reverse_iterator	rbegin(void) const
			{
				return const_reverse_iterator(lst_tail->prev);
			}
			reverse_iterator	rend(void) const
			{
				return reverse_iterator(lst_head);
			}
			const_reverse_iterator	rend(void) const
			{
				return const_reverse_iterator(lst_head);
			}
			bool	empty(void) const
			{
				if (len == 0)
					return true;
				return false;
			}
			size_type	size(void) const
			{
				return len;
			}
			size_type	max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / (sizeof(Node<T>)));
			}
			val_ref		front(void)
			{
				return lst_head->next->data;
			}
			val_ref		back(void)
			{
				return	lst_tail->prev->data;
			}
			const_val_ref		front(void) const
			{
				return lst_head->next->data;
			}
			const_val_ref		back(void) const
			{
				return	lst_tail->prev->data;
			}
			template <class InputIterator>
			void	assign(InputIterator begin, InputIterator end)
			{
				clear();
				while (begin != end)
				{
					push_back(*begin);
					begin++;
				}
			}
			void	assign(size_type n, const val_type& val)
			{
				clear();
				while (n--)
					push_back(value);
			}
			void	push_front(const val_type& val)
			{
				node tmp = new_node(val, lst_head, lst_head->next);
				lst_head->next->prev = tmp;
				lst_head->next = tmp;
				len++;
			}
			void	push_back(const val_type& val)
			{
				node tmp = new_node(val, lst_tail->prev, lst_tail);
				lst_tail->prev->next = tmp;
				lst_tail->prev = tmp;
				len++;
			}
			void	pop_front(void)
			{
				node tmp = lst_head->next->next;
				delete lst_head->next;
				lst_head->next = tmp;
				tmp->prev = lst_head;
				len--;
			}
			void	pop_back(void)
			{
				node tmp = lst_tail->prev->prev;
				delete lst_tail->prev;
				tmp->next = lst_tail;
				lst_tail->prev = tmp;
				len--;
			}
			iterator	insert(iterator pos, const val_type& val)
			{
				if (pos == begin())
				{
					push_front(val);
					return begin();
				}
				if (pos == end())
				{
					push_back(val);
					return end();
				}
				node _next = pos.node();
				node _prev = prev->prev;
				node tmp = new_node(val, _prev, _next);
				_prev->next = tmp;
				_next->prev = tmp;
				len++;
				return iterator(tmp);
			}
	};
}
#endif
