
#include <vector>
#include <string>
#include "xyc_utils.h"
#include "abc_utils.h"
#include <iostream>

std::string helloString(std::string str)
{
	return "Hello world " + str;
}

using namespace std;

// int main( int argc, const char* argv[] )
int main()
{
    std::cout << helloString("Earth") << endl;
	auto ivec1 = abc::split_to_ints("12|2343|23434", '|');
	auto ivec2 = xyc::split_to_ints("23|101230|-23", '|');
	for (int v : ivec1) {
		cout << "From static lib:" << v << endl;
	}
	for (int v : ivec2) {
		cout << "From dynamic lib:" << v << endl;
	}
}
