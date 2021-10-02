#pragma once
#include <fstream>
class Helpers
{
public:
	bool is_empty(std::ifstream& pFile)
	{
		return pFile.peek() == std::ifstream::traits_type::eof();
	}
};

