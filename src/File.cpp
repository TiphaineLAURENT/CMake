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
		Clear();
	}

	File::File(const File &copy)
		: _filename(copy.Filename(), copy.Mode()), _file(_filename),
		  _lines(copy.Lines()), _mode(copy.Mode())
	{
	}

	File::~File()
	{
		Close();
	}

	File &File::operator=(File &other)
	{
		*this = other.Readlines();
		return *this;
	}

	std::vector<std::string> &File::Readlines()
	{
		std::string line;
		while (getline(_file, line))
			_lines.emplace_back(line);
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

	File &File::operator=(const std::vector<std::string> &lines)
	{
		Close();
		_file.open(_filename, std::fstream::out | std::fstream::trunc);
		for (auto &line : lines)
			_file << line + "\n";
		Close();
		_file.open(_filename, _mode);
		Readlines();
		return *this;
	}

	void File::Open(const std::string &filename, std::ios_base::openmode mode)
	{
		Close();
		_file.open(filename, mode);
		_filename = filename;
		_mode = mode;
		Readlines();
		Clear();
	}

	void File::Close()
	{
		if (IsOpen())
			_file.close();
	}

	bool File::IsOpen()
	{
		return _file.is_open();
	}

}
