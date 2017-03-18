#include "filesystem.hpp"

#include "../log/logger.hpp"

FATPartition::FATPartition(std::ifstream& dump, const size_t start_sector) :
	properties{dump, start_sector}
{}
