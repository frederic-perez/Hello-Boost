// --

#include <iostream>

#define BOOST_LIB_DIAGNOSTIC

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/system/config.hpp>

void
TestFileSystem(const std::string& a_filename)
{

	const std::string filename = "main.cpp";
	std::cout << filename << " has a file_size of "
		<< boost::filesystem::file_size(a_filename) << std::endl;
}

void
TestLexicalCast()
{
	using boost::lexical_cast;
	using boost::bad_lexical_cast;

	const short value = lexical_cast<short>("66");
	std::cout << "lexical_cast<short>(\"66\") is " << value << std::endl;
}

int
main(int /*argc*/, char* argv[])
{
	std::cout << "Hello, world!" << std::endl;
	const std::string exeFile = argv[0];

	TestFileSystem(exeFile);

	return EXIT_SUCCESS;
}

// -- eof
