#include "chs.hpp"

std::ostream& operator<<(std::ostream& stream, const CHSAddress& chs)
{
	stream << static_cast<int>(chs.cylinder) << "/"
		   << static_cast<int>(chs.head) << "/"
		   << static_cast<int>(chs.sector);
	return stream;
}
