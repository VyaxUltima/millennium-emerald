AmenoTorifune_B3F_MapScripts::
	.byte 0

AmenoTorifune_B3F_EventScript_Mario::
	trainerbattle_single TRAINER_LOLA_2, AmenoTorifune_B3F_Text_MarioIntro, AmenoTorifune_B3F_Text_MarioDefeated
	msgbox AmenoTorifune_B3F_Text_MarioPostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B3F_EventScript_Ronnie::
	trainerbattle_single TRAINER_LOLA_3, AmenoTorifune_B3F_Text_RonnieIntro, AmenoTorifune_B3F_Text_RonnieDefeated
	msgbox AmenoTorifune_B3F_Text_RonniePostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B3F_EventScript_Raycorra::
	trainerbattle_single TRAINER_LOLA_4, AmenoTorifune_B3F_Text_RaycorraIntro, AmenoTorifune_B3F_Text_RaycorraDefeated
	msgbox AmenoTorifune_B3F_Text_RaycorraPostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B3F_EventScript_Zed::
	trainerbattle_single TRAINER_LOLA_5, AmenoTorifune_B3F_Text_ZedIntro, AmenoTorifune_B3F_Text_ZedDefeated
	msgbox AmenoTorifune_B3F_Text_ZedPostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B3F_EventScript_FindMentalHerb::
	finditem ITEM_MENTAL_HERB
	end

@ I FUCKING LOVE TEXT RAHHHHHHHH

AmenoTorifune_B3F_Text_MarioIntro:
	.string "Can you read?$"

AmenoTorifune_B3F_Text_MarioDefeated:
	.string "Cannot believe that Ditto\n"
	.string "lost me the fight.$"

AmenoTorifune_B3F_Text_MarioPostBattle:
	.string "We go climbing today.$"

AmenoTorifune_B3F_Text_RonnieIntro:
	.string "My name is Yoshikage Kira.\n"
	.string "I'm 33 years old.\p"
	.string "My house is in the northeast section\n"
	.string "of Morioh, where all the villas are,\l"
	.string "and I am not married.$"

AmenoTorifune_B3F_Text_RonnieDefeated:
	.string "Aw, geez, {PLAYER}, this is worse\n"
	.string "than the time I did Seals pass!$"

AmenoTorifune_B3F_Text_RonniePostBattle:
	.string "Bro, I'm sick.\p"
	.string "If this was Gen 6, I could have\n"
	.string "Mega Evolved Sceptile and won.\p"
	.string "…Huh? What is an Ice Shard?$"

AmenoTorifune_B3F_Text_RaycorraIntro:
	.string "A good Trainer should be\n"
	.string "prepared for anything.$"

AmenoTorifune_B3F_Text_RaycorraDefeated:
	.string "I guess you were prepared.$"

AmenoTorifune_B3F_Text_RaycorraPostBattle:
	.string "That would have been embarrassing\n"
	.string "if you lost.\l"
	.string "Good thing that didn't happen, right?$"

AmenoTorifune_B3F_Text_ZedIntro:
	.string "Would you like to purchase\n"
	.string "some Abyss Sharks?$"

AmenoTorifune_B3F_Text_ZedDefeated:
	.string "Good investment, I swear.$"

AmenoTorifune_B3F_Text_ZedPostBattle:
	.string "Stop asking about the next\n"
	.string "Yugioh Funny Moments.$"
