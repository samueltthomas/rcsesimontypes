#pragma once
#include <chrono>
#include <thread>
#include <algorithm>

std::string random_string(int length)
{
	auto randchar = []() -> char
	{
		const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	std::string str(length, 0);
	generate_n(str.begin(), length, randchar);
	return str;
}

void delay(int ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

std::string toUpperCase(std::string str)
{
	for (int i = 0; str[i] != 0; i++)
		if (str[i] <= 'z' && str[i] >= 'a')
			str[i] -= 32;
	return str;
}