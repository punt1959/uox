// 
// Created on:  6/7/21

#include "Configuration.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <filesystem>
#include "StringUtility.hpp"
#include "DataCategory.hpp"
//+++++++++++++++++++++++++++++++++++++++++++++++++++
//
//		Methods for Configuration
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++
std::filesystem::path Configuration::_starting_location = std::filesystem::path(".");
//===========================================================================
Configuration::Configuration(){
	_starting_location = std::filesystem::current_path();
}
//===========================================================================
Configuration::~Configuration() {
	std::filesystem::current_path(_starting_location);
}
//============================================================================
Configuration& Configuration::shared(){
	static Configuration instance;
	return instance ;
}

//============================================================================
void Configuration::loadDirectory(std::shared_ptr<DataSection> &section){

	if (auto entry = section->firstKey("UODATA")) {
		_uodir = std::filesystem::path(entry->text) ;
	}
	else {
		throw std::runtime_error(std::string("'UODATA' in [DIRECTORY] not found in configuration: ")+ section->origin());
	}

	if (auto entry =  section->firstKey("ROOT")) {
		_root = std::filesystem::path(entry->text) ;
	}
	else {
		throw std::runtime_error(std::string("'ROOT' in [DIRECTORY] not found in configuration: ")+section->origin());
	}

	if (auto entry =  section->firstKey("ACCOUNTS")) {
		_accountlocation = std::filesystem::path(entry->text) ;
	}
	else {
		throw std::runtime_error(std::string("'ACCOUNTS' in [DIRECTORY] not found in configuration: ")+section->origin());
	}

	if (auto entry =  section->firstKey("SAVE")) {
		_savelocation = std::filesystem::path(entry->text) ;
	}
	else {
		throw std::runtime_error(std::string("'SAVE' in [DIRECTORY] not found in configuration: ")+section->origin());
	}

	if (auto entry =  section->firstKey("LOGS")) {
		_loglocation = std::filesystem::path(entry->text) ;
	}
	else {
		throw std::runtime_error(std::string("'LOGS' in [DIRECTORY] not found in configuration: ")+section->origin());
	}

	if (auto entry =  section->firstKey("DEFINITIONS")) {
		_definition_location = std::filesystem::path(entry->text) ;
	}
	else {
		throw std::runtime_error(std::string("'DEFINITIONS' in [DIRECTORY] not found in configuration: ")+section->origin());
	}
	
	if (auto entry =  section->firstKey("BOOK")) {
		_book_location = std::filesystem::path(entry->text) ;
	}
	else {
		throw std::runtime_error(std::string("'BOOK' in [DIRECTORY] not found in configuration: ")+section->origin());
	}

	if (auto entry =  section->firstKey("HTML")) {
		_html_location = std::filesystem::path(entry->text) ;
	}
	else {
		throw std::runtime_error(std::string("'HTML' in [DIRECTORY] not found in configuration: ")+section->origin());
	}
	
	if (auto entry =  section->firstKey("SCRIPT")) {
		_script_location = std::filesystem::path(entry->text) ;
	}
	else {
		throw std::runtime_error(std::string("'BOOK' in [DIRECTORY] not found in configuration: ")+section->origin());
	}
	
	if (auto entry =  section->firstKey("MSGBOARD")) {
		_msgboard_location = std::filesystem::path(entry->text) ;
	}
	else {
		throw std::runtime_error(std::string("'MSGBOARD' in [DIRECTORY] not found in configuration: ")+section->origin());
	}
	


	// Now we need to validate
	validateDirectory();
}

//============================================================================
void Configuration::validateDirectory() {
	// We want to validate that the directories, exist, and move our current_dir to root
	// first, move ourself to the root directory
	if (std::filesystem::exists(_root) && std::filesystem::is_directory(_root)){
		std::filesystem::current_path(_root) ;
		_root = std::filesystem::current_path();
	}
	else {
		throw std::runtime_error(std::string("ROOT directory does not exist or is not a directory: ")+_root.string());
	}
	
	if (!std::filesystem::exists(_uodir) || !std::filesystem::is_directory(_uodir)){
		throw std::runtime_error(std::string("UODATA directory does not exist or is not a directory: ")+_uodir.string());
	}

	// Now we need to determine if the other directores are relative or absolute
	
	if (!_accountlocation.is_absolute()){
		_accountlocation = _root / _accountlocation ;
	}
	if (!std::filesystem::exists(_accountlocation) || !std::filesystem::is_directory(_accountlocation)){
		throw std::runtime_error(std::string("ACCOUNT directory does not exist or is not a directory: ")+_accountlocation.string());
		
	}
	
	if (!_loglocation.is_absolute()){
		_loglocation = _root / _loglocation ;
	}
	if (!std::filesystem::exists(_loglocation) || !std::filesystem::is_directory(_loglocation)){
		throw std::runtime_error(std::string("LOG directory does not exist or is not a directory: ")+_loglocation.string());
		
	}
	
	if (!_savelocation.is_absolute()){
		_savelocation = _root / _savelocation ;
	}
	if (!std::filesystem::exists(_savelocation) || !std::filesystem::is_directory(_savelocation)){
		throw std::runtime_error(std::string("SAVE directory does not exist or is not a directory: ")+_savelocation.string());
	}
	
	
	if (!_definition_location.is_absolute()){
		_definition_location = _root / _definition_location ;
	}
	if (!std::filesystem::exists(_definition_location) || !std::filesystem::is_directory(_definition_location)){
		throw std::runtime_error(std::string("DEFINITION directory does not exist or is not a directory: ")+_definition_location.string());
	}
	
	if (!_html_location.is_absolute()){
		_html_location = _root / _html_location ;
	}
	if (!std::filesystem::exists(_html_location) || !std::filesystem::is_directory(_html_location)){
		throw std::runtime_error(std::string("HTML directory does not exist or is not a directory: ")+_html_location.string());
	}

	if (!_script_location.is_absolute()){
		_script_location = _root / _script_location ;
	}
	if (!std::filesystem::exists(_script_location) || !std::filesystem::is_directory(_script_location)){
		throw std::runtime_error(std::string("SCRIPT directory does not exist or is not a directory: ")+_script_location.string());
	}
	
	if (!_book_location.is_absolute()){
		_book_location = _root / _book_location ;
	}
	if (!std::filesystem::exists(_book_location) || !std::filesystem::is_directory(_book_location)){
		throw std::runtime_error(std::string("BOOK directory does not exist or is not a directory: ")+_book_location.string());
	}
	if (!_msgboard_location.is_absolute()){
		_msgboard_location = _root / _msgboard_location ;
	}
	if (!std::filesystem::exists(_msgboard_location) || !std::filesystem::is_directory(_msgboard_location)){
		throw std::runtime_error(std::string("MSGBOARD directory does not exist or is not a directory: ")+_msgboard_location.string());
	}

}

//============================================================================
void Configuration::loadBase(const std::string &filename){
	if (!std::filesystem::exists(std::filesystem::path(filename))){
		throw std::runtime_error(std::string("Unable to find configuration: ")+filename);
	}
	_config.loadFile(filename);
	if (auto section = _config.section("directory")) {
		loadDirectory(section);
	}
	else {
		throw std::runtime_error(std::string("Section [DIRECTORY] not found in configuration: ")+filename);
	}
	if (auto section = _config.section("server")) {
		loadServer(section);
	}
	else {
		throw std::runtime_error(std::string("Section [SERVER] not found in configuration: ")+filename);
	}
	
	
}
//===========================================================================
void Configuration::loadServer(std::shared_ptr<DataSection> &section){
	if (auto entry = section->firstKey("NAME")) {
		_name = entry->text ;
	}
	else {
		throw std::runtime_error(std::string("'NAME' in [SERVER] not found in configuration: ")+ section->origin());
	}
	if (auto entry =  section->firstKey("PORT")) {
		_port = entry->text;
	}
	else {
		throw std::runtime_error(std::string("'PORT' in [SERVER] not found in configuration: ")+section->origin());
	}
	if (auto entry =  section->firstKey("EXTERNALIP")) {
		_external_ip = entry->text ;
	}
	else {
		throw std::runtime_error(std::string("'EXTERNALIP' in [SERVER] not found in configuration: ")+section->origin());
	}
	if (auto entry =  section->firstKey("DEFAULTLOGGING")) {
		if (entry->text == "1") {
			_default_logging =true ;
		}
		else {
			_default_logging = false ;
		}
	}
	else {
		throw std::runtime_error(std::string("'DEFAULTLOGGING' in [SERVER] not found in configuration: ")+section->origin());
	}
}
//===========================================================================
void Configuration::loadDefinitions( const std::string &path) {
	for (auto &entry : DataCategory::directories){
		DataCategory category;
		category.loadData(path, entry.first);
		_categories.insert_or_assign(entry.first, category);
	}
	
}

//===========================================================================
std::map<std::string,std::shared_ptr<DataSection> > Configuration::sections(DataCategory::Category cat){
	return _categories[cat].sections();
}

//===========================================================================
std::shared_ptr<DataSection> Configuration::section(DataCategory::Category cat, const std::string & section){
	return _categories[cat].section(section) ;
}
