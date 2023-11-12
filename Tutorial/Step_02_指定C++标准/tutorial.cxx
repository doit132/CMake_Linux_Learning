#include <iostream>
#include <math.h>

int main(int argc, char const *argv[])
{
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " number" << std::endl;
		std::cout << "__cplusplus: " << __cplusplus << std::endl;
		return 1;
	}

	// convert input to double
	// TODO 4： 用 std::stod(argv[1] 替换 atof(argv[1]), 因为 stod 是 C++11 版本才支持的
	// const double inputValue = atof(argv[1]);
	const double inputValue = std::stod(argv[1]);

	// calculate square root
	const double outputValue = sqrt(inputValue);
	std::cout << "The square root of " << inputValue << " is " << outputValue << std::endl;
	return 0;
}
