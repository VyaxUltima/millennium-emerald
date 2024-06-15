SootopolisCity_NewGym_1F_MapScripts::
	.byte 0

SootopolisCity_NewGym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_NewGym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_NewGym_1F_EventScript_GymStatue
	end

SootopolisCity_NewGym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_NewGym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_NewGym_1F_EventScript_GymStatue
	end

SootopolisCity_NewGym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_NewGym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_NewGym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_NewGym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_NewGym_1F_Text_GymStatue:
	.string "Sootopolis City Pokémon Gym$"

SootopolisCity_NewGym_1F_Text_GymStatueCertified:
	.string "Sootopolis City Pokémon Gym\p"
	.string "Eva's Certified Trainers:\n"
	.string "{PLAYER}$"

