// -- Examples on how to use boost::lexical_cast

#include <iostream>

#include <boost/lexical_cast.hpp>

#include "AuxRaw.h"
#include "Lexical-cast-pool.h"

void
ExamplesOfLexicalCast()
{
	std::clog << __func__ << " started..." << std::endl;
	
	using boost::lexical_cast;
	using boost::bad_lexical_cast;

	const std::string pad = "  ";
	const short value = lexical_cast<short>("66");
	std::cout << pad << "lexical_cast<short>(\"66\") is " << value << std::endl;
	
	std::clog << __func__ << " finished." << std::endl;
}

// -- eof
