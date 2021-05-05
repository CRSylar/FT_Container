/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:49:06 by cromalde          #+#    #+#             */
/*   Updated: 2021/05/05 15:10:58 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETITERATOR_HPP
# define SETITERATOR_HPP

# include "Utils.hpp"

namespace ft
{
	template <class T>
	class SetIterator
	{
		public:
			typedef T				val_type;
			typedef T&				val_ref;
			typedef RBSet<T>*		node_T;

		protected:
			node_T	_node;

			node_T	_successor(node_T _ptr)
			{
				node_T tmp;
				if (_ptr->dx->_bound)
					return _ptr->dx;
				if (_ptr->dx->_nil)
				{
					tmp = _ptr;
					while (tmp->father && tmp == tmp->father->dx)
						tmp = tmp->father;
					tmp = tmp->father;
				}
				else
				{
					tmp =  _ptr->dx;
					while (!tmp->sx->_nil)
						tmp = tmp->sx;
				}
				return tmp;
			}

			node_T	_predecessor(node_T _ptr)
			{
				node_T tmp;
				if (_ptr->sx->_bound)
					return _ptr->sx;
				if (_ptr->sx->_nil)
				{
					tmp = _ptr;
					while (tmp->father && tmp == tmp->father->sx)
						tmp = tmp->father;
					tmp = tmp->father;
				}
				else
				{
					tmp = _ptr->sx;
					while (!tmp->dx->_nil)
						tmp = tmp->dx;
				}
				return tmp;
			}

		public:
			SetIterator(void) : _node(0) {}
			SetIterator(const node_T _ptr) : _node(_ptr)	{}
			SetIterator(const SetIterator& src)
			{
				*this = src;
			}
			virtual ~SetIterator() {}
			SetIterator& operator=(const SetIterator& src)
			{
				this->_node = src.node();
				return *this;
			}
			node_T	node(void) const
			{
				return this->_node;
			}
			val_type&	operator*(void)
			{
				return const_cast<val_type&>(this->_node->_pair);
			}
			val_type*	operator->(void)
			{
				return &(this->_node->_pair);
			}
			bool	operator==(const SetIterator<T>& rght)
			{
				return this->_node = rght._node;
			}
			bool	operator!=(const SetIterator<T>& rght)
			{
				return (!(this->_node == rght._node));
			}
			bool	operator<(const SetIterator<T>& rght)
			{
				return this->_node < rght._node;
			}
			bool	operator>(const SetIterator<T>& rght)
			{
				return this->_node > rght._node;
			}
			bool	operator<=(const SetIterator<T>& rght)
			{
				return (!(this->_node > rght._node));
			}
			bool	operator>=(const SetIterator<T>& rght)
			{
				return (!(this->_node < rght._node));
			}
			SetIterator&	operator++(void)
			{
				this->_node = _successor(this->_node);
				return *this;
			}
			SetIterator&	operator--(void)
			{
				this->_node = _predecessor(this->_node);
				return *this;
			}
			SetIterator		operator++(int)
			{
				SetIterator tmp(*this);
				this->_node = _successor(this->_node);
				return tmp;
			}
			SetIterator		operator--(int)
			{
				SetIterator	tmp(*this);
				this->_node = _predecessor(this->_node);
				return tmp;
			}
	};

	template <class T>
	class Const_SetIterator
	{
		public:
			typedef T				val_type;
			typedef T&				val_ref;
			typedef RBSet<T>*		node_T;

		protected:
			node_T	_node;

			node_T	_successor(node_T _ptr)
			{
				node_T tmp;
				if (_ptr->dx->_bound)
					return _ptr->dx;
				if (_ptr->dx->_nil)
				{
					tmp = _ptr;
					while (tmp->father && tmp == tmp->father->dx)
						tmp = tmp->father;
					tmp = tmp->father;
				}
				else
				{
					tmp =  _ptr->dx;
					while (!tmp->sx->_nil)
						tmp = tmp->sx;
				}
				return tmp;
			}

			node_T	_predecessor(node_T _ptr)
			{
				node_T tmp;
				if (_ptr->sx->_bound)
					return _ptr->sx;
				if (_ptr->sx->_nil)
				{
					tmp = _ptr;
					while (tmp->father && tmp == tmp->father->sx)
						tmp = tmp->father;
					tmp = tmp->father;
				}
				else
				{
					tmp = _ptr->sx;
					while (!tmp->dx->_nil)
						tmp = tmp->dx;
				}
				return tmp;
			}

		public:
			Const_SetIterator(void) : _node(0) {}
			Const_SetIterator(const node_T _ptr) : _node(_ptr)	{}
			Const_SetIterator(const Const_SetIterator& src)
			{
				*this = src;
			}
			virtual ~Const_SetIterator() {}
			Const_SetIterator& operator=(const Const_SetIterator& src)
			{
				this->_node = src.node();
				return *this;
			}
			node_T	node(void) const
			{
				return this->_node;
			}
			val_type&	operator*(void) const
			{
				return this->_node->_pair;
			}
			val_type*	operator->(void) const
			{
				return &(this->_node->_pair);
			}
			bool	operator==(const Const_SetIterator<T>& rght)
			{
				return this->_node = rght._node;
			}
			bool	operator!=(const Const_SetIterator<T>& rght)
			{
				return (!(this->_node == rght._node));
			}
			bool	operator<(const Const_SetIterator<T>& rght)
			{
				return this->_node < rght._node;
			}
			bool	operator>(const Const_SetIterator<T>& rght)
			{
				return this->_node > rght._node;
			}
			bool	operator<=(const Const_SetIterator<T>& rght)
			{
				return (!(this->_node > rght._node));
			}
			bool	operator>=(const Const_SetIterator<T>& rght)
			{
				return (!(this->_node < rght._node));
			}
			Const_SetIterator&	operator++(void)
			{
				this->_node = _successor(this->_node);
				return *this;
			}
			Const_SetIterator&	operator--(void)
			{
				this->_node = _predecessor(this->_node);
				return *this;
			}
			Const_SetIterator		operator++(int)
			{
				Const_SetIterator tmp(*this);
				this->_node = _successor(this->_node);
				return tmp;
			}
			Const_SetIterator		operator--(int)
			{
				Const_SetIterator	tmp(*this);
				this->_node = _predecessor(this->_node);
				return tmp;
			}
	};

	template <class T>
	class ReverseSetIterator
	{
		public:
			typedef T	val_type;
			typedef T&	val_ref;
			typedef RBSet<T>*		node_T;

		protected:
			node_T	_node;

			node_T	_successor(node_T _ptr)
			{
				node_T tmp;
				if (_ptr->dx->_bound)
					return _ptr->dx;
				if (_ptr->dx->_nil)
				{
					tmp = _ptr;
					while (tmp->father && tmp == tmp->father->dx)
						tmp = tmp->father;
					tmp = tmp->father;
				}
				else
				{
					tmp =  _ptr->dx;
					while (!tmp->sx->_nil)
						tmp = tmp->sx;
				}
				return tmp;
			}

			node_T	_predecessor(node_T _ptr)
			{
				node_T tmp;
				if (_ptr->sx->_bound)
					return _ptr->sx;
				if (_ptr->sx->_nil)
				{
					tmp = _ptr;
					while (tmp->father && tmp == tmp->father->sx)
						tmp = tmp->father;
					tmp = tmp->father;
				}
				else
				{
					tmp = _ptr->sx;
					while (!tmp->dx->_nil)
						tmp = tmp->dx;
				}
				return tmp;
			}

		public:
			ReverseSetIterator(void) : _node(0) {}
			ReverseSetIterator(const node_T _ptr) : _node(_ptr)	{}
			ReverseSetIterator(const ReverseSetIterator& src)
			{
				*this = src;
			}
			virtual ~ReverseSetIterator() {}
			ReverseSetIterator& operator=(const ReverseSetIterator& src)
			{
				this->_node = src.node();
				return *this;
			}
			node_T	node(void) const
			{
				return this->_node;
			}
			val_type&	operator*(void)
			{
				return this->_node->_pair;
			}
			val_type*	operator->(void)
			{
				return &(this->_node->_pair);
			}
			bool	operator==(const ReverseSetIterator<T>& rght)
			{
				return this->_node = rght._node;
			}
			bool	operator!=(const ReverseSetIterator<T>& rght)
			{
				return (!(this->_node == rght._node));
			}
			bool	operator<(const ReverseSetIterator<T>& rght)
			{
				return this->_node < rght._node;
			}
			bool	operator>(const ReverseSetIterator<T>& rght)
			{
				return this->_node > rght._node;
			}
			bool	operator<=(const ReverseSetIterator<T>& rght)
			{
				return (!(this->_node > rght._node));
			}
			bool	operator>=(const ReverseSetIterator<T>& rght)
			{
				return (!(this->_node < rght._node));
			}
			ReverseSetIterator&	operator++(void)
			{
				this->_node = _predecessor(this->_node);
				return *this;
			}
			ReverseSetIterator&	operator--(void)
			{
				this->_node = _successor(this->_node);
				return *this;
			}
			ReverseSetIterator		operator++(int)
			{
				ReverseSetIterator tmp(*this);
				this->_node = _predecessor(this->_node);
				return tmp;
			}
			ReverseSetIterator		operator--(int)
			{
				ReverseSetIterator	tmp(*this);
				this->_node = _successor(this->_node);
				return tmp;
			}
	};

	template <class T>
	class Const_ReverseSetIterator
	{
		public:
			typedef T				val_type;
			typedef T&				val_ref;
			typedef RBSet<T>*		node_T;

		protected:
			node_T	_node;

			node_T	_successor(node_T _ptr)
			{
				node_T tmp;
				if (_ptr->dx->_bound)
					return _ptr->dx;
				if (_ptr->dx->_nil)
				{
					tmp = _ptr;
					while (tmp->father && tmp == tmp->father->dx)
						tmp = tmp->father;
					tmp = tmp->father;
				}
				else
				{
					tmp =  _ptr->dx;
					while (!tmp->sx->_nil)
						tmp = tmp->sx;
				}
				return tmp;
			}

			node_T	_predecessor(node_T _ptr)
			{
				node_T tmp;
				if (_ptr->sx->_bound)
					return _ptr->sx;
				if (_ptr->sx->_nil)
				{
					tmp = _ptr;
					while (tmp->father && tmp == tmp->father->sx)
						tmp = tmp->father;
					tmp = tmp->father;
				}
				else
				{
					tmp = _ptr->sx;
					while (!tmp->dx->_nil)
						tmp = tmp->dx;
				}
				return tmp;
			}

		public:
			Const_ReverseSetIterator(void) : _node(0) {}
			Const_ReverseSetIterator(const node_T _ptr) : _node(_ptr)	{}
			Const_ReverseSetIterator(const Const_ReverseSetIterator& src)
			{
				*this = src;
			}
			virtual ~Const_ReverseSetIterator() {}
			Const_ReverseSetIterator& operator=(const Const_ReverseSetIterator& src)
			{
				this->_node = src.node();
				return *this;
			}
			node_T	node(void) const
			{
				return this->_node;
			}
			val_type&	operator*(void) const
			{
				return this->_node->_pair;
			}
			val_type*	operator->(void) const
			{
				return &(this->_node->_pair);
			}
			bool	operator==(const Const_ReverseSetIterator<T>& rght)
			{
				return this->_node = rght._node;
			}
			bool	operator!=(const Const_ReverseSetIterator<T>& rght)
			{
				return (!(this->_node == rght._node));
			}
			bool	operator<(const Const_ReverseSetIterator<T>& rght)
			{
				return this->_node < rght._node;
			}
			bool	operator>(const Const_ReverseSetIterator<T>& rght)
			{
				return this->_node > rght._node;
			}
			bool	operator<=(const Const_ReverseSetIterator<T>& rght)
			{
				return (!(this->_node > rght._node));
			}
			bool	operator>=(const Const_ReverseSetIterator<T>& rght)
			{
				return (!(this->_node < rght._node));
			}
			Const_ReverseSetIterator&	operator++(void)
			{
				this->_node = _predecessor(this->_node);
				return *this;
			}
			Const_ReverseSetIterator&	operator--(void)
			{
				this->_node = _successor(this->_node);
				return *this;
			}
			Const_ReverseSetIterator		operator++(int)
			{
				Const_ReverseSetIterator tmp(*this);
				this->_node = _predecessor(this->_node);
				return tmp;
			}
			Const_ReverseSetIterator		operator--(int)
			{
				Const_ReverseSetIterator	tmp(*this);
				this->_node = _successor(this->_node);
				return tmp;
			}
	};
};

#endif
