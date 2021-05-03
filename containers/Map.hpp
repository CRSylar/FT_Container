/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:25:48 by cromalde          #+#    #+#             */
/*   Updated: 2021/05/03 18:23:55 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# define RED	0
# define BLACK	1

# include <memory>
# include <limits>
# include <utility>
# include <functional>
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
					bool value_compare(Compare c)
					{
						comp(c);
					}
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
			void	_print_node(node n, int widh = 0)
			{
				if (!n)
					return;
				_print_node(n->dx, widh + 4);
				if (n != __end && n != __rend && n != _leaf)
				{
					std::cout << std::setw(widh) << ' ';
					if (n->color == RED)
						std::cout << "\x1B[31m";
					std::cout << n->_pair.first << " = " << n->_pair.second << "\033[0m" << std::endl;
				}
				_print_node(n->sx, widh + 4);
			}
			node	_new_node(key_type _key, val_type _value, node _father)
			{
				node _new_ = new RBNode<key_type, val_type>();
				_new_->_pair = std::make_pair(_key, _value);
				_new_->father = _father;
				_new_->color = RED;
				_new_->_nil = false;
				_new_->_bound = false;
				return _new_;
			}
			void	_free_tree(node _n, bool flag = false)
			{
				if (_n && (_n->dx != __end && _n->dx != _leaf))
					_free_tree(_n->dx, true);
				if (_n && (_n->sx != __rend && _n->sx != _leaf))
					_free_tree(_n->sx, true);
				delete _n;
				if (!flag)
				{
					delete __end;
					delete __rend;
					delete _leaf;
				}
			}
			void	_init_tree(void)
			{
				_leaf = new RBNode<key_type,val_type>();
				__end = new RBNode<key_type,val_type>();
				__rend = new RBNode<key_type,val_type>();
				_leaf->_nil = __end->_nil = __rend->_nil = true;
				__end->_bound = true;
				__rend->_bound = true;
				_leaf->_bound = false;
				_root = 0;
				_len = 0;
			}
			void	_link(node& _root, node& _new_, key_type _key)
			{
				if (_key < _root->_pair.first)
				{
					if (_root->sx == __rend)
					{
						_new_->sx = __rend;
						__rend->father = _new_;
					}
					else
						_new_->sx = _leaf;
					_root->sx = _new_;
					_new_->dx = _leaf;
				}
				else
				{
					if (_root->dx == __end)
					{
						_new_->dx = __end;
						__end->father = _new_;
					}
					else
						_new_->dx = _leaf;
					_root->dx = _new_;
					_new_->sx = _leaf;
				}
				_new_->father = _root;
			}
			void	_balance_insert(node& _t)
			{
				while (true)
				{
					node _p = _t->father;
					node _n = (_p == 0) ? 0 : _p->father;
					node _z = ((_n == 0) ? _leaf : (_n->sx == _p) ? _n->dx : _n->sx);

					if (_p == 0)
					{
						_t->color = BLACK;
						return ;
					}
					else if (_p->color == BLACK)
						return ;
					else if (_z->color == RED)
					{
						_p->color = _z->color = BLACK;
						_n->color = RED;
						_t = _n;
					}
					else
					{
						if (_t == _p->dx && _p == _n->sx)
						{
							_rotateSx(_p);
							_t = _p;
						}
						else if (_t == _p->sx && _p == _n->dx)
						{
							_rotateDx(_p);
							_t = _p;
						}
						else
						{
							if (_t == _p->sx && _p == _n->sx)
								_rotateDx(_n);
							else if (_t == _p->dx && _p == _n->dx)
								_rotateSx(_n);
							_p->color = BLACK;
							_n->color = RED;
							return ;
						}
					}
				}
			}
			void	_rotateSx(node& _x)
			{
				node _y = _x->dx;
				node _p = _x->father;

				_x->dx = _y->sx;
				if (_y->sx != _leaf && _y->sx != __rend && _y->sx != __end)
					_y->sx->father = _x;
				_y->sx = _x;
				_x->father = _y;
				_y->father = _p;
				if (!_p)
				{
					_root = _y;
					return ;
				}
				if (_p->sx == _x)
					_p->sx = _y;
				else
					_p->dx = _y;
			}
			void	_rotateDx(node& _x)
			{
				node	_y = _x->sx;
				node	_p = _x->father;

				_x->sx = _y->dx;
				if (_y->dx != _leaf && _y->dx != __rend && _y->dx != __end)
					_y->dx->father = _x;
				_y->dx = _x;
				_x->father = _y;
				_y->father = _p;
				if (!_p)
				{
					_root = _y;
					return ;
				}
				if (_p->dx == _x)
					_p->dx = _y;
				else
					_p->sx = _y;
			}
			void	balance_delete(node& _t)
			{
				while (_t != _root && _t->color == BLACK)
				{
					node _p = _t->father;
					if (_t == _p->sx)
					{
						node _f = _p->dx;
						node _ns = _f->sx;
						node _nd = _f->dx;
						if (_f->color == RED)
						{
							_p->color = RED;
							_f->color = BLACK;
							_rotateSx(_p);
						}
						else
						{
							if (_ns->color == _nd->color == BLACK)
							{
								_f->color = RED;
								_t = _p;
							}
							else if (_ns->color == RED && _nd->color == BLACK)
							{
								_ns->color = BLACK;
								_f->color = RED;
								_rotateDx(_f);
							}
							else if (_nd->color == RED)
							{
								_f->color = _p->color;
								_p->color = BLACK;
								_nd->color = BLACK;
								_rotateSx(_p);
								_t = _root;
							}
						}
					}
					else
					{
						node _f = _p->sx;
						node _ns = _f->dx;
						node _nd = _f->sx;
						if (_f->color == RED)
						{
							_p->color = RED;
							_f->color = BLACK;
							_rotateDx(_p);
						}
						else
						{
							if (_ns->color == _nd->color == BLACK)
							{
								_f->color = RED;
								_t = _p;
							}
							else if (_ns->color == RED && _nd->color == BLACK)
							{
								_ns->color = BLACK;
								_f->color = RED;
								_rotateSx(_f);
							}
							else if (_nd->color == RED)
							{
								_f->color = _p->color;
								_p->color = BLACK;
								_nd->color = BLACK;
								_rotateDx(_p);
								_t = _root;
							}
						}
					}
				}
			}
		public:

			void	print(void)
			{
				_print_node(_root);
			}

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
				//clear();
				insert(rght.begin(), rght.end());
				return *this;
			}
			iterator	begin(void)
			{
				return (iterator(__rend->father));
			}
			const_iterator	begin(void) const
			{
				return (iterator(__rend->father));
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
				node tmp = _root;
				node tmpfather;

				if (!_root)
				{
					_root = _new_node(value.first, value.second, 0);
					_root->color = BLACK;
					_root->sx = __rend;
					_root->dx = __end;
					__rend->father = _root;
					__end->father = _root;
					_len += 1;
					return std::make_pair(begin(), true);
				}
				while (tmp != __end && tmp != __rend && tmp != _leaf && tmp->_pair.first != value.first)
				{
					tmpfather = tmp;
					if (value.first < tmp->_pair.first)
						tmp = tmp->sx;
					else if (value.first > tmp->_pair.first)
						tmp = tmp->dx;
				}
				if (tmp != __end && tmp != __rend && tmp != _leaf && tmp->_pair.first == value.first)
					return (std::make_pair(iterator(tmp), false));
				_len += 1;
				tmp = _new_node(value.first, value.second, 0);
				_link(tmpfather, tmp, value.first);
				_balance_insert(tmp);
				return (std::make_pair(iterator(tmp), true));
			}
			std::pair<iterator, bool>	insert(iterator first, iterator last)
			{
				std::pair<iterator, bool> _pair;
				while (first != last)
				{
					_pair = insert(*first);
					++first;
				}
				return _pair;
			}
			void	erase(iterator _pos)
			{
				node tmp = _root;
				node tmpfather;

				while (tmp != __end && tmp != __rend && tmp != _leaf && tmp->_pair.first != _pos.node()->_pair.first)
				{
					tmpfather = tmp;
					if (_pos.node()->_pair.first < tmp->_pair.first)
						tmp = tmp->sx;
					else if (_pos.node()->_pair.first > tmp->_pair.first)
						tmp = tmp->dx;
				}
				if (tmp != __end && tmp != __rend && tmp != _leaf && tmp->_pair.first == _pos.node()->_pair.first)
				{
					if (tmp == tmpfather->dx)

					balance_delete(tmp);
					_len -= 1;
				}
			}
	};
};

#endif
