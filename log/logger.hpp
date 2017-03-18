#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <string>

struct Logger : std::ostream, std::streambuf
{
	const std::string _prefix;
	bool _first_char = true;

	void print_prefix();

public:
	Logger(const std::string prefix);

	int overflow(int c) override;
};

extern Logger iolog, mbrlog, fatlog;
extern const std::string trivial, caution, useful, important;

#endif // LOGGER_HPP
