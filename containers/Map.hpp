/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:25:48 by cromalde          #+#    #+#             */
/*   Updated: 2021/04/30 11:49:03 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

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



		private:

		public:
	};
};

#endif
