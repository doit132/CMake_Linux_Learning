#include <iostream>
#include <math.h>

// 引入 TutorialConfig.h
#include "TutorialConfig.h"

// TODO 5: Include MathFunctions.h
#include "MathFunctions.h"

int main(int argc, char const *argv[])
{
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " number" << std::endl;
		std::cout << "__cplusplus: " << __cplusplus << std::endl;
		std::cout << "Tutorial_VERSION_MAJOR: " << Tutorial_VERSION_MAJOR << std::endl;
		std::cout << "Tutorial_VERSION_MINOR: " << Tutorial_VERSION_MINOR << std::endl;
		return 1;
	}

	// convert input to double
	// 用 std::stod(argv[1] 替换 atof(argv[1]), 因为 stod 是 C++11 版本才支持的
	// const double inputValue = atof(argv[1]);
	const double inputValue = std::stod(argv[1]);

	// TODO 6: 把 sqrt 替换为 mysqrt
	// calculate square root
	const double outputValue = mysqrt(inputValue);
	std::cout << "The square root of " << inputValue << " is " << outputValue << std::endl;
	return 0;
}
