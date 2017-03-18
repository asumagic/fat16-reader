#ifndef MBR_HPP
#define MBR_HPP

#include <fstream>
#include <cstdint>
#include <array>
#include <map>
#include "../common/chs.hpp"

struct MBRPartition
{
	uint8_t status;

	CHSAddress chs_start;
	uint8_t type;
	CHSAddress chs_end;

	uint32_t start_sector;
	uint32_t sector_count;

	const std::string& type_name() const;

	static const std::map<uint8_t, std::string> partition_types;
	static const std::string unknown_type;
};

struct MBR
{
	MBR(std::ifstream& dump);

	std::array<MBRPartition, 4> partitions;
};

std::ostream& operator<<(std::ostream& stream, const MBRPartition& part);

#endif // MBR_HPP
