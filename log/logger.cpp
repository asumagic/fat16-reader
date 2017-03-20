#include "logger.hpp"

void Logger::print_prefix()
{
	_first_char = false;
	(*this) << _prefix << ' ';
}

Logger::Logger(const std::string& prefix) :
	std::ostream{this},
	_prefix{prefix}
{}

int Logger::overflow(int c)
{
	if (_first_char)
		print_prefix();
	else if (c == '\n')
		_first_char = true;

	std::cout << static_cast<char>(c);

	return 0;
}

Logger iolog{"\x1b[93m[E/S]\x1b[0m"},
	   mbrlog{"\x1b[94m[MBR]\x1b[0m"},
	   fatlog{"\x1b[92m[FAT]\x1b[0m"};

const std::string trivial{"\x1b[90m"},
				  caution{"\x1b[93m"},
				  useful{"\x1b[1m"},
				  important{"\x1b[91m"};
