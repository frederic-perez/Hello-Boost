// --

#include <iostream>
#include <string>

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

void
ExamplesOfLexicalCast(const std::string& a_string)
{
	std::clog << "ExamplesOfLexicalCast(-) started..." << std::endl;

	using boost::lexical_cast;
	using boost::bad_lexical_cast;

	const std::string pad = "  ";

	const int valueIntS = stoi(a_string);
	std::cout << pad << "stoi(\"" << a_string << "\") is "
		<< valueIntS << std::endl;
	const int valueIntL = lexical_cast<int>(a_string);
	std::cout << pad << "lexical_cast<int>(\"" << a_string << "\") is "
		<< valueIntL << std::endl;

	const short valueShortS = static_cast<short>(stoi(a_string));
	std::cout << pad << "stoi(\"" << a_string << "\") is "
		<< valueShortS << std::endl;
	try {
		const short valueShortL = lexical_cast<short>(a_string);
		std::cout << pad << "lexical_cast<short>(\"" << a_string << "\") is "
			<< valueShortL << std::endl;
	}
	catch (const boost::bad_lexical_cast& e) {
		std::cerr << pad << "Exception caught: " << e.what() << "\n";
	}

	std::clog << "ExamplesOfLexicalCast(-) finished." << std::endl;
}

namespace {

	void
		Output(const std::string& a_description, const std::string& a_value) {
		const std::string pad = "  ";
		std::cout << pad << a_description << ": \"" << a_value << "\"" << std::endl;
	}

} // namespace

void
ExamplesOfAlgorithmsString()
{
	std::clog << "ExamplesOfAlgorithmsString() started..." << std::endl;

	std::string name = "  Alan Turing  ";
	Output("Name (original)", name);

	using namespace boost::algorithm;
	to_lower(name);
	Output("Name (after to_lower)", name);
	to_upper(name);
	Output("Name (after to_upper)", name);
	trim_right(name);
	Output("Name (after trim_right)", name);
	trim(name);
	Output("Name (after trim)", name);
	name.erase(remove_if(name.begin(), name.end(), isspace), name.end());
	Output("Name (after isspace removal)", name);

	std::clog << "ExamplesOfAlgorithmsString() finished." << std::endl;
}

int
main(int /*argc*/, char* /*argv*/[])
{
	std::cout << "Hello, Boost!\n" << std::endl;

	const std::string inputValue = "1234567890";
	ExamplesOfLexicalCast(inputValue);
	std::cout << std::endl;
	
	ExamplesOfAlgorithmsString();
	std::cout << std::endl;

	std::cout << "Bye, Boost!" << std::endl;
	return EXIT_SUCCESS;
}

// -- eof
