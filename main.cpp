// --

#include <iostream>
#include <string>

#include "algorithm-string-pool.h"
#include "filesystem-pool.h"
#include "lexical-cast-pool.h"

int
main(int /*argc*/, char* argv[])
{
	std::cout << "Hello, Boost!" << std::endl;

	using namespace HelloBoost;
	
	const std::string exeFile = argv[0];
	ExamplesOfFileSystem(exeFile);

	const std::string inputValue = "1234567890";
	ExamplesOfLexicalCast(inputValue);
	
	ExamplesOfAlgorithmsString();

	return EXIT_SUCCESS;
}

// -- eof
