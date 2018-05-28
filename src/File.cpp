//
// EPITECH PROJECT, 2018
// Util
// File description:
// File
//

#include "File.hpp"

namespace MadeM
{

	File::File(const std::string &filename, std::ios_base::openmode mode)
		: _filename(filename), _file(filename, mode),
		  _lines()
	{
		ReadFile();
	}

	File::File(const File &copy)
	{
	}

	File::~File()
	{
		_file.close();
	}

	File &File::operator=(const File &other)
	{
		return *this;
	}

	std::vector<std::string> &File::ReadFile()
	{
		std::string line;
		while (getline(_file, line))
			_lines.emplace_back(line);
		_file.clear();
		return _lines;
	}

	std::vector<std::string>::iterator File::begin() noexcept
	{
		return _lines.begin();
	}

	std::vector<std::string>::iterator File::end() noexcept
	{
		return _lines.end();
	}

	std::vector<std::string>::const_iterator File::begin() const noexcept
	{
		return _lines.begin();
	}

	std::vector<std::string>::const_iterator File::end() const noexcept
	{
		return _lines.end();
	}

	void File::operator<<(const std::string &str)
	{
		_file << str;
	}

	const std::string &File::Filename() const noexcept
	{
		return _filename;
	}

	std::ostream &operator<<(std::ostream &out, const File &file)
	{
		std::string output;
		for (auto &l : file)
			output += l + "\n";
		output.pop_back();
		out << output;
		return out;
	}

}
