// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  6/1/21

#ifndef IDX_hpp
#define IDX_hpp

#include <cstdint>
#include <string>
#include <vector>
namespace UO {
	struct idxentry {
		unsigned int offset ;
		unsigned int length ;
		unsigned int extra ;
		idxentry() {
			offset = 0xFFFFFFFE ;
			length = 0 ;
			extra = 0 ;
		}
		unsigned short width() const {
			return static_cast<unsigned short>((extra&0x0000FFFF));
		}
		unsigned short height() const {
			return static_cast<unsigned short>(((extra&0xFFFF0000)>>16));
		}
		bool valid() const {
			return ((length>0) && (length != 0xFFFFFFFF)&&(offset != 0xFFFFFFFE) && (offset != 0xFFFFFFFF));
		}
	};

	class IDX {
	private:
		std::vector<idxentry> _entries ;
	public:
		IDX(const std::string &filename="");
		void load(const std::string &filename);
		std::size_t maxEntry() const ;
		const std::vector<idxentry>& entries() const ;
		const idxentry& entry(std::size_t id)const ;
	};
}
#endif /* IDX_hpp */
