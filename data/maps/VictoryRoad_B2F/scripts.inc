VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "Oh no, it's the beginning of\n"
	.string "the end.$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Played like my braincells were gone.$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "It's all prep. CARALHO$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "I'd heard that there was a tough\n"
	.string "Trainer around. Do they mean you?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "The gamer is tough!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "The rumors I heard, that tough gamer\n"
	.string "topped the Petalburg YCS.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "You must be getting a little tired.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Even after 12 rounds?$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "Drink water.$"

VictoryRoad_B2F_Text_JulieIntro: @Fyre
	.string "Yes I stole sets from Smogon and\n"
	.string "modified them. Muhahah$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "I dot pixels good.$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Tell Vyax to get me a drink,\n"
	.string "when you see him.$"

VictoryRoad_B2F_Text_FelixIntro: @soulsrep
	.string "I tried to make it as dumb\n"
	.string "as possible.$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "It's Finger, yes.$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "Glad I found a romhack that\n"
	.string "appreciates Joseph Biden.$"

VictoryRoad_B2F_Text_DianneIntro: @ant
	.string "Would you like to see my collection\n"
	.string "of little guys?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Nooo, Springtrap!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "I draw little guys and rats.$"

