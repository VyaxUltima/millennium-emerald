FortreeCity_NewGym_MapScripts::
	.byte 0

FortreeCity_NewGym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_FORTREE_CITY_NEW_GYM, 8, 56
	waitstate
	releaseall
	end

FortreeCity_NewGym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_NewGym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_NewGym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_NewGym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_NewGym_Text_JaredIntro, FortreeCity_NewGym_Text_JaredDefeat
	msgbox FortreeCity_NewGym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_NewGym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_NewGym_Text_EdwardoIntro, FortreeCity_NewGym_Text_EdwardoDefeat
	msgbox FortreeCity_NewGym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_NewGym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_NewGym_Text_FlintIntro, FortreeCity_NewGym_Text_FlintDefeat
	msgbox FortreeCity_NewGym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_NewGym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_NewGym_Text_AshleyIntro, FortreeCity_NewGym_Text_AshleyDefeat
	msgbox FortreeCity_NewGym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_NewGym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_NewGym_Text_WinonaIntro, FortreeCity_NewGym_Text_WinonaDefeat, FortreeCity_NewGym_EventScript_WinonaDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_TM40, FortreeCity_NewGym_EventScript_GiveAerialAce2
	msgbox FortreeCity_NewGym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_NewGym_EventScript_WinonaDefeated::
	message FortreeCity_NewGym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_NewGym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_NewGym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_NewGym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_NewGym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM06
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_NewGym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	release
	end

FortreeCity_NewGym_EventScript_GiveAerialAce::
	giveitem ITEM_TM06
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_NewGym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	return

FortreeCity_NewGym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_NewGym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_NewGym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_NewGym_EventScript_GymStatueCertified
	goto FortreeCity_NewGym_EventScript_GymStatue
	end

FortreeCity_NewGym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_NewGym_EventScript_GymStatueCertified
	goto FortreeCity_NewGym_EventScript_GymStatue
	end

FortreeCity_NewGym_EventScript_GymStatueCertified::
	msgbox FortreeCity_NewGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_NewGym_EventScript_GymStatue::
	msgbox FortreeCity_NewGym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

@ Text

FortreeCity_NewGym_Text_WinonaIntro:
	.string "dire: Congratulations, {PLAYER}.\n"
	.string "You survived the e-girl brigade.\l"
	.string "Now it's time for you to face me.\p"
	.string "Hm? How do I know your name?\n"
	.string "Simple. I'm in your walls.\p"
	.string "I'm excited for this. Finally I don't\n"
	.string "have to edit anything.\l"
	.string "Let's do this!$"

FortreeCity_NewGym_Text_WinonaDefeat:
	.string "That was rough.\n"
	.string "I need to be more toxic.\p"
	.string "Well, here you go.$"

FortreeCity_NewGym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} received the Loptr Badge\n"
	.string "from dire.$"

FortreeCity_NewGym_Text_ExplainFeatherBadgeTakeThis:
	.string "dire: With the Loptr Badge, Pokémon up\n"
	.string "to Level 60, will obey all commands.\p"
	.string "Also, you now have fast travel in\n"
	.string "the form of the Fly HM.\p"
	.string "Also, this is a gift from me.\n"
	.string "A reflection of my personality.$"

FortreeCity_NewGym_Text_ExplainAerialAce:
	.string "TM06 is Toxic.\p"
	.string "The poison it inflicts gradually gets\n"
	.string "stronger over time.\l"
	.string "Sort of like a Discord server.$"

FortreeCity_NewGym_Text_RegisteredWinona:
	.string "Registered Gym Leader dire\n"
	.string "in the Pokénav.$"

FortreeCity_NewGym_Text_WinonaPostBattle:
	.string "Wait, streamers might play this.\n"
	.string "So I have to edit after all…$"

FortreeCity_NewGym_Text_GymStatue:
	.string "Fortree City Pokémon Gym$"

FortreeCity_NewGym_Text_GymStatueCertified:
	.string "Fortree City Pokémon Gym\p"
	.string "dire's Certified Trainers:\n"
	.string "{PLAYER}$"

FortreeCity_NewGym_Text_JaredIntro:
	.string "Tired office ladies should be\n"
	.string "in demand.$"

FortreeCity_NewGym_Text_JaredDefeat:
	.string "One wacky fact about me?\n"
	.string "I like margaritas.$"

FortreeCity_NewGym_Text_JaredPostBattle:
	.string "Where would you get mono from?\n"
	.string "Ther Saizeria drink bar?$"

FortreeCity_NewGym_Text_EdwardoIntro:
	.string "I bullied someone into playing\n"
	.string "Watt Kashtira.$"

FortreeCity_NewGym_Text_EdwardoDefeat:
	.string "No need to thank me.\n"
	.string "I'll do it again.$"

FortreeCity_NewGym_Text_EdwardoPostBattle:
	.string "Osaka might have a thing for feet.$"

FortreeCity_NewGym_Text_FlintIntro:
	.string "I sure do wish I could date\n"
	.string "Jack Atlas.$"

FortreeCity_NewGym_Text_FlintDefeat:
	.string "It's been 0 days since I last\n"
	.string "thirsted for Jack Atlas.$"

FortreeCity_NewGym_Text_FlintPostBattle:
	.string "The power of anime is too strong!!!!$"

FortreeCity_NewGym_Text_AshleyIntro:
	.string "It's Ulner, bitch.$"

FortreeCity_NewGym_Text_AshleyDefeat:
	.string "Vegetables aren't a thing.\n"
	.string "They don't actually exist.$"

FortreeCity_NewGym_Text_AshleyPostBattle:
	.string "Good job surviving in that\n"
	.string "bubble for so long.$"

FortreeCity_NewGym_Text_GymGuideAdvice:
	.string "How's it going?\p"
	.string "As you can see… this Gym is\n"
	.string "full of toxicity.\p"
	.string "You'll need an Acro Bike to be able\n"
	.string "to cross over those bridges.\p"
	.string "If you don't have one, visit Rydel's\n"
	.string "bike shop in Mauville.\p"
	.string "Also, if you see a strange spot\n"
	.string "on the floor, you can return here\l"
	.string "by walking on it.$"

FortreeCity_NewGym_Text_GymGuidePostVictory:
	.string "Survived the e-girls?\n"
	.string "Well done.$"

