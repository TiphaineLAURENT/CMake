//
// EPITECH PROJECT, 2018
// Util
// File description:
// Directory
//

#ifndef DIRECTORY_HPP_
# define DIRECTORY_HPP_

# include <experimental/filesystem>
# include <string>
# include <iostream>
# include <vector>

namespace fs = std::experimental::filesystem;

namespace MadeM
{

class	Directory
{
public:
	Directory(const std::string &dirname = ".");
	Directory(const Directory &);
	~Directory() = default;
	Directory &operator=(const Directory &);

public:
	std::vector<fs::directory_entry>::iterator begin() noexcept;
	std::vector<fs::directory_entry>::iterator end() noexcept;
	std::vector<fs::directory_entry>::const_iterator begin() const noexcept;
	std::vector<fs::directory_entry>::const_iterator end() const noexcept;

	const std::string	&Dirname() const;
	int			Size(const std::string &type="all") const;
	void			Refresh();
	const std::vector<fs::directory_entry> &Entries() const;

private:
	std::string		_dirname;
	fs::directory_iterator	_dir;
	int			_allEntries;
	int			_regularEntries;
	int			_dirEntries;
	int			_blockEntries;
	int			_characterEntries;
	int			_fifoEntries;
	int			_socketEntries;
	int			_symlinkEntries;
	std::vector<fs::directory_entry> _entries;
};

std::ostream		&operator<<(std::ostream&, const Directory&);

}

#endif /* !DIRECTORY_HPP_ */
