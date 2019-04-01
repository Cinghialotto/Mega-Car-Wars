/***********************************************************

 MEGA CAR WARS

 SCENARIO.H
***********************************************************/
#ifndef _SCENARIO_H_
#define _SCENARIO_H_

// SGDK LIBS //////////////////////////////////////////////
#include "genesis.h"

// LIBS ///////////////////////////////////////////////////


// ASSETS /////////////////////////////////////////////////
#include "gfx.h"


// CONSTANT ///////////////////////////////////////////////
#define SCREEN_WIDTH_TILES     40
#define SCREEEN_HEIGHT_TILES   28

#define SCENARIO_VRAM_POS     		10
#define SCENARIO_BPLAN_VRAM_POS		SCENARIO_VRAM_POS
#define SCENARIO_APLAN_VRAM_POS		SCENARIO_VRAM_POS + scenario.btileset->numTile

#define SCENARIO_POS_X          0
#define SCENARIO_POS_Y          0

#define SCENARIO_WIDTH_TILES 		60
#define SCENARIO_HEIGHT_TILES 		70
#define SCENARIO_NUM_TILES 			SCENARIO_WIDTH_TILES * SCENARIO_HEIGHT_TILES

#define SCENARIO_ISOMETRIC_WIDTH_TILES    520
#define SCENARIO_ISOMETRIC_HEIGHT_TILES   260
#define SCENARIO_ISOMETRIC_NUM_TILES      SCENARIO_ISOMETRIC_WIDTH_TILES * SCENARIO_ISOMETRIC_HEIGHT_TILES

#define SCENARIO_DEFAULT_PAL	PAL0

#define SCENARIO_MAX			3

#define SCENARIO_ID_CIRCUIT		0
#define SCENARIO_ID_DESERT		1
#define SCENARIO_ID_SNOWY		2

#define SCENARIO_FIRST			SCENARIO_ID_CIRCUIT


// STRUCTS ////////////////////////////////////////////////

// Scenario definition
struct t_scenario_def
{
	const Image *bga;
	const Image *bgb;
	const Image *prioritymap;
	const Image *hardnessmap;

	u16 startx, starty;

	void (*routine)(u8); // Optional extra routine
};

// Scenario handler
struct t_scenario_data
{
	u8 current; // current scenario id/index

	Palette *palette;

	Map *amap;
	Map *bmap;

	TileSet *atileset;
	TileSet *btileset;

	u8 hardnessmap[SCENARIO_NUM_TILES];
};

// DATA ///////////////////////////////////////////////////

// Definitions
extern const struct t_scenario_def scenarios[SCENARIO_MAX];

// Handler
extern struct t_scenario_data scenario;


// MACROS /////////////////////////////////////////////////
#define Scenario_setPalette(); \
	VDP_setPalette(SCENARIO_DEFAULT_PAL, (u16*) scenario.palette->data);

#define Scenario_loadTileset(); \
	VDP_loadTileSet(scenario.btileset, SCENARIO_BPLAN_VRAM_POS, TRUE); \
	VDP_loadTileSet(scenario.atileset, SCENARIO_APLAN_VRAM_POS, TRUE);

#define Scenario_setCurrent(id); scenario.current = (id);


// FUNCTIONS //////////////////////////////////////////////

void Scenario_loadMaps(u8);
void Scenario_load(u8);
void Scenario_setRegion(u16, u16, u16, u16, u8, u8);


#endif // _SCENARIO_H_
