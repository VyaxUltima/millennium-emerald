Route121_AmenoTorifuneEntrance_MapScripts::
	.byte 0

Route121_AmenoTorifuneEntrance_Scientist1::
	msgbox Route121_AmenoTorifuneEntrance_TextReadings, MSGBOX_NPC
	end

Route121_AmenoTorifuneEntrance_Scientist2::
	msgbox Route121_AmenoTorifuneEntrance_TextMonitoring, MSGBOX_NPC
	end

Route121_AmenoTorifuneEntrance_HealerMan::
	lock
	faceplayer
	msgbox Route121_AmenoTorifuneEntrance_Text_RestUpHere, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route121_AmenoTorifuneEntrance_Text_GoodToGo, MSGBOX_DEFAULT
	release
	end

Route121_AmenoTorifuneEntrance_TextReadings:
	.string "There's a cavern underneath here.\p"
	.string "We've been keeping an eye on\n"
	.string "activity down there for a while.\p"
	.string "Recently, we've made a discovery\n"
	.string "of a strong presence down below.\p"
	.string "That has attracted some Trainers\n"
	.string "who are quite skilled.\p"
	.string "If you intend to go down there,\n"
	.string "you should prepare adequately.$"

Route121_AmenoTorifuneEntrance_TextMonitoring:
	.string "There's normally very little\n"
	.string "activity in this space.\p"
	.string "However, talks of a legendary\n"
	.string "Pokémon being here has roused\l"
	.string "some interest once again.$"

Route121_AmenoTorifuneEntrance_Text_RestUpHere:
	.string "I can recover your party's strength.\n"
	.string "Here, let me handle it.$"

Route121_AmenoTorifuneEntrance_Text_GoodToGo:
	.string "You're good to go!$"

