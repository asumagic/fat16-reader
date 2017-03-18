#ifndef CHS_HPP
#define CHS_HPP

#include <iostream>
#include <cstdint>

struct CHSAddress
{
	uint8_t cylinder, head, sector;
} __attribute__((packed));

std::ostream& operator<<(std::ostream& stream, const CHSAddress& chs);

#endif // CHS_HPP
