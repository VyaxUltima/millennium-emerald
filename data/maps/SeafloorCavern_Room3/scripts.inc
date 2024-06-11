SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Ah, hello again.\p"
	.string "How did you manage to get here without\n"
	.string "a submarine?\p"
	.string "…Mm, right. We forgot about HMs.\p"
	.string "No big deal. This time, I have\n"
	.string "the ultimate spreadsheet.\p"
	.string "And, I do want payback for what\n"
	.string "happened at the Weather Institute.\p"
	.string "Though, even if I lose, it would\n"
	.string "work out just fine.\p"
	.string "Now, let me demonstrate why I am\n"
	.string "the one true Twitch mod.$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Failed to resolve Danger Mathman.$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Like I said before, it's fine\n"
	.string "if I lose to you.\p"
	.string "After all, everything that Archie\n"
	.string "needed is already in place.\p"
	.string "It's time for the funny Joel.$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "For our dream to become real, we need\n"
	.string "the power of big Joel….\p"
	.string "But meddlers like you use the power of\n"
	.string "Pokémon to mess with us even at\l"
	.string "a place like this!\p"
	.string "Life just doesn't work the way we\n"
	.string "need it to!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Gwah!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "You know, we don't dare question\n"
	.string "the motives of the Joel Fanclub.\p"
	.string "But here you are, just some punk,\n"
	.string "going up against our streamer.\p"
	.string "Maybe…\n"
	.string "You must be something…$"

