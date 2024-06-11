SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "Who are you?\n"
	.string "Where did you come in from?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Lost it…$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "You followed us in, huh?\p"
	.string "Didn't consider that.$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Who are you?\n"
	.string "Where do you think you're going?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "I failed to win!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "My partner forgot the map in that\n"
	.string "submarine!\p"
	.string "How's that for being useless?$"

