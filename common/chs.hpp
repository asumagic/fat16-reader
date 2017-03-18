#ifndef CHS_HPP
#define CHS_HPP

#include <iostream>
#include <cstdint>

namespace chs
{
	struct Address
	{
		uint8_t cylinder, head, sector;
	} __attribute__((packed));
}

std::ostream& operator<<(std::ostream& stream, const chs::Address& chs);

#endif // CHS_HPP
