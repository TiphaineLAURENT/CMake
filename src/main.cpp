//
// EPITECH PROJECT, 2018
// MadeM
// File description:
// main
//

# include <iostream>

//#include "Make.hpp"
# include "Directory.hpp"
# include "File.hpp"

int		main(int ac, char **av)
{
	if (ac < 2)
		return -1;

	MadeM::File	file(av[1]);
	MadeM::File	makefile("Makefile");

	file = makefile;
	return 0;
}
