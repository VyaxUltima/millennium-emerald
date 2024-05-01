AmenoTorifune_B2F_MapScripts::
	.byte 0

AmenoTorifune_B2F_EventScript_Luck::
	trainerbattle_single TRAINER_ANDRES_5, AmenoTorifune_B2F_Text_LuckIntro, AmenoTorifune_B2F_Text_LuckDefeated
	msgbox AmenoTorifune_B2F_Text_LuckPostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B2F_EventScript_KMR::
	trainerbattle_single TRAINER_DUSTY_2, AmenoTorifune_B2F_Text_KMRIntro, AmenoTorifune_B2F_Text_KMRDefeated
	msgbox AmenoTorifune_B2F_Text_KMRPostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B2F_EventScript_Lemon::
	trainerbattle_single TRAINER_DUSTY_3, AmenoTorifune_B2F_Text_LemonIntro, AmenoTorifune_B2F_Text_LemonDefeated
	msgbox AmenoTorifune_B2F_Text_LemonPostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B2F_EventScript_Annie::
	trainerbattle_single TRAINER_DUSTY_4, AmenoTorifune_B2F_Text_AnnieIntro, AmenoTorifune_B2F_Text_AnnieDefeated
	msgbox AmenoTorifune_B2F_Text_AnniePostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B2F_EventScript_Mili::
	trainerbattle_single TRAINER_DUSTY_5, AmenoTorifune_B2F_Text_MiliIntro, AmenoTorifune_B2F_Text_MiliDefeated
	msgbox AmenoTorifune_B2F_Text_MiliPostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B2F_EventScript_FindWhiteHerb::
	finditem ITEM_WHITE_HERB
	end

@ I FUCKING LOVE TEXT RAHHHHHHHH

AmenoTorifune_B2F_Text_LuckIntro:
	.string "yap yap yap yap\n"
	.string "yap yap yap yap$"

AmenoTorifune_B2F_Text_LuckDefeated:
	.string "yap yap yap yap\n"
	.string "yap yap yap yap$"

AmenoTorifune_B2F_Text_LuckPostBattle:
	.string "yap yap yap yap\n"
	.string "yap yap yap yap$"

AmenoTorifune_B2F_Text_KMRIntro:
	.string "I just won 3200 dollars\n"
	.string "at the casino.$"

AmenoTorifune_B2F_Text_KMRDefeated:
	.string "Fuck, I lost it all.$"

AmenoTorifune_B2F_Text_KMRPostBattle:
	.string "Dealer had a 21 again dude\n"
	.string "of course.$"

AmenoTorifune_B2F_Text_LemonIntro:
	.string "Play NR format.$"

AmenoTorifune_B2F_Text_LemonDefeated:
	.string "April 15th, 2027.$"

AmenoTorifune_B2F_Text_LemonPostBattle:
	.string "https://discord.gg/BTK4mfUWHp$"

AmenoTorifune_B2F_Text_AnnieIntro:
	.string "Hi cutie.\n"
	.string ":Gayge:$"

AmenoTorifune_B2F_Text_AnnieDefeated:
	.string "Wow, homophobia.$"

AmenoTorifune_B2F_Text_AnniePostBattle:
	.string "Are you Gayge?$"

AmenoTorifune_B2F_Text_MiliIntro:
	.string "It's a beautiful day outside!\n"
	.string "Birds are singing, flowers in bloom!\p"
	.string "On days like this, kids like\n"
	.string "you should be melting!$"

AmenoTorifune_B2F_Text_MiliDefeated:
	.string "The sun wasn't hot enough…$"

AmenoTorifune_B2F_Text_MiliPostBattle:
	.string "Should have used a rain team.\n"
	.string ":($"
