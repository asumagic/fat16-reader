#ifndef BOOTSECTOR_HPP
#define BOOTSECTOR_HPP

#include <cstdint>
#include <fstream>

namespace fat
{
	struct BootSector
	{
		BootSector(std::ifstream& dump, const size_t start_sector);

		struct
		{
			uint8_t jump[3];
			int8_t oem_code[8];
			uint16_t sector_size; // likely 512
			uint8_t cluster_size; // in sectors
			uint16_t reserved; // sectors
			uint8_t fat_count; // FAT count
			uint16_t root_directory_size; // amount of entries in the root directory
			uint16_t sectors_short; // zero if sectors_long is used
			uint8_t media; // defines the media type
			uint16_t fat_size; // FAT size in sectors
			uint16_t track_size; // in sectors
			uint16_t head_count;
			uint32_t hidden_sectors;
			uint32_t sectors_long;

			uint8_t drive_number;
			uint8_t current_head;
			uint8_t boot_sector_sign;
			uint32_t volume_id;
			char label[11];
			char fs[8];
			char boot_code[448];
			uint16_t boot_code_sign;
		} __attribute__((packed)) data;

		std::string oem() const;
		std::string label() const;
		unsigned long sector_count() const;
	};
}

std::ostream& operator<<(std::ostream& stream, const fat::BootSector& part);

#endif // BOOTSECTOR_HPP
