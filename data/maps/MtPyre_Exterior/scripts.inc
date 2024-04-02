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
	.string "………\p"
	.string "Hey.\p"
	.string "………\p"
	.string "I guess you saw that thing\n"
	.string "in my house, right?\l"
	.string "That's a memory of my cat, Lily.\p"
	.string "She passed away about a month\n"
	.string "before this project was completed.$"

MtPyre_Exterior_Text_Remembrance:
	.string "Lily was around for half my life.\p"
	.string "I knew losing her would hurt,\n"
	.string "but the end came so suddenly.\p"
	.string "………\p"
	.string "There are two things that bring me\n"
	.string "a little peace of mind.\p"
	.string "The first is that she didn't have to\n"
	.string "suffer in the time she had left.\l"
	.string "I made sure that didn't happen.\p"
	.string "The second is that I made this hack.\n"
	.string "With help, of course.\l"
	.string "But making a hack like this…\p"
	.string "It means I can put a reminder here.\p"
	.string "The memories that I had of her\n"
	.string "can now include this project, too.\p"
	.string "………\p"
	.string "Ha. Sorry. You're playing this to\n"
	.string "have fun, and I go say all this.\p"
	.string "Get going. You've still got a\n"
	.string "lot of hack left to play!$"

MtPyre_Exterior_Text_MissYou:
	.string "I'll miss you.$"

