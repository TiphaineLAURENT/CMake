//
// EPITECH PROJECT, 2018
// Arcade
// File description:
// Directory
//

#include "Directory.hpp"

namespace MadeM
{

Directory::Directory(const std::string &dirname)
	: _dirname(dirname), _dir(dirname),
	  _allEntries(0), _regularEntries(0), _dirEntries(0),
	  _blockEntries(0), _characterEntries(0), _fifoEntries(0),
	  _socketEntries(0), _symlinkEntries(0),
	  _entries()
{
	Refresh();
}

Directory::Directory(const Directory &copy)
	: _dirname(copy.Dirname()), _dir(copy.Dirname()),
	  _allEntries(copy.Size()),
	  _regularEntries(copy.Size("regular")), _dirEntries(copy.Size("directory")),
	  _blockEntries(copy.Size("block")), _characterEntries(copy.Size("character")),
	  _fifoEntries(copy.Size("fifo")), _socketEntries(copy.Size("socket")),
	  _symlinkEntries(copy.Size("symlink")),
	  _entries(copy.Entries())
{
}

Directory		&Directory::operator=(const Directory &other)
{
	_dirname = other.Dirname();
	_dir = fs::directory_iterator(_dirname);
	_entries = other.Entries();
	_allEntries = other.Size();
	_regularEntries = other.Size("regular");
	_dirEntries = other.Size("directory");
	_blockEntries = other.Size("block");
	_characterEntries = other.Size("character");
	_fifoEntries = other.Size("fifo");
	_socketEntries = other.Size("socket");
	_symlinkEntries = other.Size("symlink");
	return *this;
}

const std::string	&Directory::Dirname() const
{
	return _dirname;
}

int			Directory::Size(const std::string &type) const
{
	if (type == "regular")
		return _regularEntries;
	else if (type == "directory")
		return _dirEntries;
	else if (type == "block")
		return _blockEntries;
	else if (type == "character")
		return _characterEntries;
	else if (type == "fifo")
		return _fifoEntries;
	else if (type == "socket")
		return _socketEntries;
	else if (type == "symlink")
		return _symlinkEntries;
	return _allEntries;
}

void			Directory::Refresh()
{
	_allEntries = 0;
	_dirEntries = 0;
	_regularEntries = 0;

	for (auto &e : _dir) {
		_allEntries += 1;
		if (fs::is_regular_file(e))
			_regularEntries += 1;
		else if (fs::is_directory(e))
			_dirEntries += 1;
		else if (fs::is_block_file(e))
			_blockEntries += 1;
		else if (fs::is_character_file(e))
			_characterEntries += 1;
		else if (fs::is_fifo(e))
			_fifoEntries += 1;
		else if (fs::is_socket(e))
			_socketEntries += 1;
		else if (fs::is_symlink(e))
			_symlinkEntries += 1;
		_entries.emplace_back(e);
	}

	_dir = fs::directory_iterator(_dirname);
}

const std::vector<fs::directory_entry> &Directory::Entries() const
{
	return _entries;
}

std::vector<fs::directory_entry>::iterator Directory::begin()  noexcept
{
	return _entries.begin();
}

std::vector<fs::directory_entry>::iterator Directory::end()  noexcept
{
	return _entries.end();
}

std::vector<fs::directory_entry>::const_iterator Directory::begin() const noexcept
{
	return _entries.begin();
}

std::vector<fs::directory_entry>::const_iterator Directory::end() const noexcept
{
	return _entries.end();
}

std::ostream		&operator<<(std::ostream &out, const Directory &dir)
{
	out << "Total: " << dir.Size() << "\n"
	    << "Regular files: " << dir.Size("regular") << "\n"
	    << "Directories: " << dir.Size("directory") << "\n"
	    << "Block devices: " << dir.Size("block") << "\n"
	    << "Character devices: " << dir.Size("character") << "\n"
	    << "IPC pipes:" << dir.Size("fifo") << "\n"
	    << "IPC sockets: " << dir.Size("socket") << "\n"
	    << "Symbolic links: " << dir.Size("symlink") << "\n";

	for (auto &e : dir.Entries())
		out << "\n" << e;

	return out;
}

}
