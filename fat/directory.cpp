#include "directory.hpp"
#include <iostream>
#include "../log/logger.hpp"

namespace fat
{
	RootDirectory::RootDirectory(std::ifstream& dump, const fat::BootSector& boot) :
		entries(boot.data.root_directory_size)
	{
		dump.seekg(boot.offset() + (boot.data.reserved + boot.data.fat_size * boot.data.fat_count) * boot.data.sector_size);

		for (Entry& e : entries)
		{
			dump.read(reinterpret_cast<char*>(&e.data), sizeof(Entry::data));

			if (e.present())
				fatlog << e << std::endl;
		}
	}
}
