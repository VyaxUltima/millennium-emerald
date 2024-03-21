DewfordTown_NewGym_MapScripts::
	.byte 0

DewfordTown_NewGym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_NewGym_Text_TakaoIntro, DewfordTown_NewGym_Text_TakaoDefeat
	msgbox DewfordTown_NewGym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_NewGym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_NewGym_Text_JocelynIntro, DewfordTown_NewGym_Text_JocelynDefeat
	msgbox DewfordTown_NewGym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_NewGym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_NewGym_Text_CristianIntro, DewfordTown_NewGym_Text_CristianDefeat
	msgbox DewfordTown_NewGym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_NewGym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_NewGym_Text_LilithIntro, DewfordTown_NewGym_Text_LilithDefeat
	msgbox DewfordTown_NewGym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_NewGym_EventScript_BlackBelt::
	msgbox DewfordTown_NewGym_Text_Rocks, MSGBOX_NPC
	end

DewfordTown_NewGym_EventScript_Woman::
	msgbox DewfordTown_NewGym_Text_Relax, MSGBOX_NPC
	end

DewfordTown_NewGym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_NewGym_EventScript_GymStatueCertified
	goto DewfordTown_NewGym_EventScript_GymStatue
	end

DewfordTown_NewGym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_NewGym_EventScript_GymStatueCertified
	goto DewfordTown_NewGym_EventScript_GymStatue
	end

DewfordTown_NewGym_EventScript_GymStatueCertified::
	msgbox DewfordTown_NewGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_NewGym_EventScript_GymStatue::
	msgbox DewfordTown_NewGym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_NewGym_Text_TakaoIntro:
	.string "We're all about double battles!$"

DewfordTown_NewGym_Text_TakaoDefeat:
	.string "Doubled over…$"

DewfordTown_NewGym_Text_TakaoPostBattle:
	.string "Double battles are a much greater\n"
	.string "show of technique.$"

DewfordTown_NewGym_Text_JocelynIntro:
	.string "Come on, team! Let's do this!$"

DewfordTown_NewGym_Text_JocelynDefeat:
	.string "Feeling sleepy…$"

DewfordTown_NewGym_Text_JocelynPostBattle:
	.string "It's really easy to just doze\n"
	.string "off at a beach.$"

DewfordTown_NewGym_Text_CristianIntro:
	.string "If you mean to pass, it has to be\n"
	.string "through us!$"

DewfordTown_NewGym_Text_CristianDefeat:
	.string "Wow!\n"
	.string "Totally overwhelmed!$"

DewfordTown_NewGym_Text_CristianPostBattle:
	.string "You got me!\n"
	.string "Go get that Badge!$"

DewfordTown_NewGym_Text_LilithIntro:
	.string "Ufufu…\n"
	.string "Enjoying the vacation?$"

DewfordTown_NewGym_Text_LilithDefeat:
	.string "Oh, you…\n"
	.string "How very strong.$"

DewfordTown_NewGym_Text_LilithPostBattle:
	.string "The Gym Leaders await.$"

DewfordTown_NewGym_Text_Rocks:
	.string "Phew…\p"
	.string "Clearing these is tricky.\n"
	.string "Hard to get equipment in here.$"

DewfordTown_NewGym_Text_Relax:
	.string "Haah…\n"
	.string "Feels nice to take a break…$"

DewfordTown_NewGym_Text_GymStatue:
	.string "Dewford Town Pokémon Gym\p"
	.string "Crush Cards' Certified Trainers:\n"
	.string "Ruggles$"

DewfordTown_NewGym_Text_GymStatueCertified:
	.string "Dewford Town Pokémon Gym\p"
	.string "Crush Cards' Certified Trainers:\n"
	.string "Ruggles, {PLAYER}$"

