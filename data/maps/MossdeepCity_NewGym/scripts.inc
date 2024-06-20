MossdeepCity_NewGym_MapScripts::
	.byte 0

MossdeepCity_NewGym_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_NewGym_EventScript_GotYourBadge
	goto MossdeepCity_NewGym_EventScript_GymTheme
	end

MossdeepCity_NewGym_EventScript_GymTheme::
	msgbox MossdeepCity_NewGym_Text_Fishing, MSGBOX_DEFAULT
	release
	end

MossdeepCity_NewGym_EventScript_GotYourBadge::
	msgbox MossdeepCity_NewGym_Text_AcquiredBadge, MSGBOX_DEFAULT
	release
	end

MossdeepCity_NewGym_EventScript_LvK::
	goto_if_lt VAR_MOSSDEEP_NEW_GYM_STATE, 4, MossdeepCity_NewGym_EventScript_LvKNotEnough
	trainerbattle_single TRAINER_TATE_AND_LIZA_1, MossdeepCity_NewGym_Text_LvKIntro, MossdeepCity_NewGym_Text_LvKDefeat, MossdeepCity_NewGym_EventScript_LvKDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_TM04, MossdeepCity_NewGym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_NewGym_Text_LvKPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_NewGym_EventScript_LvKDefeated::
	message MossdeepCity_NewGym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_NewGym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_NewGym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_NewGym_Text_RegisteredLvK, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_NewGym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM45
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_NewGym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM04
	release
	end

MossdeepCity_NewGym_EventScript_GiveCalmMind::
	giveitem ITEM_TM45
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_NewGym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM04
	return

MossdeepCity_NewGym_EventScript_LvKRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_NewGym_Text_LvKPreRematch, MossdeepCity_NewGym_Text_LvKRematchDefeat, MossdeepCity_NewGym_Text_LvKRematchNeedTwoMons
	msgbox MossdeepCity_NewGym_Text_LvKPostRematch, MSGBOX_AUTOCLOSE
	end

MossdeepCity_NewGym_EventScript_GatherMen::
	addvar VAR_MOSSDEEP_NEW_GYM_STATE, 1
	return

MossdeepCity_NewGym_EventScript_LvKNotEnough::
	msgbox MossdeepCity_NewGym_Text_LvKLackMen, MSGBOX_NPC
	release
	end

MossdeepCity_NewGym_EventScript_PrestonFindMen::
	call MossdeepCity_NewGym_EventScript_GatherMen
	msgbox MossdeepCity_NewGym_Text_PrestonOtherLifters, MSGBOX_DEFAULT
	release
	end

MossdeepCity_NewGym_EventScript_VirgilFindMen::
	call MossdeepCity_NewGym_EventScript_GatherMen
	msgbox MossdeepCity_NewGym_Text_VirgilOtherLifters, MSGBOX_DEFAULT
	release
	end

MossdeepCity_NewGym_EventScript_BlakeFindMen::
	call MossdeepCity_NewGym_EventScript_GatherMen
	msgbox MossdeepCity_NewGym_Text_BlakeOtherLifters, MSGBOX_DEFAULT
	release
	end

MossdeepCity_NewGym_EventScript_HannahFindMen::
	call MossdeepCity_NewGym_EventScript_GatherMen
	msgbox MossdeepCity_NewGym_Text_HannahOtherLifters, MSGBOX_DEFAULT
	release
	end

MossdeepCity_NewGym_EventScript_SwimLady::
	msgbox MossdeepCity_NewGym_Text_SwimExercise, MSGBOX_NPC
	end

MossdeepCity_NewGym_EventScript_Volleyballer1::
	msgbox MossdeepCity_NewGym_Text_Volleyballing1, MSGBOX_NPC
	end

MossdeepCity_NewGym_EventScript_Volleyballer2::
	msgbox MossdeepCity_NewGym_Text_Volleyballing2, MSGBOX_NPC
	end

MossdeepCity_NewGym_EventScript_LostHiker::
	msgbox MossdeepCity_NewGym_Text_Mountain, MSGBOX_NPC
	end

MossdeepCity_NewGym_EventScript_AquaGrunt::
	msgbox MossdeepCity_NewGym_Text_What, MSGBOX_NPC
	end

MossdeepCity_NewGym_EventScript_Sailor::
	msgbox MossdeepCity_NewGym_Text_Beefers, MSGBOX_NPC
	end

MossdeepCity_NewGym_EventScript_Picnic::
	msgbox MossdeepCity_NewGym_Text_BeachLunch, MSGBOX_NPC
	end

MossdeepCity_NewGym_EventScript_OldGuy::
	msgbox MossdeepCity_NewGym_Text_Old, MSGBOX_NPC
	end

MossdeepCity_NewGym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_NewGym_Text_PrestonIntro, MossdeepCity_NewGym_Text_PrestonDefeat, MossdeepCity_NewGym_EventScript_PrestonFindMen
	msgbox MossdeepCity_NewGym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_NewGym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_NewGym_Text_VirgilIntro, MossdeepCity_NewGym_Text_VirgilDefeat, MossdeepCity_NewGym_EventScript_VirgilFindMen
	msgbox MossdeepCity_NewGym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_NewGym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_NewGym_Text_BlakeIntro, MossdeepCity_NewGym_Text_BlakeDefeat, MossdeepCity_NewGym_EventScript_BlakeFindMen
	msgbox MossdeepCity_NewGym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_NewGym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_NewGym_Text_HannahIntro, MossdeepCity_NewGym_Text_HannahDefeat, MossdeepCity_NewGym_EventScript_HannahFindMen
	msgbox MossdeepCity_NewGym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_NewGym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_NewGym_EventScript_GymStatueCertified
	goto MossdeepCity_NewGym_EventScript_GymStatue
	end

MossdeepCity_NewGym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_NewGym_EventScript_GymStatueCertified
	goto MossdeepCity_NewGym_EventScript_GymStatue
	end

MossdeepCity_NewGym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_NewGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_NewGym_EventScript_GymStatue::
	msgbox MossdeepCity_NewGym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_NewGym_Text_SwimExercise:
	.string "There's a lot of people trying\n"
	.string "to tan on the beach here.\p"
	.string "…They know this is indoors, right?$"

MossdeepCity_NewGym_Text_Volleyballing1:
	.string "Wait a minute.\n"
	.string "The Lakers don't play volleyball.$"

MossdeepCity_NewGym_Text_Volleyballing2:
	.string "I keep hitting this damn net.$"

MossdeepCity_NewGym_Text_Mountain:
	.string "This isn't a mountain.\n"
	.string "…How did I get here?$"

MossdeepCity_NewGym_Text_What:
	.string "What?$"

MossdeepCity_NewGym_Text_Beefers:
	.string "The Gym Leader has his trainers\n"
	.string "scattered around.\l"
	.string "They're big on fitness.\p"
	.string "Fitness d… nah, never mind.$"

MossdeepCity_NewGym_Text_BeachLunch:
	.string "Having a beach picnic is great.\n"
	.string "Though the sand isn't fun…$"

MossdeepCity_NewGym_Text_Old:
	.string "Ahh, this is the life.$"

MossdeepCity_NewGym_Text_PrestonIntro:
	.string "Roast me as much as possible.$"

MossdeepCity_NewGym_Text_PrestonDefeat:
	.string "I said me, not my team!$"

MossdeepCity_NewGym_Text_PrestonOtherLifters:
	.string "There's four trainers total.\n"
	.string "Best of luck.$"

MossdeepCity_NewGym_Text_PrestonPostBattle:
	.string "We're dying for your anti-rizz.$"

MossdeepCity_NewGym_Text_VirgilIntro:
	.string "This is going to be such a\n"
	.string "beautiful disaster.$"

MossdeepCity_NewGym_Text_VirgilDefeat:
	.string "Ach, dropped my weights.$"

MossdeepCity_NewGym_Text_VirgilOtherLifters:
	.string "Gotta beat the other lifters.\n"
	.string "Sorry liberals, I don't make the rules.$"

MossdeepCity_NewGym_Text_VirgilPostBattle:
	.string "Is Celtic Guardian really that funny?$"

MossdeepCity_NewGym_Text_BlakeIntro:
	.string "Beefcakes?\n"
	.string "Sorry, we don't do pastry.$"

MossdeepCity_NewGym_Text_BlakeDefeat:
	.string "Are we beefing?$"

MossdeepCity_NewGym_Text_BlakeOtherLifters:
	.string "Ah, the Gym challenge, right.\n"
	.string "Good luck with the rest.$"

MossdeepCity_NewGym_Text_BlakePostBattle:
	.string "I get the aesthetic. I do.\p"
	.string "But did we really need an\n"
	.string "indoor beach?$"

MossdeepCity_NewGym_Text_HannahIntro:
	.string "Work out with me,\n"
	.string "if you want to live.$"

MossdeepCity_NewGym_Text_HannahDefeat:
	.string "Hasta la vista, baby.$"

MossdeepCity_NewGym_Text_HannahOtherLifters:
	.string "Well done.\n"
	.string "Now complete your workout.$"

MossdeepCity_NewGym_Text_HannahPostBattle:
	.string "I'll be back.$"

MossdeepCity_NewGym_Text_LvKIntro:
	.string "LvK: Oh, now this is original.\p"
	.string "Walk in the gym, battle, win,\n"
	.string "and continue onwards.\p"
	.string "Well, this time's going to be\n"
	.string "different, pal.\p"
	.string "They'll be calling you Sisyphus\n"
	.string "after we're done here!\p"
	.string "Replays, don't fail me now!$"

MossdeepCity_NewGym_Text_LvKDefeat:
	.string "Hey, Lois…\n"
	.string "Nah, just kidding.$"

MossdeepCity_NewGym_Text_ReceivedMindBadge:
	.string "{PLAYER} received the Celtic Badge\n"
	.string "from LukeVonKarma.$"

MossdeepCity_NewGym_Text_ExplainMindBadgeTakeThis:
	.string "My Celtic Badge makes you way funnier.\n"
	.string "Outside of battle, you can use\l"
	.string "the HM for Dive now, too.\p"
	.string "Oh, and you can take this.$"

MossdeepCity_NewGym_Text_ExplainCalmMind:
	.string "TM45 contains Iron Head.\n"
	.string "It causes flinching pretty often.\p"
	.string "Pretty useful, as a streamer.\n"
	.string "… … … … … …$"

MossdeepCity_NewGym_Text_RegisteredLvK:
	.string "Registered Gym Leader LukeVonKarma\n"
	.string "in the Pokénav.$"

MossdeepCity_NewGym_Text_LvKPostBattle:
	.string "Hmm… there's really something off\n"
	.string "about this beach, isn't there?$"

MossdeepCity_NewGym_Text_GymStatue:
	.string "Mossdeep City Pokémon Gym$"

MossdeepCity_NewGym_Text_GymStatueCertified:
	.string "Mossdeep City Pokémon Gym\p"
	.string "LukeVonKarma's Certified Trainers:\n"
	.string "{PLAYER}$"

MossdeepCity_NewGym_Text_Fishing:
	.string "Yo, what's up, Trainer?\p"
	.string "This here's a Pokémon Gym,\n"
	.string "and a fitness gym!\p"
	.string "There's four Trainers you have to\n"
	.string "beat to challenge LukeVonKarma.\p"
	.string "However, there's also a lot of\n"
	.string "regular visitors, so you'll have\l"
	.string "to find them.$"

MossdeepCity_NewGym_Text_AcquiredBadge:
	.string "Now that's a nice badge!$"

MossdeepCity_NewGym_Text_LvKPreRematch:
	.string "TATE: POKéMON…\n"
	.string "LIZA: POKéMON…\p"
	.string "TATE: By changing the party's mix…\n"
	.string "LIZA: The battle style changes.\p"
	.string "TATE: But me…\n"
	.string "LIZA: But me…\p"
	.string "TATE: I'll always be with LIZA!\n"
	.string "LIZA: I'll always be with TATE!\p"
	.string "TATE: Our combination…\n"
	.string "LIZA: We'll show you again and again!$"

MossdeepCity_NewGym_Text_LvKRematchDefeat:
	.string "TATE: You and your POKéMON…\n"
	.string "LIZA: It's as if you were siblings!$"

MossdeepCity_NewGym_Text_LvKPostRematch:
	.string "TATE: You can knock us down,\n"
	.string "but we'll never stay down!\p"
	.string "LIZA: Because the two of us,\n"
	.string "we always support each other!$"

MossdeepCity_NewGym_Text_LvKLackMen:
	.string "Yo! Looking for a battle?\n"
	.string "I'm doing a meme review right now.\p"
	.string "This here's a fitness gym.\p"
	.string "So, if you can beat the four\n"
	.string "personal trainers, then we'll fight.$"

MossdeepCity_NewGym_Text_LvKRematchNeedTwoMons:
	.string "balls$"

