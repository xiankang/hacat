#pragma once
#include <string>
#include <cstdarg>
#include <vector>

#define BUFFSIZE 512
inline std::string format_string(const char* format, va_list args)
{
	va_list argscopy;
	va_copy(argscopy, args);

	char buff[BUFFSIZE] = {0};

	size_t size = snprintf(buff, BUFFSIZE, format, args);
	printf("%s", buff);
	return buff;
}

inline std::string format_string(const char* format, ...)
{
	va_list args;

	va_start(args, format);
	auto s = format_string(format, args);
	va_end(args);

	return s;
}

