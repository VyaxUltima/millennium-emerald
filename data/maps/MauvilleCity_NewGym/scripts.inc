MauvilleCity_NewGym_MapScripts::
	.byte 0

MauvilleCity_NewGym_EventScript_Wattson::
	goto_if_lt VAR_MAUVILLE_NEW_GYM_STATE, 4, MauvilleCity_NewGym_EventScript_WattsonNoEvidence
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_NewGym_Text_WattsonIntro, MauvilleCity_NewGym_Text_WattsonDefeat, MauvilleCity_NewGym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_NewGym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM34, MauvilleCity_NewGym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_NewGym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_NewGym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_NewGym_EventScript_WattsonDefeated::
	message MauvilleCity_NewGym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_NewGym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	call MauvilleCity_NewGym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_NewGym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_NewGym_EventScript_GiveShockWave2::
	giveitem ITEM_TM85
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_NewGym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM34
	release
	end

MauvilleCity_NewGym_EventScript_GiveShockWave::
	giveitem ITEM_TM85
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_NewGym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM34
	return

MauvilleCity_NewGym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_NewGym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_NewGym_EventScript_GatherEvidence::
	addvar VAR_MAUVILLE_NEW_GYM_STATE, 1
	return

MauvilleCity_NewGym_EventScript_WattsonNoEvidence::
	msgbox MauvilleCity_NewGym_Text_WattsonLackEvidence, MSGBOX_DEFAULT
	release
	end

MauvilleCity_NewGym_EventScript_KirkEvidence::
	call MauvilleCity_NewGym_EventScript_GatherEvidence
	msgbox MauvilleCity_NewGym_Text_KirkGiveEvidence, MSGBOX_DEFAULT
	release
	end

MauvilleCity_NewGym_EventScript_ShawnEvidence::
	call MauvilleCity_NewGym_EventScript_GatherEvidence
	msgbox MauvilleCity_NewGym_Text_ShawnGiveEvidence, MSGBOX_DEFAULT
	release
	end

MauvilleCity_NewGym_EventScript_BenEvidence::
	call MauvilleCity_NewGym_EventScript_GatherEvidence
	msgbox MauvilleCity_NewGym_Text_BenGiveEvidence, MSGBOX_DEFAULT
	release
	end

MauvilleCity_NewGym_EventScript_VivianEvidence::
	call MauvilleCity_NewGym_EventScript_GatherEvidence
	msgbox MauvilleCity_NewGym_Text_VivianGiveEvidence, MSGBOX_DEFAULT
	release
	end

MauvilleCity_NewGym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_NewGym_Text_WattsonPreRematch, MauvilleCity_NewGym_Text_WattsonRematchDefeat, MauvilleCity_NewGym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_NewGym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_NewGym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_NewGym_Text_KirkIntro, MauvilleCity_NewGym_Text_KirkDefeat, MauvilleCity_NewGym_EventScript_KirkEvidence
	msgbox MauvilleCity_NewGym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_NewGym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_NewGym_Text_ShawnIntro, MauvilleCity_NewGym_Text_ShawnDefeat, MauvilleCity_NewGym_EventScript_ShawnEvidence
	msgbox MauvilleCity_NewGym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_NewGym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_NewGym_Text_BenIntro, MauvilleCity_NewGym_Text_BenDefeat, MauvilleCity_NewGym_EventScript_BenEvidence
	msgbox MauvilleCity_NewGym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_NewGym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_NewGym_Text_VivianIntro, MauvilleCity_NewGym_Text_VivianDefeat, MauvilleCity_NewGym_EventScript_VivianEvidence
	msgbox MauvilleCity_NewGym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_NewGym_EventScript_Defense::
	msgbox MauvilleCity_NewGym_Text_SaulGoodman, MSGBOX_NPC
	end

MauvilleCity_NewGym_EventScript_Prosecution::
	msgbox MauvilleCity_NewGym_Text_YourHonorLeague, MSGBOX_NPC
	end

MauvilleCity_NewGym_EventScript_Beter::
	msgbox MauvilleCity_NewGym_Text_LikeThatTime, MSGBOX_NPC
	end

MauvilleCity_NewGym_EventScript_BanlistHater::
	msgbox MauvilleCity_NewGym_Text_Unban, MSGBOX_NPC
	end

MauvilleCity_NewGym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_NewGym_EventScript_GymStatueCertified
	goto MauvilleCity_NewGym_EventScript_GymStatue
	end

MauvilleCity_NewGym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_NewGym_EventScript_GymStatueCertified
	goto MauvilleCity_NewGym_EventScript_GymStatue
	end

MauvilleCity_NewGym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_NewGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_NewGym_EventScript_GymStatue::
	msgbox MauvilleCity_NewGym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_NewGym_Text_KirkIntro:
	.string "I'll give you some evidence,\n"
	.string "if you can beat me!$"

MauvilleCity_NewGym_Text_KirkDefeat:
	.string "Not bad!$"

MauvilleCity_NewGym_Text_KirkGiveEvidence:
	.string "Alright then.\n"
	.string "My evidence is “B”.$"

MauvilleCity_NewGym_Text_KirkPostBattle:
	.string "Found the rest yet?$"

MauvilleCity_NewGym_Text_ShawnIntro:
	.string "I trained under MBT!\n"
	.string "I only practice for 10 minutes!$"

MauvilleCity_NewGym_Text_ShawnDefeat:
	.string "Should I practice less…?$"

MauvilleCity_NewGym_Text_ShawnGiveEvidence:
	.string "My evidence is “U”.\n"
	.string "Now go collect the rest!$"

MauvilleCity_NewGym_Text_ShawnPostBattle:
	.string "MBT is a master of debates.$"

MauvilleCity_NewGym_Text_BenIntro:
	.string "Your honor?\n"
	.string "I don't know what contempt is,\l"
	.string "but I'd like to be held.$"

MauvilleCity_NewGym_Text_BenDefeat:
	.string "Contempt is a crime?$"

MauvilleCity_NewGym_Text_BenGiveEvidence:
	.string "The evidence I have is “S”.\n"
	.string "I think there was two copies.$"

MauvilleCity_NewGym_Text_BenPostBattle:
	.string "MBT says he likes setting up\n"
	.string "quirked up white boys.$"

MauvilleCity_NewGym_Text_VivianIntro:
	.string "What, are we going to\n"
	.string "cross-examine a dog now?$"

MauvilleCity_NewGym_Text_VivianDefeat:
	.string "Wait a second.$"

MauvilleCity_NewGym_Text_VivianGiveEvidence:
	.string "My evidence is “Y”.\n"
	.string "Go fetch the others, now.$"

MauvilleCity_NewGym_Text_VivianPostBattle:
	.string "You are not a clown.\n"
	.string "You are the entire circus.$"

MauvilleCity_NewGym_Text_SaulGoodman:
	.string "Hi, I'm Saul Goodman.\n"
	.string "Did you know that you have rights?$"

MauvilleCity_NewGym_Text_YourHonorLeague:
	.string "Your Honor.\n"
	.string "League of Legends.$"

MauvilleCity_NewGym_Text_LikeThatTime:
	.string "This is like that time I faced\n"
	.string "off against von Karma. Nyehehe.$"

MauvilleCity_NewGym_Text_Unban:
	.string "I'm here to appeal the ban of\n"
	.string "Self-Destruct Button.\p"
	.string "It's my right as an American\n"
	.string "to hold up the entire YCS!$"

MauvilleCity_NewGym_Text_WattsonIntro:
	.string "Well, well, well.\n"
	.string "So it was “BUSSY” all along.\l"
	.string "Should have known.\p"
	.string "Well, since you went to the trouble\n"
	.string "of collecting all that:\p"
	.string "Let's have a debate!\p"
	.string "…Oh, no, you and I won't\n"
	.string "be debating each other.\p"
	.string "Your Pokémon will debate my\n"
	.string "team of sissy hypnos!\l"
	.string "Get ready!$"

MauvilleCity_NewGym_Text_WattsonDefeat:
	.string "Erm, ackchyually-\p"
	.string "…Fine, I lost!\p"
	.string "That wasn't half bad.\n"
	.string "Then take my Badge.$"

MauvilleCity_NewGym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} received the Attorney Badge\n"
	.string "from MBT.$"

MauvilleCity_NewGym_Text_ExplainDynamoBadgeTakeThis:
	.string "With that Attorney Badge, you can\n"
	.string "use Rock Smash out of battle.\p"
	.string "Hmm…\n"
	.string "You should take this, too!$"

MauvilleCity_NewGym_Text_ExplainShockWave:
	.string "TM85 contains Zen Headbutt.\p"
	.string "It can cause the opponent to flinch,\n"
	.string "and forget their whole argument.\p"
	.string "… … … … … …$"

MauvilleCity_NewGym_Text_RegisteredWattson:
	.string "Registered MBT\n"
	.string "in the Pokénav.$"

MauvilleCity_NewGym_Text_WattsonPostBattle:
	.string "Maybe I should polish this trophy.$"

MauvilleCity_NewGym_Text_WattsonGoForthAndEndeavor:
	.string "White.$"

MauvilleCity_NewGym_Text_WattsonLackEvidence:
	.string "Hm? I'm currently watching the\n"
	.string "latest Progression episode.\p"
	.string "Unless you have all the evidence,\n"
	.string "I'm not interested.$"

MauvilleCity_NewGym_Text_GymStatue:
	.string "Mauville City Pokémon Gym\p"
	.string "MBT's Certified Trainers:\n"
	.string "Ruggles$"

MauvilleCity_NewGym_Text_GymStatueCertified:
	.string "Mauville City Pokémon Gym\p"
	.string "MBT's Certified Trainers:\n"
	.string "Ruggles, {PLAYER}$"

MauvilleCity_NewGym_Text_WattsonPreRematch:
	.string "WATTSON: Ah-ha! Here at last!\n"
	.string "I know what you want.\l"
	.string "You want to battle my POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "I'll make sparks fly from you!\n"
	.string "Don't say I didn't warn you!$"

MauvilleCity_NewGym_Text_WattsonRematchDefeat:
	.string "Oof…\n"
	.string "Our batteries ran dry…$"

MauvilleCity_NewGym_Text_WattsonPostRematch:
	.string "WATTSON: We'll have to recharge our\n"
	.string "batteries again.\p"
	.string "When we're fully charged up, we'll\n"
	.string "gladly accept your challenge.\p"
	.string "So, come back again sometime,\n"
	.string "won't you?$"

MauvilleCity_NewGym_Text_WattsonRematchNeedTwoMons:
	.string "WATTSON: Ah-ha! Here at last!\n"
	.string "I know what you want.\l"
	.string "You want to battle my POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "Oops! Wait!\n"
	.string "You've only one POKéMON with you!\p"
	.string "Come see me with two or more\n"
	.string "POKéMON, all right?$"

