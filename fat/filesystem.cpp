#include "filesystem.hpp"

#include "../log/logger.hpp"

namespace fat
{
	Partition::Partition(std::ifstream& dump, const size_t start_sector) :
		properties{dump, start_sector}
	{}
}
