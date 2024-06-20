SootopolisCity_NewGym_1F_MapScripts::
	.byte 0

SootopolisCity_NewGym_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_NewGym_1F_EventScript_GotYourBadge
	goto SootopolisCity_NewGym_1F_EventScript_GymTheme
	end

SootopolisCity_NewGym_1F_EventScript_GymTheme::
	msgbox SootopolisCity_NewGym_1F_Text_Classrooms, MSGBOX_DEFAULT
	release
	end

SootopolisCity_NewGym_1F_EventScript_GotYourBadge::
	msgbox SootopolisCity_NewGym_1F_Text_AcquiredBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_NewGym_1F_EventScript_Teacher::
	msgbox SootopolisCity_NewGym_1F_Text_Knowledge, MSGBOX_NPC
	end

SootopolisCity_NewGym_1F_EventScript_Student::
	msgbox SootopolisCity_NewGym_1F_Text_StopHittingYourself, MSGBOX_NPC
	end

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

SootopolisCity_NewGym_1F_Text_Classrooms:
	.string "Hello, challenger!\n"
	.string "Welcome to Sootopolis Gym!\p"
	.string "Our Gym Leader is an educator,\n"
	.string "so our Gym's theme is a school!\p"
	.string "There are faculty scattered around\n"
	.string "classrooms in the building.\p"
	.string "There's six rooms, though I'm not\n"
	.string "certain where each of your\l"
	.string "opponents will be.\p"
	.string "Once you beat them, you can try\n"
	.string "to win your Badge.$"

SootopolisCity_NewGym_1F_Text_AcquiredBadge:
	.string "Looks like you beat Eva.\n"
	.string "Well done!$"

SootopolisCity_NewGym_1F_Text_GymStatue:
	.string "Sootopolis City Pokémon Gym$"

SootopolisCity_NewGym_1F_Text_GymStatueCertified:
	.string "Sootopolis City Pokémon Gym\p"
	.string "Eva's Certified Trainers:\n"
	.string "{PLAYER}$"

SootopolisCity_NewGym_1F_Text_Knowledge:
	.string "So, what can you tell me\n"
	.string "about type matchups?$"

SootopolisCity_NewGym_1F_Text_StopHittingYourself:
	.string "Oh, oh! I know!\n"
	.string "Dragons like hitting themselves!$"

