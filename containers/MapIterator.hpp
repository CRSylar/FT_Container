/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:49:06 by cromalde          #+#    #+#             */
/*   Updated: 2021/05/03 15:46:11 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

# include "Utils.hpp"
# include <utility>

namespace ft
{
	template <class Key, class T>
	class MapIterator
	{
		public:
			typedef std::pair<Key, T>	val_type;
			typedef std::pair<Key, T>&	val_ref;
			typedef RBNode<Key, T>*		node_T;

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
			MapIterator(void) : _node(0) {}
			MapIterator(const node_T _ptr) : _node(_ptr)	{}
			MapIterator(const MapIterator& src)
			{
				*this = src;
			}
			virtual ~MapIterator() {}
			MapIterator& operator=(const MapIterator& src)
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
			bool	operator==(const MapIterator<Key, T>& rght)
			{
				return this->_node = rght._node;
			}
			bool	operator!=(const MapIterator<Key, T>& rght)
			{
				return (!(this->_node == rght._node));
			}
			bool	operator<(const MapIterator<Key, T>& rght)
			{
				return this->_node < rght._node;
			}
			bool	operator>(const MapIterator<Key, T>& rght)
			{
				return this->_node > rght._node;
			}
			bool	operator<=(const MapIterator<Key, T>& rght)
			{
				return (!(this->_node > rght._node));
			}
			bool	operator>=(const MapIterator<Key, T>& rght)
			{
				return (!(this->_node < rght._node));
			}
			MapIterator&	operator++(void)
			{
				this->_node = _successor(this->_node);
				return *this;
			}
			MapIterator&	operator--(void)
			{
				this->_node = _predecessor(this->_node);
				return *this;
			}
			MapIterator		operator++(int)
			{
				MapIterator tmp(*this);
				this->_node = _successor(this->_node);
				return tmp;
			}
			MapIterator		operator--(int)
			{
				MapIterator	tmp(*this);
				this->_node = _predecessor(this->_node);
				return tmp;
			}
	};

	template <class Key, class T>
	class Const_MapIterator : public MapIterator<Key, T>
	{
		public:
			typedef std::pair<Key, T>	val_type;
			typedef std::pair<Key, T>&	val_ref;
			typedef RBNode<Key, T>*		node_T;
			~Const_MapIterator()	{}
			val_type&	operator*(void) const
			{
				return this->_node->_pair;
			}
			val_type*	operator->(void) const
			{
				return &(this->_node->_pair);
			}
	};

	template <class Key, class T>
	class ReverseIterator : public MapIterator<Key, T>
	{
		public:
			typedef std::pair<Key, T>	val_type;
			typedef std::pair<Key, T>&	val_ref;
			typedef RBNode<Key, T>*		node_T;
			~ReverseIterator() {}
			ReverseIterator&	operator++(void)
			{
				this->_node = _predecessor(this->_node);
				return *this;
			}
			ReverseIterator&	operator--(void)
			{
				this->_node = _successor(this->_node);
				return *this;
			}
			ReverseIterator	operator++(int)
			{
				ReverseIterator	tmp;
				this->_node = _predecessor(this->_node);
				return tmp;
			}
			ReverseIterator	operator--(int)
			{
				ReverseIterator	tmp(*this);
				this->_node = _successor(this->_node);
				return tmp;
			}
	};

	template <class Key, class T>
	class Const_ReverseIterator : public MapIterator<Key, T>
	{
		public:
			typedef std::pair<Key, T>	val_type;
			typedef std::pair<Key, T>&	val_ref;
			typedef RBNode<Key, T>*		node_T;
			~Const_ReverseIterator()	{}
			val_type&	operator*(void) const
			{
				return this->_node->_pair;
			}
			val_type*	operator->(void) const
			{
				return &(this->_node->_pair);
			}
			Const_ReverseIterator&	operator++(void)
			{
				this->_node = _predecessor(this->_node);
				return *this;
			}
			Const_ReverseIterator&	operator--(void)
			{
				this->_node = _successor(this->_node);
				return *this;
			}
			Const_ReverseIterator	operator++(int)
			{
				Const_ReverseIterator	tmp;
				this->_node = _predecessor(this->_node);
				return tmp;
			}
			Const_ReverseIterator	operator--(int)
			{
				Const_ReverseIterator	tmp(*this);
				this->_node = _successor(this->_node);
				return tmp;
			}
	};
};

#endif
