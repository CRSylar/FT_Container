/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:48:12 by cromalde          #+#    #+#             */
/*   Updated: 2021/05/06 14:55:04 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "containers/DequeIterator.hpp"
#include <iostream>

int main(void)
{
	ft::DequeIterator<int> it;

	std::cout << it.node()->_data << std::endl << it.node()->__ptr << std::endl << std::endl << std::endl;
	++it;
	std::cout << it.node()->_data << std::endl << it.node()->__ptr << std::endl << std::endl << std::endl;
	--it;
	--it;
	std::cout << it.node()->_data << std::endl << it.node()->__ptr << std::endl << std::endl << std::endl;

	return 0;
}
