.set LOCALID_VYAX, 3

MtPyre_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_OnTransition
	.byte 0

MtPyre_Exterior_OnTransition:
	call MtPyre_Exterior_EventScript_CheckEnterFromSummit
	end

MtPyre_Exterior_EventScript_CheckEnterFromSummit::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, 12, MtPyre_Exterior_EventScript_EnterFromSummit
	return

MtPyre_Exterior_EventScript_EnterFromSummit::
	setweather WEATHER_FOG_HORIZONTAL
	return

MtPyre_Exterior_EventScript_FogTrigger::
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	end

MtPyre_Exterior_EventScript_SunTrigger::
	setweather WEATHER_SUNNY
	doweather
	end

MtPyre_Exterior_EventScript_Vyax::
	lockall
	goto_if_set FLAG_MT_PYRE_SPOKE_TO_VYAX, MtPyre_Exterior_EventScript_VyaxMiss
	msgbox MtPyre_Exterior_Text_YouSawIt, MSGBOX_DEFAULT
	closemessage
	delay 60
	faceplayer
	msgbox MtPyre_Exterior_Text_Remembrance, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_VYAX, DIR_NORTH
	waitmovement 0
	setflag FLAG_MT_PYRE_SPOKE_TO_VYAX
	releaseall
	end

MtPyre_Exterior_EventScript_VyaxMiss::
	msgbox MtPyre_Exterior_Text_MissYou, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

MtPyre_Exterior_Text_YouSawIt:
	.string "Oh, hey {PLAYER}.\p"
	.string "I guess you saw that thing\n"
	.string "in my house, right?\l"
	.string "It's a little memento of my cat.\p"
	.string "She passed away while I was still\n"
	.string "working on this thing.\p"
	.string "I wanted to have something to\n"
	.string "remember her with here.$"

MtPyre_Exterior_Text_Remembrance:
	.string "Ha. Sorry. You're playing this to\n"
	.string "have fun, and I drop that on you.\l"
	.string "I'll stop being a downer.\p"
	.string "Get going. You've still got a\n"
	.string "lot of this left to play!$"

MtPyre_Exterior_Text_MissYou:
	.string "I'll miss you.$"

