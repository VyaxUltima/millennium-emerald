EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFourDrake_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 1, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFourDrake_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	addvar VAR_ELITE_4_ROOMS_CLEARED, 1
	call PokemonLeague_EliteFourDrake_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech:
	.string "Yo. I'm Refisio.\n"
	.string "I made the maps for the game.\p"
	.string "Skarlon's gym was a NIGHTMARE,\n"
	.string "lemme tell ya.\p"
	.string "Still don't think I got it right on the\n"
	.string "perspective for Duelist Kingdom, but\l"
	.string "whooshing deadlines and all that.\p"
	.string "…But I guess you're not here\n"
	.string "to discuss map-making.\p"
	.string "sigh\p"
	.string "Just once, JUST. ONCE.\n"
	.string "I would love it if someone talked\l"
	.string "about the FUCKING MAPS.\p"
	.string "I PUT HARD WORK INTO THEM, BUT\n"
	.string "Y'ALL JUST WANT TO BATTLE.\l"
	.string "BATTLE BATTLE BATTLE BATTLE.\p"
	.string "Fine. You want a battle?\n"
	.string "Then you'll get a battle.\p"
	.string "COME ON, BITCH.\n"
	.string "SHOW ME WHAT YOU LOVE!$"

EverGrandeCity_DrakesRoom_Text_Defeat:
	.string "Ach… Hervorragend.$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
	.string "So long, farewell.\n"
	.string "Auf Wiedersehen, goodbye.\p"
	.string "I leave… and heave…\n"
	.string "a sigh and say goodbye…\p"
	.string "…I need a drink.$"

