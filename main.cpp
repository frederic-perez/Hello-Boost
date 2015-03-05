// --

#include <iostream>

#define BOOST_LIB_DIAGNOSTIC

#undef TESTFILESYSTEM
#ifdef TESTFILESYSTEM

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/system/config.hpp>

void
TestFileSystem(const std::string& a_filename)
{
	using namespace boost::filesystem;

	// "Testing" a_filename

	std::cout << a_filename << " has a file_size of "
		<< file_size(a_filename) << " bytes" << std::endl;

	std::cout << a_filename;
	const path myPath1(a_filename);
	if (myPath1.has_extension())
		std::cout << " has the extension " << myPath1.extension();
	else
		std::cout << " does not have any extension";
	std::cout << std::endl;

	// "Testing" the current directory

	const std::string dot = ".";
	const path currentDir(dot);
	const bool isDirectory = is_directory(currentDir);
	std::cout << "is_directory(" << currentDir << ") = " << std::boolalpha
		<< isDirectory << std::endl;

	if (isDirectory) {
		std::cout << "Directory contents:" << std::endl;
		std::copy(
			directory_iterator(currentDir), directory_iterator(),
			std::ostream_iterator<directory_entry>(std::cout, "\n"));
			// directory_iterator::value_type is directory_entry, which is converted
			// to a path by the path stream inserter
	}
}
#endif

#undef TESTLEXICALCAST
#ifdef TESTLEXICALCAST
void
TestLexicalCast()
{
	using boost::lexical_cast;
	using boost::bad_lexical_cast;

	const short value = lexical_cast<short>("66");
	std::cout << "lexical_cast<short>(\"66\") is " << value << std::endl;
}
#endif

int
main(int /*argc*/, char* argv[])
{
	std::cout << "Hello, world!" << std::endl;
	const std::string exeFile = argv[0];

#ifdef TESTFILESYSTEM
	TestFileSystem(exeFile);
#endif

#ifdef TESTLEXICALCAST
	TestLexicalCast()
#endif

	return EXIT_SUCCESS;
}

// -- eof
