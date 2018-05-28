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
		  _lines(), _mode(mode)
	{
		Readlines();
	}

	File::File(const File &copy)
		: _filename(copy.Filename(), copy.Mode()), _file(_filename),
		  _lines(copy.Lines()), _mode(copy.Mode())
	{
	}

	File::~File()
	{
		_file.close();
	}

	File &File::operator=(const File &other)
	{
		_filename = other.Filename();
		_file = std::fstream(_filename);
		_lines = other.Lines();
		_mode = other.Mode();
		return *this;
	}

	std::vector<std::string> &File::Readlines()
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

	const std::string &File::operator[](size_t pos) const
	{
		return _lines[pos];
	}

	const std::ios_base::openmode &File::Mode() const noexcept
	{
		return _mode;
	}

	const std::vector<std::string> &File::Lines() const noexcept
	{
		return _lines;
	}

	const std::fstream &File::Stream() const noexcept
	{
		return _file;
	}

	void File::Clear()
	{
		_file.clear();
	}

	int File::Get()
	{
		return _file.get();
	}

	std::string File::Readline()
	{
		std::string line;
		std::getline(_file, line);

		return line;
	}

}
