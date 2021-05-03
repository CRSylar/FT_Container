/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 08:04:33 by cromalde          #+#    #+#             */
/*   Updated: 2021/05/03 12:37:05 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <iomanip>
# include "./containers/Map.hpp"

int main(void)
{
	ft::Map<int, int> m1;

	m1.insert(std::make_pair(10, 42));
	m1.insert(std::make_pair(13, 21));
	m1.insert(std::make_pair(18, 14));

	m1.insert(std::make_pair(1, 7));
	m1.print();
	return 0;
}
