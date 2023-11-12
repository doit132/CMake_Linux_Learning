#include <iostream>
#include <math.h>

// 引入 TutorialConfig.h
#include "TutorialConfig.h"

// 条件判断 USE_MYMATH 是否包含 MathFunctions.h 文件
#ifdef USE_MYMATH
	#include "MathFunctions.h"
#endif

int main(int argc, char const *argv[])
{
	int a = 100;
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

// 条件判断 USE_MYMATH
// calculate square root
#ifdef USE_MYMATH
	const double outputValue = mysqrt(inputValue);
#else
	const double outputValue = sqrt(inputValue);
#endif
	std::cout << "The square root of " << inputValue << " is " << outputValue << std::endl;
	return 0;
}
