#ifndef FILE_HPP
#define FILE_HPP

#include <cstdint>
#include <string>

namespace fat
{
	struct Entry
	{
		struct
		{
			uint8_t filename[8];
			uint8_t extension[3];
			uint8_t attributes;
			uint8_t reserved_data[10];
			uint16_t modify_time;
			uint16_t modify_date;
			uint16_t cluster;
			uint32_t file_size;
		} __attribute__((packed)) data;

		bool present() const;
		bool is_directory() const;
		bool is_file() const;

		uint8_t first_char() const;
		std::string filename() const;
		std::string filename_full() const;
        std::string extension() const;
		std::string directory_name() const;
	};
}

std::ostream& operator<<(std::ostream& stream, const fat::Entry& part);

#endif // FILE_HPP
