#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include <fstream>
#include "bootsector.hpp"

namespace fat
{
	struct Partition
	{
		Partition(std::ifstream& dump, const size_t start_sector);

		BootSector properties;
	};
}

#endif // FILESYSTEM_HPP
