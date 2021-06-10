// Copyright © 2021 Charles Kerr. All rights reserved.
// Created on:  5/31/21

#ifndef UOTiles_hpp
#define UOTiles_hpp

#include <cstdint>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
namespace UO {
	constexpr unsigned short InvalidTile = 0xFFFF ;
	
	enum TileType {invalid=-1,land=0,art=1};

	// No enum?   No, because we want to test multiple flags at one time
	struct TileFlag {
		static constexpr unsigned long long none 		= 0x0000000000000000;
		static constexpr unsigned long long background 	= 0x0000000000000001;
		static constexpr unsigned long long weapon 	= 0x0000000000000002;
		static constexpr unsigned long long holdable 	= 0x0000000000000002;	// Alternative for weapon
		static constexpr unsigned long long transparent = 0x0000000000000004;
		static constexpr unsigned long long translucent = 0x0000000000000008;
		static constexpr unsigned long long wall 		= 0x0000000000000010;
		static constexpr unsigned long long damaging 	= 0x0000000000000020;
		static constexpr unsigned long long impassable 	= 0x0000000000000040;
		static constexpr unsigned long long wet 		= 0x0000000000000080;
		static constexpr unsigned long long unknown1 	= 0x0000000000000100;
		static constexpr unsigned long long surface 	= 0x0000000000000200;
		static constexpr unsigned long long bridge 	= 0x0000000000000400;
		static constexpr unsigned long long climable 	= 0x0000000000000400;  // alternative for bridge
		static constexpr unsigned long long generic 	= 0x0000000000000800;
		static constexpr unsigned long long stackable 	= 0x0000000000000800;  // alternative for generic
		static constexpr unsigned long long window 	= 0x0000000000001000;
		static constexpr unsigned long long noshoot 	= 0x0000000000002000;
		static constexpr unsigned long long articlea 	= 0x0000000000004000;
		static constexpr unsigned long long articlean 	= 0x0000000000008000;
		static constexpr unsigned long long internal 	= 0x0000000000010000;
		static constexpr unsigned long long description	= 0x0000000000010000;  // alternative for internal
		static constexpr unsigned long long foliage 	= 0x0000000000020000;
		static constexpr unsigned long long partialHue 	= 0x0000000000040000;
		static constexpr unsigned long long unknown2 	= 0x0000000000080000;
		static constexpr unsigned long long map 		= 0x0000000000100000;
		static constexpr unsigned long long container 	= 0x0000000000200000;
		static constexpr unsigned long long wearable 	= 0x0000000000400000;
		static constexpr unsigned long long lightSource = 0x0000000000800000;
		static constexpr unsigned long long animation 	= 0x0000000001000000;
		static constexpr unsigned long long hoverover 	= 0x0000000002000000;
		static constexpr unsigned long long nodiagnol 	= 0x0000000002000000;  // alternative for hoverover ;
		static constexpr unsigned long long unknown3 	= 0x0000000004000000;
		static constexpr unsigned long long armor 	= 0x0000000008000000;
		static constexpr unsigned long long roof 		= 0x0000000010000000;
		static constexpr unsigned long long door 		= 0x0000000020000000;
		static constexpr unsigned long long stairback 	= 0x0000000040000000;
		static constexpr unsigned long long stairright 	= 0x0000000080000000;
		
		// HS tile flags
		static constexpr unsigned long long alphablend 	= 0x0000000100000000;
		static constexpr unsigned long long usenewart 	= 0x0000000200000000;
		static constexpr unsigned long long artused 	= 0x0000000400000000;
		static constexpr unsigned long long noshadow 	= 0x0000000800000000;
		static constexpr unsigned long long pixelbleed 	= 0x0000001000000000;
		static constexpr unsigned long long animonce 	= 0x0000002000000000;
		static constexpr unsigned long long multimove 	= 0x0000004000000000;

	};
	
	// The base of our tiles  (all have a tile id, and a flag value)
	struct base_tile {
		unsigned short tileid ;
		unsigned long long flag ;
		std::string name ;
		TileType type ;
		base_tile(TileType type=TileType::invalid) {this->type=type;tileid=InvalidTile;flag=TileFlag::none; }
		bool valid() { return (type!=TileType::invalid);}
		bool flags(unsigned long long mask) {
			if (mask == TileFlag::none) {
				return (flag == TileFlag::none);
			}
			else {
				return ((flag & mask) == mask);
			}
		}
		void setFlags(unsigned long long mask) {
			if (mask == TileFlag::none) {
				flag = TileFlag::none ;
			}
			else {
				flag = flag | mask ;
			}
		}
		bool anyFlag(unsigned long long mask){
			if (mask == TileFlag::none) {
				return (flag == TileFlag::none);
			}
			else {
				return ((flag & mask) >0);
			}
		}
		void clearFlags(unsigned long long mask){
			flag = (~mask) & flag;
		}
	};
	//			Land tile, the base tile that is in maps
	struct Land_Tile : public base_tile {
		unsigned short texture ;

		Land_Tile(unsigned short tileid=InvalidTile) : base_tile(TileType::land) {
			this->tileid = tileid ;
			texture = 0 ;
		}
	};
	//			Art tile, for any Static and Dynamic structure, etc.
	struct Art_Tile : public base_tile {
		unsigned char  weight ;
		unsigned char  quality ;
		unsigned short unknown0;
		unsigned char  unknown1;
		unsigned char  quantity ;
		unsigned short animation ;
		unsigned char  unknown2 ;
		unsigned char  hue_value ;
		unsigned short unknown3;
		unsigned char  height;
		Art_Tile(unsigned short tileid=InvalidTile) : base_tile(TileType::art){
			this->tileid=tileid ;
			weight=0 ;
			quality = 0 ;
			unknown0=0;
			unknown1=0;
			quantity=0 ;
			animation=0;
			unknown2=0;
			hue_value = 0 ;
			unknown3=0;
			height = 0 ;
			
		}
	};
	

	
	//================================================================
	// Tile storage access
	class Tiles {
	private:
		std::vector<std::shared_ptr<Land_Tile>> _land ;
		std::vector<std::shared_ptr<Art_Tile>> _art ;
		static constexpr auto sizeForHS = 3188736;

		bool _usingHS ;
		
		Tiles(const std::string& filename);
	protected:
		std::vector<std::shared_ptr<Art_Tile>> loadArt(std::ifstream& input, bool useHS);
		std::vector<std::shared_ptr<Land_Tile>> loadLand(std::ifstream& input, bool useHS);

	public:
		Tiles( const Tiles &) = delete;
		Tiles& operator=(const Tiles&) = delete ;
		static Tiles& shared(const std::string& filename="") ;
		void load(const std::string& filename);
		std::size_t maxLand() const ;
		std::size_t maxTile() const ;
		std::shared_ptr<Land_Tile> land(std::size_t tileid) const ;
		std::shared_ptr<Art_Tile>  art(std::size_t tileid) const ;
		
	};
}

#endif /* Tiles_hpp */
