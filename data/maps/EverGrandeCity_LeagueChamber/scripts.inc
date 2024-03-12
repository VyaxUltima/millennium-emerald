EverGrandeCity_LeagueChamber_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_LeagueChamber_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_LeagueChamber_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_LeagueChamber_OnTransition
	.byte 0

EverGrandeCity_LeagueChamber_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_LeagueChamber_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_LeagueChamber_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_LeagueChamber_OnTransition:
	setvar VAR_ELITE_4_STATE, 0
	end

EverGrandeCity_LeagueChamber_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_LeagueChamber_CloseDuckieDoor
	call_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_LeagueChamber_CloseBakuraDoor
	call_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_LeagueChamber_CloseMuttDoor
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_LeagueChamber_CloseRefisioDoor
	end

EverGrandeCity_LeagueChamber_CloseDuckieDoor:
	setmetatile 3, 3, 0x202, TRUE
	setmetatile 3, 4, 0x20A, TRUE
	special DrawWholeMapView
	return

EverGrandeCity_LeagueChamber_CloseBakuraDoor:
	setmetatile 10, 2, 0x202, TRUE
	setmetatile 10, 3, 0x20A, TRUE
	special DrawWholeMapView
	return
	
EverGrandeCity_LeagueChamber_CloseMuttDoor:
	setmetatile 18, 2, 0x202, TRUE
	setmetatile 18, 3, 0x20A, TRUE
	special DrawWholeMapView
	return
	
EverGrandeCity_LeagueChamber_CloseRefisioDoor:
	setmetatile 25, 3, 0x202, TRUE
	setmetatile 25, 4, 0x20A, TRUE
	special DrawWholeMapView
	return

EverGrandeCity_LeagueChamber_OpenChampionDoor::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	playse SE_DOOR
	setmetatile 13, 5, METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 13, 6, METATILE_EliteFour_OpenDoor_Opening, FALSE
	setmetatile 14, 5, METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 14, 6, METATILE_EliteFour_OpenDoor_Opening, FALSE
	setmetatile 15, 5, METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 15, 6, METATILE_EliteFour_OpenDoor_Opening, FALSE
	special DrawWholeMapView
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	msgbox EverGrandeCity_LeagueChamber_ItsTimeText, MSGBOX_DEFAULT
	setvar VAR_ELITE_4_ROOMS_CLEARED, 5
	release
	end

EverGrandeCity_LeagueChamber_EnterDuckieRoom::
	lock
	msgbox EverGrandeCity_LeagueChamber_DuckieRoomText, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ELITE_4_DUCKIE_ROOM, 1
	release
	end

EverGrandeCity_LeagueChamber_EnterBakuraRoom::
	lock
	msgbox EverGrandeCity_LeagueChamber_BakuraRoomText, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ELITE_4_BAKURA_ROOM, 1
	release
	end

EverGrandeCity_LeagueChamber_EnterMuttRoom::
	lock
	msgbox EverGrandeCity_LeagueChamber_MuttRoomText, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ELITE_4_MUTT_ROOM, 1
	release
	end

EverGrandeCity_LeagueChamber_EnterRefisioRoom::
	lock
	msgbox EverGrandeCity_LeagueChamber_RefisioRoomText, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ELITE_4_REFISIO_ROOM, 1
	release
	end

EverGrandeCity_LeagueChamber_DuckieRoomText:
	.string "You feel heat waves cut through\n"
	.string "permafrost. You can smell gunpowder.\p"
	.string "If you're ready for what awaits you,\n"
	.string "then step inside.$"

EverGrandeCity_LeagueChamber_BakuraRoomText:
	.string "You see sand. It's coarse. It's rough.\n"
	.string "And it's fucking everywhere.\p"
	.string "If you're ready for what awaits you,\n"
	.string "then step inside.$"

EverGrandeCity_LeagueChamber_MuttRoomText:
	.string "Muttma\n"
	.string "balls lmao\p"
	.string "If you're ready for what awaits you,\n"
	.string "then step inside.$"

EverGrandeCity_LeagueChamber_RefisioRoomText:
	.string "You hear internalized screams.\n"
	.string "A thud can be heard on the downbeat.\p"
	.string "If you're ready for what awaits you,\n"
	.string "then step inside.$"

EverGrandeCity_LeagueChamber_ItsTimeText:
	.string "You've beaten all but one.\n"
	.string "The final door's open now.\p"
	.string "No turning back.$"

