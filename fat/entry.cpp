#include "entry.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>

namespace fat
{
	bool Entry::present() const
	{
		return (data.filename[0] != 0x00) &&
			   (data.filename[0] != 0xE5) &&
			  !(data.attributes & 0x0F); // Ignore MS' Long File Names
	}

	bool Entry::is_directory() const
	{
		return data.attributes & 0x10;
	}

	bool Entry::is_file() const
	{
		return !is_directory();
	}

	uint8_t Entry::first_char() const
	{
		if (data.filename[0] == 0x05)
			return 0xE5;
		else
			return data.filename[0];
	}

	std::string Entry::filename() const
	{
		std::string raw{data.filename, data.filename + 8};
		raw[0] = static_cast<char>(first_char());

		const auto shrink_at = std::find_if(rbegin(raw), rend(raw), [](const char c) { return c != ' '; });
		return std::string{&(raw[0]), &(*shrink_at) + 1}; // @TODO make this less worse
	}

	std::string Entry::filename_full() const
	{
		return filename() + '.' + extension();
	}

	std::string Entry::extension() const
	{
		const std::string raw{data.extension, data.extension + 3};

		const auto shrink_at = std::find_if(rbegin(raw), rend(raw), [](const char c) { return c != ' '; });
		return std::string{raw.data(), &(*shrink_at) + 1}; // make this less worse
	}

	std::string Entry::directory_name() const
	{
		std::string raw{data.filename, data.extension + 3};
		raw[0] = static_cast<char>(first_char());

		const auto shrink_at = std::find_if(rbegin(raw), rend(raw), [](const char c) { return c != ' '; });
		return std::string{&(raw[0]), &(*shrink_at) + 1}; // make this less worse
	}
}

std::ostream& operator<<(std::ostream& stream, const fat::Entry& part)
{
	if (part.is_directory())
		stream << "Répertoire : " << part.directory_name();
	else if (part.is_file())
		stream << "Fichier : " << part.filename_full();

	return stream;
}
