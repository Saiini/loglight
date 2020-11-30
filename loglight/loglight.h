#pragma once
#include <stdio.h>
#include <chrono>
#include <ctime> 
#include <thread> 
#include "rang.h"

#ifdef _WIN64
#pragma warning(disable : 4996) 
#endif

class Log
{

public:

	enum LogLevel
	{
		ERR,
		INFO,
		DEBUG,
		WARNING,
		SYSTEM,
		NETWORK,
	};


	static void log(char* text, LogLevel level) {
		rang::fg    color;
		std::string _level;
		std::time_t t = std::time(0);
		std::tm* curr = std::localtime(&t);

		switch (level) {
		case ERR:
			color = rang::fg::red;
			_level = "ERROR";
			break;
		case INFO:
			color = rang::fg::cyan;
			_level = "INFO";
			break;
		case DEBUG:
			color = rang::fg::green;
			_level = "DEBUG";
			break;
		case WARNING:
			color = rang::fg::yellow;
			_level = "WARNING";
			break;
		case SYSTEM:
			color = rang::fg::magenta;
			_level = "SYSTEM";
			break;
		case NETWORK:
			color = rang::fg::blue;
			_level = "NETWORK";
			break;
		}

		std::cout << "[" <<
			color <<
			curr->tm_hour <<
			":" <<
			curr->tm_min <<
			":" <<
			curr->tm_sec <<
			" " << rang::fg::reset << "<" << color << _level << rang::fg::reset << ">" <<
			rang::fg::reset <<
			"] " <<
			text << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
};