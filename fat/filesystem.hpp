#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include <fstream>
#include "bootsector.hpp"

struct FATPartition
{
	FATPartition(std::ifstream& dump, const size_t start_sector);

	FATBootSector properties;
};

#endif // FILESYSTEM_HPP
