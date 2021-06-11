// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  3/17/21

#include "StringUtility.hpp"
#include <regex>
#include <cctype>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>


namespace strutil {
	
	
	// Whitespace related
	
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++
	std::string ltrim(const std::string& s) {
		return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
	}
	
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++
	std::string rtrim(const std::string& s) {
		return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
	}
	
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++
	std::string trim(const std::string& s) {
		return ltrim(rtrim(s));
	}
	
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++
	std::string simplify(const std::string& input){
		std::regex re("\\s{2,}");
		std::string fmt = " ";
		auto output = regex_replace(input, re, fmt);
		return output ;
	}
	
	// Upper and lower
	
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++
	std::string toupper(const std::string &s) {
		auto input = s ;
		std::transform(input.begin(), input.end(), input.begin(),
				   [](unsigned char c){ return std::toupper(c); } // correct
				   );
		return input;
	}
	
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++
	std::string tolower(const std::string &s) {
		auto input = s ;
		std::transform(input.begin(), input.end(), input.begin(),
				   [](unsigned char c){ return std::tolower(c); } // correct
				   );
		return input;
	}
	
	
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++
	std::string stripComment(const std::string &input,const std::string &commentdelim ){
		auto loc = input.find(commentdelim) ;
		auto value = input.substr(0,loc);
		value = trim(value) ;
		return value;
	}
	
	//====================================================================
	std::string& stripTrim(std::string& s)  {
		auto loc = s.find("//") ;
		if (loc != std::string::npos) {
			s = s.substr(0,loc) ;
		}
		loc = s.find_first_not_of(" \t\v") ;
		if (loc != std::string::npos) {
			auto eloc = s.find_last_not_of(" \t\v") ;
			s = s.substr(loc,(eloc-loc)+1);
		}
		return s ;
	}
	//====================================================================
	std::string format(const char * expr,...) {
		char buffer[2048] ;
		va_list v1 ;
		va_start(v1, expr);
		vsnprintf(buffer, 2048, expr, v1);
		va_end(v1) ;
		return std::string(buffer);
	}
	
	//====================================================================
	std::tuple<std::string,std::string> split(const std::string &value, const std::string &sep){
		std::string first ;
		std::string second ;
		auto loc = value.find(sep);
		if (loc == std::string::npos){
			first = value ;
		}
		else {
			first = strutil::rtrim(value.substr(0,loc));
			if ((loc+1) < value.size()) {
				second = strutil::ltrim(value.substr(loc+1));
			}
		}
		return std::make_tuple(first,second);
	}
	
}
