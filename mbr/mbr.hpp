#ifndef MBR_HPP
#define MBR_HPP

#include <fstream>
#include <cstdint>
#include <array>
#include <map>
#include "../common/chs.hpp"

namespace mbr
{
	struct Partition
	{
		struct
		{
			uint8_t status;

			chs::Address chs_start;
			uint8_t type;
			chs::Address chs_end;

			uint32_t start_sector;
			uint32_t sector_count;
		} __attribute__((packed)) data;

		const std::string& type_name() const;

		static const std::map<uint8_t, std::string> partition_types;
		static const std::string unknown_type;
	};

	struct MBR
	{
		explicit MBR(std::ifstream& dump);

		std::array<Partition, 4> partitions;
	};
}

std::ostream& operator<<(std::ostream& stream, const mbr::Partition& part);

#endif // MBR_HPP
