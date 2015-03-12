// --

#include <iostream>
#include <string>

#include "Filesystem-pool.h"
#include "Lexical-cast-pool.h"
#include "ParsingXML.h"

int
main(int /*argc*/, char* argv[])
{
	std::cout << "Hello, Boost!" << std::endl;

	const std::string exeFile = argv[0];
	ExamplesOfFileSystem(exeFile);

	ExamplesOfLexicalCast();

	const std::string filenameIn = "input.xml";
	const std::string filenameOut = "output.xml";
	const bool succeeded = ParseXML(filenameIn, filenameOut);
	std::clog << "ParseXML " << (succeeded ? "succeeded" : "failed") << std::endl;

	return EXIT_SUCCESS;
}

// -- eof
