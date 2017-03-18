#include "mbr.hpp"

#include <iomanip>
#include "../log/logger.hpp"

namespace mbr
{
	const std::map<uint8_t, std::string> Partition::partition_types
	{
		{0x1, "FAT12"},
		{0x4, "FAT16"},
		{0x5, "Étendue"},
		{0x6, "FAT16B"},
		{0x7, "FAT16B"},
		{0x8, "NTFS/exFAT"},
		{0xB, "FAT32)"},
		{0xC, "FAT32"},
		{0xE, "FAT16B"},
		{0xF, "Étendue"},
		// @TODO : Have more partition type matches
	};

	const std::string Partition::unknown_type = "Inconnu";

	const std::string& Partition::type_name() const // @TODO make this less bad
	{
		try
		{
			return partition_types.at(type);
		}
		catch (const std::out_of_range)
		{
			return unknown_type;
		}
	}

	MBR::MBR(std::ifstream& dump)
	{
		mbrlog << trivial << "Analyse de la MBR" << std::endl;

		dump.seekg(0x1FE); // Seek to the MBR signature
		{
			uint16_t signature;
			dump.read(reinterpret_cast<char*>(&signature), 2);

			if (signature != 0xAA55)
			{
				mbrlog << caution << "La signature de la MBR n'a pas été trouvée." << std::endl
					   << caution << "Soit le périphérique n'est pas en MBR, soit celle-ci est corrompue." << std::endl;
			}
		}

		dump.seekg(0x1BE); // Seek to the MBR partition list

		dump.read(reinterpret_cast<char*>(partitions.data()), sizeof(Partition) * 4);

		mbrlog << trivial << "Listage et vérification des partitions" << std::endl;
		for (const Partition& part : partitions)
		{
			if (part.type)
				mbrlog << useful << "Partition détectée : " << std::endl << part << std::endl;
			else
				mbrlog << trivial << "Partition absente" << std::endl;
		}
	}
}

std::ostream& operator<<(std::ostream& stream, const mbr::Partition& part)
{
	stream << "État      : " << static_cast<int>(part.status) << std::endl
		   << "Début CHS : " << part.chs_start << std::endl
		   << "Type      : " << part.type_name() << " (" << std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(part.type) << "h)" << std::dec << std::endl
		   << "Fin CHS   : " << part.chs_end << std::endl
		   << "Début LBA : " << part.start_sector << std::endl
		   << "Secteurs  : " << part.sector_count << " (" << static_cast<float>(part.sector_count * 512) / (1024.f * 1024.f) << " Mio)";

	return stream;
}

