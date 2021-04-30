/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:25:48 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/30 17:53:02 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# define RED	0
# define BLACK	1

# include <memory>
# include <limits>
# include "MapIterator.hpp"
namespace ft
{
	template <class Key, class T, class Compare=std::less<Key>, class Alloc=std::allocator<std::pair<const Key, T> > >
	class Map
	{
		public:
			typedef Key										key_type;
			typedef	T										val_type;
			typedef	std::pair<const key_type, val_type>		pair_type;
			typedef	Compare									key_comp;
			typedef Alloc									alloc_type;
			typedef	T&										val_ref;
			typedef	const T&								const_val_ref;
			typedef	T*										val_ptr;
			typedef	const T*								const_val_ptr;
			typedef	unsigned long							size_type;
			typedef	RBNode<key_type, val_type>*				node;
			typedef MapIterator<key_type, val_type>			iterator;
			typedef Const_MapIterator<key_type, val_type>		const_iterator;
			typedef ReverseIterator<key_type, val_type>			reverse_iterator;
			typedef Const_ReverseIterator<key_type, val_type>	const_reverse_iterator;

			class	val_comp
			{
				friend class map;
				protected:
					Compare	comp;
					value_compare(Compare c) : comp(c) {}
				public:
					typedef bool			res_type;
					typedef pair_type		first_arg;
					typedef	pair_type		second_arg;
					bool	operator()(const pair_type& x, const pair_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

		private:
			alloc_type	_allocator;
			key_comp	_comp;
			node		_root;
			node		_leaf;
			node		__end;
			node		__rend;
			size_type	_len;
			void	_print_node(node n)
			{
				if (!n)
					return;
				_print_node(n->sx);
				if (n->father && !n->_nil)
					std::cout << n->_pair.first << " = " << n->_pair.second << std::endl;
				_print_node(n->dx);
			}
			node	_new_node(key_type _key, val_type _value, node _father)
			{
				node _new_ = new RBNode<key_type, val_type>();
				_new_->_pair = std::make_pair(_key, _value);
				_new_->dx = 0;
				_new_->sx = 0;
				_new_->father = _father;
				_new_->color = RED;
				return _new_;
			}
			void	_free_tree(node _n)
			{
				if (_n->dx)
					_free_tree(_n->dx);
				if (_n->sx)
					_free_tree(_n->sx);
				delete _n;
				delete _leaf;
			}
			void	_init_node(node& _n, int _last)
			{
				_n->dx = 0;
				_n->sx = 0;
				_n->color = 0;
				_n->father = 0;
				if (!_last)
				{
					_n->_nil = true;
					_n->__bound = false;
				}
				else
				{
					_n->_nil = false;
					_n->__bound = true;
				}
			}
			void	_init_tree(void)
			{
				_leaf = new RBNode<key_type,val_type>();
				__end = new RBNode<key_type,val_type>();
				__rend = new RBNode<key_type,val_type>();
				_init_node(_leaf, 0);
				_init_node(__end, 1);
				_init_node(__rend, 1);
				_root = 0;
				_len = 0;
			}
			node	_insert_node(pair_type&	_value)
			{

			}


		public:
			explicit Map(const key_comp& comp = key_comp(), const alloc_type alloc=alloc_type()) :
				_allocator(alloc), _comp(comp)
			{
				_init_tree();
			}
			template <class InputIterator>
			Map(InputIterator first, InputIterator last, const key_comp& comp = key_comp(), const alloc_type alloc = alloc_type()) :
				_allocator(alloc), _comp(comp)
				{
					_init_tree();
					insert(first, last);
				}
			Map(const Map<Key, T>& src)
			{
				_init_tree();
				*this = src;
			}
			~Map(void)
			{
				_free_tree(_root);
			}
			Map&	operator=(const Map<Key, T>& rght)
			{
				clear();
				insert(rght.begin(), rght.end());
				return *this;
			}
			iterator	begin(void)
			{
				node tmp = _root;
				while (!tmp->sx->_nil)
				{
					tmp = tmp->sx;
				}
				return (iterator(tmp));
			}
			const_iterator	begin(void) const
			{
				node tmp = _root;
				while (!tmp->sx->_nil)
				{
					tmp = tmp->sx;
				}
			}
			iterator	end(void)
			{
				return (iterator(__end));
			}
			const_iterator	end(void) const
			{
				return (const_iterator(__end));
			}
			reverse_iterator	rbegin(void)
			{
				return (reverse_iterator(__end->father));
			}
			const_reverse_iterator	rbegin(void) const
			{
				return (const_reverse_iterator(__end->father));
			}
			reverse_iterator	rend(void)
			{
				return (reverse_iterator(__rend->father));
			}
			const_reverse_iterator	rend(void) const
			{
				return (const_reverse_iterator(__rend->father));
			}
			bool	empty(void) const
			{
				return (_len == 0);
			}
			size_type	size(void) const
			{
				return _len;
			}
			size_type	max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / (sizeof(ft::RBNode<key_type, val_type>)));
			}
			val_type&	operator[](const key_type& _k)
			{
				iterator tmp = find(_k);
				if (tmp != end())
				{
					return tmp._node->_pair.second;
				}
				return (insert(std::make_pair(_k, val_type())));
			}
			std::pair<iterator, bool>	insert(const pair_type& value)
			{
				iterator tmp;
				tmp = find(value.first);
				if (tmp != end())
					return (std::make_pair(tmp, false));
				_len++;
				tmp = iterator(_insert_node(value));
				return (std::make_pair(tmp, true));
			}
	};
};

#endif
