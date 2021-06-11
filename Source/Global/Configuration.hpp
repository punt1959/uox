// 
// Created on:  6/7/21

#ifndef Configuration_hpp
#define Configuration_hpp

#include <cstdint>
#include <string>
#include <filesystem>
#include <map>

#include "DataCategory.hpp"

class Configuration {
private:
	Configuration() ;
	std::map<DataCategory::Category, DataCategory> _categories ;
	
	static std::filesystem::path _starting_location ;
protected:
	DataCategory _config ;
	
	// These are to prevent constant lookup
	std::filesystem::path _uodir ;
	std::filesystem::path _root;
	std::filesystem::path _savelocation ;
	std::filesystem::path _loglocation;
	std::filesystem::path _accountlocation;
	std::filesystem::path _definition_location;
	std::filesystem::path _book_location;
	std::filesystem::path _html_location;
	std::filesystem::path _msgboard_location;
	std::filesystem::path _script_location;

	std::string _name ;
	std::string _port ;
	std::string _external_ip ;
	bool _default_logging ;
	
	void loadDirectory(std::shared_ptr<DataSection> &section);
	void loadServer(std::shared_ptr<DataSection> &section);
	void validateDirectory() ;

	
public:
	~Configuration();
	Configuration( const Configuration &) = delete;
	Configuration& operator=(const Configuration&) = delete ;
	static Configuration& shared() ;

	void loadBase(const std::string &filename);
	void loadDefinitions( const std::string &path);
	
	// Lets get all the sections for a category
	std::map<std::string,std::shared_ptr<DataSection> > sections(DataCategory::Category cat) ;
	
	std::shared_ptr<DataSection> section(DataCategory::Category cat, const std::string & section) ;
	
	
	// Configuration file info
	std::filesystem::path  uodir() const {return _uodir;}
	
	std::string root() const {return _root.string();}
	std::string save() const {return _savelocation.string();}
	std::string log() const {return _loglocation.string();}
	std::string account() const {return _accountlocation.string();}
	std::string definition() const {return _definition_location.string();}
	std::string script() const {return _script_location.string();}
	std::string html() const {return _html_location.string();}
	std::string book() const {return _book_location.string();}
	std::string msgboard() const {return _msgboard_location.string();}

	const std::string& name() const { return _name ;}
	const std::string& port() const { return _port;}
	const std::string& ip() const { return _external_ip;} 
	bool defaultlog () const { return _default_logging;}

};

#endif /* Configuration_hpp */
