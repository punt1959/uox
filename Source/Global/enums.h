// 
// Created on:  6/3/21

#ifndef enums_h
#define enums_h

//=============================================================================
// Language types
enum class Language {
	unknown =0,
	standard,
	english,
	german,
	spanish,
	french,
	japanese
};

//=============================================================================
// unicode types
enum class UnicodeType {
	zero=0,
	ara,
	ari,
	are,
	arl,
	arg,
	arm,
	art,
	aro,
	ary,
	ars,
	arj,
	arb,
	ark,
	aru,
	arh,
	arq,
	bgr,
	cat,
	cht,
	chs,
	zhh,
	zhi,
	zhm,
	csy,
	dan,
	deu,
	des,
	dea,
	del,
	dec,
	ell,
	enu,
	eng,
	ena,
	enc,
	enz,
	eni,
	ens,
	enj,
	enb,
	enl,
	ent,
	enw,
	enp,
	esp,
	sem,
	esn,
	esg,
	esc,
	esa,
	esd,
	esv,
	eso,
	esr,
	ess,
	esf,
	esl,
	esy,
	esz,
	esb,
	ese,
	esh,
	esi,
	esu,
	fin,
	fra,
	frb,
	frc,
	frs,
	frl,
	frm,
	heb,
	hun,
	isl,
	ita,
	its,
	jpn,
	kor,
	nld,
	nlb,
	nor,
	non,
	plk,
	ptb,
	ptg,
	rom,
	rus,
	hrv,
	srl,
	srb,
	sky,
	sqi,
	sve,
	svf,
	tha,
	trk,
	urp,
	ind,
	ukr,
	bel,
	slv,
	eti,
	lvi,
	lth,
	ltc,
	far,
	vit,
	hye,
	aze,
	euq,
	mki,
	afk,
	kat,
	fos,
	hin,
	msl,
	msb,
	kaz,
	swk,
	uzb,
	tat,
	ben,
	pan,
	guj,
	ori,
	tam,
	tel,
	kan,
	mal,
	Asm,				// Uppercase for asm is an intrinsic
	mar,
	san,
	kok
};
//============================================================================
// Speech types
struct SpeechType {
	static constexpr int unknown 	= -1;
	static constexpr int talk 	= 0;			// normal system message
	static constexpr int prompt 	= 1;			// Display as system prompt
	static constexpr int emote 	= 2;			// : text
	static constexpr int say 	= 3;			// character speaking
	static constexpr int obj	= 4;			// at object
	static constexpr int nothing	= 5;			// does not display
	static constexpr int system	= 6;			// text labelling an item
	static constexpr int noscroll	= 7;			// status message does not scroll
	static constexpr int whisper	= 8;			// only those close can hear
	static constexpr int yell	= 9;			// can be heard 2 screens away
	static constexpr int ascii	= 0xC0;		// ASCII version, all asci is ascii | type
};

//============================================================================
// Layers
// Do not change order, the values have meaning
enum class LayerType {
	none = 0 ,
	handRight,
	handLeft,
	footwear,
	pants,
	shirtInner,
	helment,
	gloves,
	ring,
	tailsman,
	neck,
	hair,
	wasit,
	tunic,
	bracelet,
	face,
	beard,
	shirtOuter,
	earrings,
	arms,
	cloak,
	packItem,
	robe,
	leggingsOuter,
	leggingsInner,
	mount,
	containerSell,
	containerBought,
	containerBuy,
	containerBank
};
//==============================================================================
enum class FontType {
	null = -1 ,
	bold = 0,
	text_with_shadow,
	bold_plus_shadow,
	normal,
	gothic,
	italic,
	small_dark,
	colorful,
	runic,			// Only use CAPS
	small_light,
	unknown
};

//==============================================================================
// Pickup locations
enum class PickupLocation {
	nowhere = 0,
	ground ,
	ownPack,
	otherPack,
	paperdoll,
	bank
};
//==============================================================================
// Weather types
enum class WeatherType {
	none = 0,
	physical,
	light,
	rain,
	cold,
	heat,
	lightining,
	poison,
	snow,
	storm,
	stormbrew
};
//=============================================================================
// World Types
enum class WorldType {
	spring = 0,
	summer,
	autumn,
	winter,
	desolation,
	unknown
};

//=============================================================================
enum class SkillType {
	alchemy,
	anatomy,
	animallore,
	itemid,
	armslore,
	parrying,
	begging,
	blacksmithing,
	bowcraft,
	peacemaking,
	camping,
	carpentry,
	cartography,
	cooking,
	detecthidden,
	enticement,
	evaluateintel,
	healing,
	fishing,
	forensic,
	herding,
	provocation,
	inscription,
	lockpicking,
	magery,
	magicresistance,
	tatics,
	snooping,
	musicianship,
	poisoning,
	archery,
	spiritspeak,
	stealing,
	tailoring,
	taming,
	tasteid,
	tinkering,
	tracking,
	veterinary,
	swordsmanship,
	macefighting,
	fencing,
	wrestling,
	lumberjacking,
	mining,
	meditation,
	stealth,
	removetraps,
	necromancy,
	focus,
	chivalry,
	bushido,
	ninjitsu,
	spellweaving,
	imbuing,
	mysticism,
	throwing
};
// =============================================================================
// Skill lock
enum class SKillLock {
	increase = 0 ,
	decrease,
	locked
};
// =============================================================================
// Object Types
enum class ObjectType {
	invalid = 0,
	character,
	item,
	multi,
	boat,
	spawner
};
//=============================================================================
enum class CommandLevel {
	player = 0,
	counsler,
	gm,
	admin
};
//=============================================================================
enum class AIType {
	none			= 0,
	goodHealer		= 1,
	evil			= 2,
	guard			= 3,
	fighter		= 4,
	animal		= 6,
	passive		= 7,
	banker		= 8,
	playerVendor	= 17,
	guardPet		= 32,
	chaotic		= 88,
	evilHealer		= 666
};
//==============================================================================
// Distances
enum class DistanceType {
	sameTile = 1,
	nextTile,
	nearby,
	inRange=7,
	sameScreen = 24, // 24 is max in clients (enhanced/classic) v7.0.55.27 and beyond, and in ClassicUO
	buildRange = 31,
	outOfRange = 0xffff
};

//==============================================================================
// Item types
enum class ItemType {
	notype			= 0,
	container			= 1,
	castleGateOpener		= 2,
	castleGate			= 3,
	teleportItem		= 6,
	key				= 7,
	lockedContainer		= 8,
	spellBook			= 9,
	map				= 10,
	book				= 11,
	door				= 12,
	lockedDoor			= 13,
	food				= 14,
	wandMagic			= 15,
	resurrectObject		= 16,
	crystalBall			= 18,
	potion			= 19,
	tradeWindow			= 20,
	townStone			= 35,
	recallRune			= 50,
	gate				= 51,
	teleporterObject		= 60,
	spawnerItem			= 61,
	spawnerNPC			= 62,
	spawnContainer		= 63,
	spawnLockedContainer	= 64,
	spawnUnlockableContainer= 65,
	spawnArea			= 69,
	gateAdvance			= 80,
	gateMultiAdvance		= 81,
	gateMonstor			= 82,
	gateRace			= 83,
	damageObject		= 85,
	trashContainer		= 87,
	soundObject			= 88,
	changeMapObject		= 89,
	changeWorldObject		= 90,
	morphObject			= 101,
	unmorphObject		= 102,
	drink				= 105,
	standingHarp		= 106,
	gateZeroKill		= 111,
	plank				= 117,
	wandFireworks		= 118,
	spawnEscort			= 125,
	deedRename			= 186,
	toolLeather			= 190,
	toolBow			= 191,
	tiller			= 200,
	houseAddon			= 201,
	stoneGuild			= 202,
	houseSign			= 203,
	toolTinker			= 204,
	toolMetal			= 205,
	forge				= 207,
	dye				= 208,
	dyeVat			= 209,
	modelMulti			= 210,
	archeryBUtte		= 211,
	drum				= 212,
	tambourine			= 213,
	harp				= 214,
	lute				= 215,
	axe				= 216,
	playerVendorDeed		= 217,
	toolSmithy			= 218,
	toolCarpentry		= 219,
	toolMining			= 220,
	vialEmpty			= 221,
	fabricUnspun		= 222,
	fishUncooked		= 223,
	meatUncooked		= 224,
	fabricSpun			= 225,
	toolFletching		= 226,
	cannonball			= 227,
	pitcherWater		= 228,
	doughUncooked		= 229,
	sewingkit			= 230,
	ore				= 231,
	messageboard		= 232,
	sword				= 233,
	camping			= 234,
	statueMagic			= 235,
	guillotine			= 236,
	sackFlour			= 238,
	sackFlourOpen		= 239,
	poleFishing			= 240,
	clock				= 241,
	mortar			= 242,
	scissors			= 243,
	bandage			= 244,
	sextant			= 245,
	hairdye			= 246,
	lockpick			= 247,
	plantCotton			= 248,
	tinkerAxle			= 249,
	tinkerAwg			= 250,
	tinkerClock			= 251,
	tinkerSextant		= 252,
	trainingDummy		= 253
};

//==============================================================================
// Target types
enum class TargetType {
	npcAddScript = 0 ,
	teleport,
	dye,
	key,
	repairMetal,
	dyeAll,
	dyeVat,
	freeze,
	unfreeze,
	itemid,
	fish,
	info,
	townAlly,
	smith,
	mine,
	smeltOre,
	stats,
	npcRessurect,
	tweak,
	makeStatus,
	setScriptTrigger,
	castSpell,
	follow,
	attack,
	transfer,
	guard,
	restock,
	playerFriend,
	vote,
	vial,
	tiling,
	steal,
	buy,
	houseOwner,
	houseEject,
	houseBan,
	houseFriend,
	houseUnlist,
	houseLockDown,
	houseRelease,
	houseSecure,
	smelt,
	showSkills,
	houseBuild,
	partyAdd,
	partyRemove,
	houseTrash,
	houseStrongBox,
	nofunction
};

//============================================================================
enum class VisibleType {
	visible=0, 			// Visible to All
	hiddenTemp,			// Hidden (With Skill) / Visible To Item Owner
	invisible,			// Magically Hidden
	hiddenPermanent,		// Permanent Hidden (GM Hidden)
	hiddenGhost			// Hidden because the player is a ghost
};

//============================================================================
enum class FlagType {
	innocent	= 1,
	ally,
	neutral,
	criminal,
	enemy,
	murderer,
	invulnerable
};

//============================================================================
enum class BoatMoveType {
	anchored = -1,
	stop,
	forward,
	backward,
	left,
	right,
	forwardLeft,
	forwardRight,
	backwardLeft,
	backwardRight,
	leftSlow,
	rightSlow,
	backwardSlow,
	forwardLeftSlow,
	forwardRightSlot,
	backwardRightSlow,
	backwardLeftSlow,
	leftOne,
	rightOne,
	foerwardOne,
	backwardOne,
	fowardLeftOne,
	forwardRightOne,
	backwardLeftOne,
	backwardRightOne
	
};

//============================================================================
enum class RaceRelationType {
	enemy = -1,
	neutral,
	ally
};

//============================================================================
enum class BodyType {
	human = 0,
	elf,
	gargoyle,
	other
};

//=============================================================================
enum class ActionType {
	walkUnarmed = 0 ,
	// Humans,elves
	walkArmed,			// Walk with items equipped, while not in war mode
	runUnarmed,			// Run without items equipped in hands
	runArmed,			// Run with items equipped in hands
	idle,				// Stand around idle
	idleLook,			// Idle, looking around
	idleYawn,			// Idle, yawning
	idleCombat1H,		// Idle, in combat, with 1H weapon equipped
	idleCombat2H,		// Idle, in combat, with 2H weapon equipped
	attackSlash1H,		// Swing using 1H blade weapon
	attackPierce1H,		// Stab using 1H piercing weapon
	attackBash1H,		// Bash using 1H mace weapon
	attackBash2H,		// Bash using 2H mace weapon
	attackSlash2H,		// Swing using 2H blade weapon
	attackPierce2H,		// Stab using 2H piercing weapon
	walkCombat,			// Walk in combat mode
	spellTarget,		// Cast spell at target
	spellArea,			// Cast spell at area
	fireBow,			// Fire bow
	fireXBow,			// Fire crossbow
	impact,			// get hit
	dieBackward,		// Die backwards
	dieForward,			// Die forwards,
	block,			// block attack,evade
	attackUnarmed,		// Unarmed attack
	emoteBow,			// Bow to someone/something
	emoteSalute,		// Salute
	emoteEat,			// Eat or drink
	
	// Mounted
	mountWalk = 0x17,		// Walking while mounted
	mountRun,			// Running while mounted
	mountIdle,			// Idle while mounted
	mountAttack1H = 0x1A,	// Attacking with 1H weapon while mounted
	mountAttackBow,		// Attacking with Bow while mounted
	mountAttackXBow,		// Attacking with Crossbow while mounted
	mountAttack2H		// Attacking with 2H weapon while mounted
};

//=============================================================================
enum class MonstorAction {
	walk = 0,
	idle,
	dieBackward,
	dieForward,
	attackNormal,		// Attack variation 1 - ALL creatures have at least this attack
	attack2,			// Attack variation 2 - swimming monsteers don't have this
	attack3,
	attackFlail,		// Attack variation 4 - air/fire elem = flail arms
	attackRoll,			// Attack variation 5 - Misc Roll over
	attackThrow,		// Attack variation 6 - Throw
	impact,			// Get hit animation
	pillage,			// 11 = Misc, Stomp, slap ground, lich conjure
	cast1,			// Spellcast variation 1 - Misc cast, breath fire, elem creation
	cast2,			// Spellcast variation 2 - Trolls don't have this anim
	cast3,			// Spellcast variation 3
	blockRight,
	blockLeft,
	idle1,
	idle2,
	fly,				// Take off
	land,				// land
	dieFlight			// die in flight
};

//=============================================================================
enum class AnimalAction {
	walk = 0,
	run,
	idle,
	eat,
	alert,
	attack1,
	attack2,
	impact,
	die1,
	idle1,
	idle2,
	sleep,			// Lie down and sleep (not all animals have this)
	die2
};

//=============================================================================
// v7.0.0.0+
enum class NewActionType {
	attack = 0, 		// Variations listed under SubActionsAttack enum
	block,
	block2,
	die,				// Variations listed under SubActionsDeath enum
	impact,
	idle,				// One variation available (shuffle feet) with subSubAction of 0x01?
	eat,
	emote,			 // Variations listed under SubActionsEmote enum
	anger,
	takeoff,
	land,
	spell,			// Variations listed under SubActionsSpells enum
	unknown1,			// Enhanced Client only?
	unknown2,			// Enhanced Client only?
	pillage,			// Eat, pillage
	rise				// Used for character creation in Enhanced Client
};

//=============================================================================
enum class AttackActionSubType {
	wrestle,
	bow,
	crossbow,
	bash1h,
	slash1h,
	pierce1h,
	bash2h,
	slash2h,
	pierce2h,
	fling
};

//=============================================================================
enum class DeathActionSubType {
	forward = 0,
	backward
};

//=============================================================================
enum class EmoteActionSubType {
	bow = 0,
	salute
};

//=============================================================================
enum class SpellAtionSubType {
	target = 0,
	area
};

#endif /* enums_h */
