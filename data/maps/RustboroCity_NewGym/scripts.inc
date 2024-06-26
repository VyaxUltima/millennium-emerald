RustboroCity_NewGym_MapScripts::
	.byte 0

RustboroCity_NewGym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_NewGym_Text_RoxanneIntro, RustboroCity_NewGym_Text_RoxanneDefeat, RustboroCity_NewGym_EventScript_RoxanneDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_TM39, RustboroCity_NewGym_EventScript_GiveRockTomb
	msgbox RustboroCity_NewGym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_NewGym_EventScript_RoxanneDefeated::
	message RustboroCity_NewGym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_NewGym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_NewGym_EventScript_GiveRockTomb
	end

RustboroCity_NewGym_EventScript_GiveRockTomb::
	giveitem ITEM_TM11
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM39
	msgbox RustboroCity_NewGym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_NewGym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_NewGym_Text_RoxannePreRematch, RustboroCity_NewGym_Text_RoxanneRematchDefeat, RustboroCity_NewGym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_NewGym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_NewGym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_NewGym_Text_JoshIntro, RustboroCity_NewGym_Text_JoshDefeat
	msgbox RustboroCity_NewGym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_NewGym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_NewGym_Text_TommyIntro, RustboroCity_NewGym_Text_TommyDefeat
	msgbox RustboroCity_NewGym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_NewGym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_NewGym_Text_MarcIntro, RustboroCity_NewGym_Text_MarcDefeat
	msgbox RustboroCity_NewGym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_NewGym_EventScript_NewGymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_NewGym_EventScript_NewGymGuidePostVictory
	msgbox RustboroCity_NewGym_Text_NewGymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_NewGym_EventScript_NewGymGuidePostVictory::
	msgbox RustboroCity_NewGym_Text_NewGymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_NewGym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_NewGym_EventScript_NewGymStatueCertified
	goto RustboroCity_NewGym_EventScript_NewGymStatue
	end

RustboroCity_NewGym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_NewGym_EventScript_NewGymStatueCertified
	goto RustboroCity_NewGym_EventScript_NewGymStatue
	end

RustboroCity_NewGym_EventScript_NewGymStatueCertified::
	msgbox RustboroCity_NewGym_Text_NewGymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_NewGym_EventScript_NewGymStatue::
	msgbox RustboroCity_NewGym_Text_NewGymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_NewGym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_NewGym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_NewGym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_NewGym_Text_NewGymGuideAdvice:
	.string "Yo, how's it going?\p"
	.string "Listen, my friend!\n"
	.string "Would you like to become the CHAMPION?\p"
	.string "I'm no TRAINER, not me, but I can\n"
	.string "sure give you winning advice.\p"
	.string "That's settled, then! We'll aim for the\n"
	.string "POKéMON CHAMPIONSHIP together!\p"
	.string "It's your job as a TRAINER to collect\n"
	.string "GYM BADGES, am I right?\p"
	.string "But GYM LEADERS aren't pushovers!\p"
	.string "And that's where I come in!\n"
	.string "I'm here to provide expert advice!\p"
	.string "ROXANNE, the GYM LEADER, is a user\n"
	.string "of ROCK-type POKéMON.\p"
	.string "The ROCK type is very durable, but\n"
	.string "it can't stand WATER-type and\l"
	.string "GRASS-type moves.\p"
	.string "Come see me afterwards, if you beat\n"
	.string "the GYM LEADER.\p"
	.string "Well, go for it!$"

RustboroCity_NewGym_Text_NewGymGuidePostVictory:
	.string "Whoa! What a breathtaking victory!\n"
	.string "My cheering must've worked!\p"
	.string "Great!\n"
	.string "Check your TRAINER CARD.\p"
	.string "The STONE BADGE you got should be\n"
	.string "properly recorded on it.\p"
	.string "In other words…\p"
	.string "You've climbed the first step on\n"
	.string "the stairs to the CHAMPIONSHIP!\p"
	.string "That's got to feel awesome!$"

RustboroCity_NewGym_Text_JoshIntro:
	.string "Y'know, it's about 100 degrees\n"
	.string "in here.\p"
	.string "Celsius.$"

RustboroCity_NewGym_Text_JoshDefeat:
	.string "Who turns off their BIOS fans?$"

RustboroCity_NewGym_Text_JoshPostBattle:
	.string "I still can't believe this.$"

RustboroCity_NewGym_Text_TommyIntro:
	.string "I promise I will become worse.$"

RustboroCity_NewGym_Text_TommyDefeat:
	.string "I will not elaborate on this.$"

RustboroCity_NewGym_Text_TommyPostBattle:
	.string "No.$"

RustboroCity_NewGym_Text_MarcIntro:
	.string "Man it's hot in here.$"

RustboroCity_NewGym_Text_MarcDefeat:
	.string "He turned the fans off again…$"

RustboroCity_NewGym_Text_MarcPostBattle:
	.string "Better than being Mined.$"

RustboroCity_NewGym_Text_RoxanneIntro:
	.string "Farfa: Normal Tour Guide effect.\n"
	.string "Wait, what? This is Pokémon.\p"
	.string "Ah, whatever. I've got this.\p"
	.string "Hope you aren't relying on any Water.\n"
	.string "You know Fire beats Water.\p"
	.string "After all, my PC without fans\n"
	.string "melted my cooling system!$"

RustboroCity_NewGym_Text_RoxanneDefeat:
	.string "Ironman Part 2.$"

RustboroCity_NewGym_Text_ReceivedStoneBadge:
	.string "{PLAYER} received the Dante Badge\n"
	.string "from Farfa.$"

RustboroCity_NewGym_Text_StoneBadgeInfoTakeThis:
	.string "The Dante Badge lets you use\n"
	.string "Cut on trees to make bonus cards.\p"
	.string "And I'm supposed to give you this\n"
	.string "weird CD thing.$"

RustboroCity_NewGym_Text_ExplainRockTomb:
	.string "That TM11 can teach Sunny Day.\p"
	.string "If you thought Fire was good\n"
	.string "against Water already, try that out!\p"
	.string "You can use that TM as many times\n"
	.string "as you want.$"

RustboroCity_NewGym_Text_RoxannePostBattle:
	.string "Banning you if I don't laugh.$"

RustboroCity_NewGym_Text_NewGymStatue:
	.string "Rustboro City Pokémon Gym\p"
	.string "Farfa's Certified Trainers:\n"
	.string "Ruggles$"

RustboroCity_NewGym_Text_NewGymStatueCertified:
	.string "Rustboro City Pokémon Gym\p"
	.string "Farfa's Certified Trainers:\n"
	.string "Ruggles, {PLAYER}$"

RustboroCity_NewGym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Farfa: Ni hao\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

RustboroCity_NewGym_Text_RegisteredRoxanne:
	.string "Registered Farfa\n"
	.string "in the Pokénav.$"

RustboroCity_NewGym_Text_RoxannePreRematch:
	.string "ROXANNE: I'm so glad to see you again.\n"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become. Let us battle!$"

RustboroCity_NewGym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Again, I have lost…$"

RustboroCity_NewGym_Text_RoxannePostRematch:
	.string "ROXANNE: I still have much to learn\n"
	.string "when it comes to battling POKéMON.\p"
	.string "That awareness makes me love battling\n"
	.string "all that much more!$"

RustboroCity_NewGym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: I'm so glad to see you again.\n"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become…\p"
	.string "Oh, no…\n"
	.string "You only have one POKéMON with you?\p"
	.string "Please return with at least one more\n"
	.string "POKéMON.$"
