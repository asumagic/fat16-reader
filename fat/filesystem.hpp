#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include <fstream>
#include "bootsector.hpp"
#include "directory.hpp"

namespace fat
{
	struct Filesystem
	{
		Filesystem(std::ifstream& dump, const size_t start_sector);

		BootSector properties;
		RootDirectory root;
	};
}

#endif // FILESYSTEM_HPP
