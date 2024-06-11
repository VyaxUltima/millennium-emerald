PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE
	setmetatile 0, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 1, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 2, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 3, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 4, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 8, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 9, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 10, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 11, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 12, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	special DrawWholeMapView
	return

PokemonLeague_EliteFour_EventScript_WalkInCloseDoor::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp6
	waitmovement 0
	playse SE_TRUCK_DOOR
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	special DrawWholeMapView
	return

@ Essentially unused, only necessary when re-entering an Elite Four room after defeating the member, which isnt normally possible
PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom::
	setmetatile 6, 1, METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 0, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 1, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 2, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 3, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 4, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 8, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 9, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 10, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	setmetatile 11, 2, METATILE_EliteFour_RightSpotlightOff, TRUE
	setmetatile 12, 2, METATILE_EliteFour_LeftSpotlightOff, TRUE
	return

PokemonLeague_EliteFour_EventScript_CloseDoor::
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, TRUE
	return

@ new scripts to accommodate maps

@ Duckie's Room
PokemonLeague_EliteFourSidney_EventScript_CloseDoor::
	setmetatile 5, 12, METATILE_Duckie_EntryDoor_ClosedTop, TRUE
	setmetatile 6, 12, METATILE_Duckie_EntryDoor_ClosedTop, TRUE
	setmetatile 7, 12, METATILE_Duckie_EntryDoor_ClosedTop, TRUE
	setmetatile 5, 13, METATILE_Duckie_EntryDoor_ClosedBottom, TRUE
	setmetatile 6, 13, METATILE_Duckie_EntryDoor_ClosedBottom, TRUE
	setmetatile 7, 13, METATILE_Duckie_EntryDoor_ClosedBottom, TRUE
	return

PokemonLeague_EliteFourSidney_EventScript_WalkInCloseDoor::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp6
	waitmovement 0
	playse SE_TRUCK_DOOR
	setmetatile 5, 12, METATILE_Duckie_EntryDoor_ClosedTop, TRUE
	setmetatile 6, 12, METATILE_Duckie_EntryDoor_ClosedTop, TRUE
	setmetatile 7, 12, METATILE_Duckie_EntryDoor_ClosedTop, TRUE
	setmetatile 5, 13, METATILE_Duckie_EntryDoor_ClosedBottom, TRUE
	setmetatile 6, 13, METATILE_Duckie_EntryDoor_ClosedBottom, TRUE
	setmetatile 7, 13, METATILE_Duckie_EntryDoor_ClosedBottom, TRUE
	special DrawWholeMapView
	return

PokemonLeague_EliteFourSidney_SetAdvanceToNextRoomMetatiles::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	playse SE_DOOR
	setmetatile 6, 1, METATILE_Duckie_OpenDoor_Frame, FALSE
	setmetatile 6, 2, METATILE_Duckie_OpenDoor_Opening, FALSE
	special DrawWholeMapView
	return

@ Bakura's Room
PokemonLeague_EliteFourPhoebe_EventScript_CloseDoor::
	setmetatile 5, 12, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 6, 12, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 7, 12, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 5, 13, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 6, 13, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 7, 13, METATILE_Lavaridge_RockWall, TRUE
	return

PokemonLeague_EliteFourPhoebe_EventScript_WalkInCloseDoor::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp6
	waitmovement 0
	playse SE_TRUCK_DOOR
	setmetatile 5, 12, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 6, 12, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 7, 12, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 5, 13, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 6, 13, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 7, 13, METATILE_Lavaridge_RockWall, TRUE
	special DrawWholeMapView
	return

PokemonLeague_EliteFourPhoebe_SetAdvanceToNextRoomMetatiles::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	playse SE_DOOR
	setmetatile 6, 1, METATILE_Lavaridge_CaveEntrance_Top, FALSE
	setmetatile 6, 2, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	return

@ Mutt's Room
PokemonLeague_EliteFourGlacia_EventScript_CloseDoor::
	setmetatile 5, 12, METATILE_Mutt_EntryDoor_ClosedTop, TRUE
	setmetatile 6, 12, METATILE_Mutt_EntryDoor_ClosedTop, TRUE
	setmetatile 7, 12, METATILE_Mutt_EntryDoor_ClosedTop, TRUE
	setmetatile 5, 13, METATILE_Mutt_EntryDoor_ClosedBottom, TRUE
	setmetatile 6, 13, METATILE_Mutt_EntryDoor_ClosedBottom, TRUE
	setmetatile 7, 13, METATILE_Mutt_EntryDoor_ClosedBottom, TRUE
	return

PokemonLeague_EliteFourGlacia_EventScript_WalkInCloseDoor::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp3
	waitmovement 0
	playse SE_TRUCK_DOOR
	setmetatile 5, 12, METATILE_Mutt_EntryDoor_ClosedTop, TRUE
	setmetatile 6, 12, METATILE_Mutt_EntryDoor_ClosedTop, TRUE
	setmetatile 7, 12, METATILE_Mutt_EntryDoor_ClosedTop, TRUE
	setmetatile 5, 13, METATILE_Mutt_EntryDoor_ClosedBottom, TRUE
	setmetatile 6, 13, METATILE_Mutt_EntryDoor_ClosedBottom, TRUE
	setmetatile 7, 13, METATILE_Mutt_EntryDoor_ClosedBottom, TRUE
	special DrawWholeMapView
	return

PokemonLeague_EliteFourGlacia_SetAdvanceToNextRoomMetatiles::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	playse SE_DOOR
	setmetatile 6, 2, METATILE_Mutt_OpenDoor_Frame, FALSE
	setmetatile 6, 3, METATILE_Mutt_OpenDoor_Opening, FALSE
	special DrawWholeMapView
	return

@ Ref's Room
PokemonLeague_EliteFourDrake_EventScript_CloseDoor::
	return

PokemonLeague_EliteFourDrake_EventScript_WalkInCloseDoor::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp3
	waitmovement 0
	return

PokemonLeague_EliteFourDrake_SetAdvanceToNextRoomMetatiles::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	playse SE_DOOR
	setmetatile 4, 0, METATILE_Ref_OpenDoor_Frame, FALSE
	setmetatile 4, 1, METATILE_Ref_OpenDoor_Opening, FALSE
	special DrawWholeMapView
	return

