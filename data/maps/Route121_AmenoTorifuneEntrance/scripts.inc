Route121_AmenoTorifuneEntrance_MapScripts::
	.byte 0

Route121_AmenoTorifuneEntrance_Scientist1::
	msgbox Route121_AmenoTorifuneEntrance_TextReadings, MSGBOX_NPC
	end

Route121_AmenoTorifuneEntrance_Scientist2::
	msgbox Route121_AmenoTorifuneEntrance_TextMonitoring, MSGBOX_NPC
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

