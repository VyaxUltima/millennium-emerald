.set LOCALID_GYM_TRAINER, 3

LavaridgeTown_NewGym_MapScripts::
	.byte 0

LavaridgeTown_NewGym_EventScript_SetupTrainerGfx::
	switch VAR_LAVARIDGE_GYM_STATE
	case 0, LavaridgeTown_NewGym_EventScript_AlbazGfx
	case 1, LavaridgeTown_NewGym_EventScript_CartesiaGfx
	case 2, LavaridgeTown_NewGym_EventScript_QuemGfx
	case 3, LavaridgeTown_NewGym_EventScript_AluberGfx
	case 4, LavaridgeTown_NewGym_EventScript_SkarlonGfx
	end

LavaridgeTown_NewGym_EventScript_AlbazGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_3
	return

LavaridgeTown_NewGym_EventScript_CartesiaGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_GIRL_2
	return

LavaridgeTown_NewGym_EventScript_QuemGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_WOMAN_1
	return

LavaridgeTown_NewGym_EventScript_AluberGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	return

LavaridgeTown_NewGym_EventScript_SkarlonGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_FLANNERY
	return

LavaridgeTown_NewGym_EventScript_EnterArena::
	lockall
	msgbox LavaridgeTown_NewGym_Text_EnterArena, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavaridgeTown_NewGym_EventScript_BattleTime
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_NewGym_EventScript_StepBack
	end

LavaridgeTown_NewGym_EventScript_BattleTime::
	closemessage
	releaseall
	end

LavaridgeTown_NewGym_EventScript_StepBack::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_MovementStepBack
	waitmovement 0
	releaseall
	end

LavaridgeTown_NewGym_MovementStepBack:
	walk_left
	step_end

LavaridgeTown_NewGym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_NewGym_EventScript_GymStatueCertified
	goto LavaridgeTown_NewGym_EventScript_GymStatue
	end

LavaridgeTown_NewGym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_NewGym_EventScript_GymStatueCertified
	goto LavaridgeTown_NewGym_EventScript_GymStatue
	end

LavaridgeTown_NewGym_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_NewGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_NewGym_EventScript_GymStatue::
	msgbox LavaridgeTown_NewGym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_NewGym_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_NewGym_EventScript_Congratulator
	goto LavaridgeTown_NewGym_EventScript_Explainer
	end
	
LavaridgeTown_NewGym_EventScript_Explainer::
	msgbox LavaridgeTown_NewGym_Text_ExplainGym, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_NewGym_EventScript_Congratulator::
	msgbox LavaridgeTown_NewGym_Text_Congrats, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_NewGym_Text_EnterArena:
	.string "Will you enter the arena?$"

LavaridgeTown_NewGym_Text_GymStatue:
	.string "Lavaridge Town Pokémon Gym\p"
	.string "Skarlon's Certified Trainers:\n"
	.string "Ruggles$"

LavaridgeTown_NewGym_Text_GymStatueCertified:
	.string "Lavaridge Town Pokémon Gym\p"
	.string "Skarlon's Certified Trainers:\n"
	.string "Ruggles, {PLAYER}$"

LavaridgeTown_NewGym_Text_ExplainGym:
	.string "Hey there, Trainer!\p"
	.string "Let me explain to you how this\n"
	.string "Gym here works.\p"
	.string "There's four Trainers to beat before\n"
	.string "you can face the Leader.\p"
	.string "To battle them, take your place on\n"
	.string "the red podium of the arena.\p"
	.string "Once all four have been beaten,\n"
	.string "you can go for your Gym Badge.\l"
	.string "Good luck!$"

LavaridgeTown_NewGym_Text_Congrats::
	.string "Hey, you beat Skarlon!\n"
	.string "Congratulations!$"

