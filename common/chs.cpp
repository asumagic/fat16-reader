#include "chs.hpp"

std::ostream& operator<<(std::ostream& stream, const chs::Address& chs)
{
	stream << static_cast<int>(chs.cylinder) << "/"
		   << static_cast<int>(chs.head) << "/"
		   << static_cast<int>(chs.sector);
	return stream;
}
