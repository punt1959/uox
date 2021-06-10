// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  3/17/21

#ifndef StringUtility_hpp
#define StringUtility_hpp
#include <cstdint>
#include <string>
#include <type_traits>


namespace strutil {
	// Trim a string of all leading whitespace
	std::string ltrim(const std::string& s) ;
	
	// Trim a string of all trailing whitespace
	std::string rtrim(const std::string& s) ;
	
	// Trim all leading and trailing white space
	std::string trim(const std::string& s) ;
	
	// Trim all leading/trailing white space, and replace all internal white space to one space
	std::string simplify(const std::string& input);
	
	
	// Convert the string to all uppercase
	std::string toupper(const std::string &s);
	// Convert the string to all lowercase
	std::string tolower(const std::string &s);
	
	// Strip all trailing characters after and including comment deliminator
	std::string stripComment(const std::string& input,const std::string &commentdelim = "//");
	
	std::string& stripTrim(std::string& s);
	
	// Format a string
	std::string format(const char * expr,...);
	

}


#endif /* StringUtility_hpp */
