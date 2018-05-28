//
// EPITECH PROJECT, 2018
// Util
// File description:
// File
//

#ifndef FILE_HPP_
# define FILE_HPP_

# include <string>
# include <iostream>
# include <vector>
# include <fstream>

namespace MadeM
{

class	File
{
public:
	File(const std::string &filename = "file.txt",
	     std::ios_base::openmode mode = std::fstream::app | std::fstream::out | std::fstream::in);
	File(const File &);
	~File();
	File &operator=(const File &);

public:
	std::vector<std::string>::iterator begin() noexcept;
	std::vector<std::string>::iterator end() noexcept;
	std::vector<std::string>::const_iterator begin() const noexcept;
	std::vector<std::string>::const_iterator end() const noexcept;

	std::vector<std::string> &ReadFile();
	void operator<<(const std::string&);

	const std::string &Filename() const noexcept;

private:
	std::string	_filename;
	std::fstream	_file;
	std::vector<std::string> _lines;
};

std::ostream		&operator<<(std::ostream&, const File&);

}

#endif /* !FILE_HPP_ */
