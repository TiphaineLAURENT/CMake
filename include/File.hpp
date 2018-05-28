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
	File &operator=(File &);

public:
	std::vector<std::string>::iterator begin() noexcept;
	std::vector<std::string>::iterator end() noexcept;
	std::vector<std::string>::const_iterator begin() const noexcept;
	std::vector<std::string>::const_iterator end() const noexcept;

	int Get();
	std::string Readline();
	std::vector<std::string> &Readlines();
	const std::string &ReadExtension();
	void Open(const std::string&,
		  std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
	void Close();
	bool IsOpen();
	void Clear();

	void operator<<(const std::string&);
	const std::string &operator[](size_t) const;
	File &operator=(const std::vector<std::string>&);

	const std::string &Filename() const noexcept;
	const std::string &Extension() const noexcept;
	const std::ios_base::openmode &Mode() const noexcept;
	const std::vector<std::string> &Lines() const noexcept;
	const std::fstream &Stream() const noexcept;

private:
	std::string	_filename;
	std::string	_extension;
	std::fstream	_file;
	std::vector<std::string> _lines;
	std::ios_base::openmode _mode;
};

std::ostream		&operator<<(std::ostream&, const File&);

}

#endif /* !FILE_HPP_ */
