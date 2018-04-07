//
// EPITECH PROJECT, 2018
// MadeM
// File description:
// main
//

# include <iostream>

//#include "Make.hpp"
# include "Directory.hpp"

int		main(int ac, char **av)
{
	if (ac < 2)
		return -1;
	MadeM::Directory dir(av[1]);

	std::cout << dir << std::endl;

	for (auto &e : dir)
		std::cout << e << std::endl;
	return 0;
}
