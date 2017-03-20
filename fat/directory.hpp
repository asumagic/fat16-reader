#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include <vector>
#include <fstream>
#include "entry.hpp"
#include "bootsector.hpp"

namespace fat
{
	struct Directory
	{
		struct
		{

		} __attribute__((packed)) data;
	};

	struct RootDirectory
	{
        uint64_t _offset;
		std::vector<Entry> entries;

	public:
		RootDirectory(std::ifstream& dump, const BootSector& boot);
	};
}

#endif // DIRECTORY_HPP
