#include "filesystem.hpp"

#include "../log/logger.hpp"

namespace fat
{
	Filesystem::Filesystem(std::ifstream& dump, const size_t start_sector) :
		properties{dump, start_sector},
		root{dump, properties}
	{}
}
