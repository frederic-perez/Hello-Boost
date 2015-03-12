// --

// Based on the example by Andrzej Krzemienski
// in https://akrzemi1.wordpress.com/examples/parsing-xml/

// Copyright 2014 Andrzej Krzemienski.
//
// This demonstrates how to use Boost.PropertyTree
// to read and write XML files.

#include <iostream>

#include <boost/foreach.hpp>

#include "ParsingXML.h"

#ifdef DATETRANSLATOR

namespace boost {
namespace property_tree {
 
template<> struct translator_between<std::string, Date> {
		typedef DateTranslator type;
};

} // namespace property_tree
} // namespace boost

#endif

Sked
read(std::istream& is)
{
	// populate tree structure pt
	using boost::property_tree::ptree;
	ptree pt;
	read_xml(is, pt);
	 
	// traverse pt
	Sked ans;
	BOOST_FOREACH(ptree::value_type const&v, pt.get_child("sked")) {
		if (v.first == "flight") {
			Flight f;
			f.carrier = v.second.get<std::string>("carrier");
			f.number = v.second.get<unsigned>("number");
			f.date = v.second.get<Date>("date");
			f.cancelled = v.second.get("<xmlattr>.cancelled", false);
			ans.push_back(f);
		}
	}
	return ans;
}
 
void
write(Sked sked, std::ostream & os)
{
	using boost::property_tree::ptree;
	ptree pt;
	 
	pt.add("sked.version", 3);
	 
	for (Flight f : sked) {
		ptree& node = pt.add("sked.flight", "");
		node.put("carrier", f.carrier);
		node.put("number", f.number);
		node.put("date", f.date);
		if (f.cancelled)
			node.put("<xmlattr>.cancelled", true);
	}
	write_xml(os, pt);
}
 
bool
ParseXML(
	const std::string& a_inputFilename,
	const std::string& a_outputFilename)
{
	std::clog << __func__ << " started..." << std::endl;
	try {
		std::ifstream input(a_inputFilename);
		Sked sked = read(input);
		std::clog << "  ParseXML: Read(\"" << a_inputFilename << "\") finished"
			<< std::endl;
		std::ofstream output(a_outputFilename);
		write(sked, output);
		std::clog << "  ParseXML: Writing of \"" << a_outputFilename
			<< "\" finished" << std::endl;
	} catch (...) {
		return false;
	}
	std::clog << __func__ << " finished." << std::endl;
	return true;
}

// -- eof
