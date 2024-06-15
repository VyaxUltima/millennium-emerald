.set LOCALID_GYM_SKARLON_WATCHER, 1
.set LOCALID_GYM_ALBAZ, 3
.set LOCALID_GYM_CARTESIA, 4
.set LOCALID_GYM_QUEM, 5
.set LOCALID_GYM_ALUBER, 6
.set LOCALID_GYM_SKARLON_BATTLER, 7

LavaridgeTown_NewGym_MapScripts::
	.byte 0

LavaridgeTown_NewGym_EventScript_EnterArena::
	lockall
	msgbox LavaridgeTown_NewGym_Text_EnterArena, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavaridgeTown_NewGym_EventScript_BattleTime
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_NewGym_EventScript_StepBack
	end

LavaridgeTown_NewGym_EventScript_BattleTime::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerEnterArena
	waitmovement 0
	switch VAR_LAVARIDGE_GYM_STATE
	case 0, LavaridgeTown_NewGym_EventScript_AlbazBattle
	case 1, LavaridgeTown_NewGym_EventScript_CartesiaBattle
	case 2, LavaridgeTown_NewGym_EventScript_QuemBattle
	case 3, LavaridgeTown_NewGym_EventScript_AluberBattle
	case 4, LavaridgeTown_NewGym_EventScript_SkarlonBattle
	releaseall
	end

LavaridgeTown_NewGym_EventScript_AlbazBattle::
	addobject LOCALID_GYM_ALBAZ
	applymovement LOCALID_GYM_ALBAZ, LavaridgeTown_NewGym_Movement_OpponentEnterArena
	waitmovement 0
	msgbox LavaridgeTown_NewGym_Text_AlbazChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerBattleStep
	applymovement LOCALID_GYM_ALBAZ, LavaridgeTown_NewGym_Movement_OpponentBattleStep
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	trainerbattle_no_intro TRAINER_JACE, LavaridgeTown_NewGym_Text_AlbazDefeated
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerBattleFinish
	applymovement LOCALID_GYM_ALBAZ, LavaridgeTown_NewGym_Movement_OpponentBattleFinish
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	msgbox LavaridgeTown_NewGym_Text_AlbazPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GYM_ALBAZ, LavaridgeTown_NewGym_Movement_OpponentExitArena
	waitmovement 0
	removeobject LOCALID_GYM_ALBAZ
	setvar VAR_LAVARIDGE_GYM_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerExitArena
	waitmovement 0
	releaseall
	end

LavaridgeTown_NewGym_EventScript_CartesiaBattle::
	addobject LOCALID_GYM_CARTESIA
	applymovement LOCALID_GYM_CARTESIA, LavaridgeTown_NewGym_Movement_OpponentEnterArena
	waitmovement 0
	msgbox LavaridgeTown_NewGym_Text_CartesiaChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerBattleStep
	applymovement LOCALID_GYM_CARTESIA, LavaridgeTown_NewGym_Movement_OpponentBattleStep
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	trainerbattle_no_intro TRAINER_COLE, LavaridgeTown_NewGym_Text_CartesiaDefeated
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerBattleFinish
	applymovement LOCALID_GYM_CARTESIA, LavaridgeTown_NewGym_Movement_OpponentBattleFinish
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	msgbox LavaridgeTown_NewGym_Text_CartesiaPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GYM_CARTESIA, LavaridgeTown_NewGym_Movement_OpponentExitArena
	waitmovement 0
	removeobject LOCALID_GYM_CARTESIA
	setvar VAR_LAVARIDGE_GYM_STATE, 2
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerExitArena
	waitmovement 0
	releaseall
	end

LavaridgeTown_NewGym_EventScript_QuemBattle::
	addobject LOCALID_GYM_QUEM
	applymovement LOCALID_GYM_QUEM, LavaridgeTown_NewGym_Movement_OpponentEnterArena
	waitmovement 0
	msgbox LavaridgeTown_NewGym_Text_QuemChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerBattleStep
	applymovement LOCALID_GYM_QUEM, LavaridgeTown_NewGym_Movement_OpponentBattleStep
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	trainerbattle_no_intro TRAINER_DANIELLE, LavaridgeTown_NewGym_Text_QuemDefeated
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerBattleFinish
	applymovement LOCALID_GYM_QUEM, LavaridgeTown_NewGym_Movement_OpponentBattleFinish
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	msgbox LavaridgeTown_NewGym_Text_QuemPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GYM_QUEM, LavaridgeTown_NewGym_Movement_OpponentExitArena
	waitmovement 0
	removeobject LOCALID_GYM_QUEM
	setvar VAR_LAVARIDGE_GYM_STATE, 3
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerExitArena
	waitmovement 0
	releaseall
	end

LavaridgeTown_NewGym_EventScript_AluberBattle::
	addobject LOCALID_GYM_ALUBER
	applymovement LOCALID_GYM_ALUBER, LavaridgeTown_NewGym_Movement_OpponentEnterArena
	waitmovement 0
	msgbox LavaridgeTown_NewGym_Text_AluberChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerBattleStep
	applymovement LOCALID_GYM_ALUBER, LavaridgeTown_NewGym_Movement_OpponentBattleStep
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	trainerbattle_no_intro TRAINER_AXLE, LavaridgeTown_NewGym_Text_AluberDefeated
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerBattleFinish
	applymovement LOCALID_GYM_ALUBER, LavaridgeTown_NewGym_Movement_OpponentBattleFinish
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	msgbox LavaridgeTown_NewGym_Text_AluberPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GYM_ALUBER, LavaridgeTown_NewGym_Movement_OpponentExitArena
	waitmovement 0
	removeobject LOCALID_GYM_ALUBER
	applymovement LOCALID_GYM_SKARLON_WATCHER, LavaridgeTown_NewGym_Movement_SkarlonVanish
	waitmovement 0
	setflag FLAG_HIDE_SKARLON_LAVARIDGE_GYM
	setvar VAR_LAVARIDGE_GYM_STATE, 4
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerExitArena
	waitmovement 0
	releaseall
	end

LavaridgeTown_NewGym_EventScript_SkarlonBattle::
	addobject LOCALID_GYM_SKARLON_BATTLER
	applymovement LOCALID_GYM_SKARLON_BATTLER, LavaridgeTown_NewGym_Movement_OpponentEnterArena
	waitmovement 0
	msgbox LavaridgeTown_NewGym_Text_SkarlonChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerBattleStep
	applymovement LOCALID_GYM_SKARLON_BATTLER, LavaridgeTown_NewGym_Movement_OpponentBattleStep
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	trainerbattle_no_intro TRAINER_FLANNERY_1, LavaridgeTown_NewGym_Text_SkarlonDefeated
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerBattleFinish
	applymovement LOCALID_GYM_SKARLON_BATTLER, LavaridgeTown_NewGym_Movement_OpponentBattleFinish
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	message LavaridgeTown_NewGym_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_NewGym_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_NewGym_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_NewGym_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	msgbox LavaridgeTown_NewGym_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GYM_SKARLON_BATTLER, LavaridgeTown_NewGym_Movement_SkarlonExitArena
	waitmovement 0
	removeobject LOCALID_GYM_SKARLON_BATTLER
	setvar VAR_LAVARIDGE_GYM_ARENA_TRIGGER, 1
	setvar VAR_LAVARIDGE_GYM_STATE, 5
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_PlayerExitArena
	waitmovement 0
	releaseall
	end

LavaridgeTown_NewGym_EventScript_GiveOverheat::
	giveitem ITEM_TM78
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_NewGym_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM50
	return

LavaridgeTown_NewGym_EventScript_StepBack::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_NewGym_Movement_StepBack
	waitmovement 0
	releaseall
	end

@ Movement commands for arena

LavaridgeTown_NewGym_Movement_PlayerEnterArena:
	walk_right
	walk_right
	step_end

LavaridgeTown_NewGym_Movement_OpponentEnterArena:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_NewGym_Movement_PlayerBattleStep:
	walk_right
	step_end

LavaridgeTown_NewGym_Movement_OpponentBattleStep:
	walk_left
	step_end

LavaridgeTown_NewGym_Movement_PlayerBattleFinish:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LavaridgeTown_NewGym_Movement_OpponentBattleFinish:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

LavaridgeTown_NewGym_Movement_PlayerExitArena:
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_NewGym_Movement_OpponentExitArena:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LavaridgeTown_NewGym_Movement_SkarlonExitArena:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_NewGym_Movement_StepBack:
	walk_left
	step_end

LavaridgeTown_NewGym_Movement_SkarlonVanish:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	set_invisible
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

@ Text

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

LavaridgeTown_NewGym_Text_Congrats:
	.string "Hey, you beat Skarlon!\n"
	.string "Congratulations!$"

LavaridgeTown_NewGym_Text_AlbazChallenge:
	.string "I'll show the Gym Leader how\n"
	.string "much I've trained!$"

LavaridgeTown_NewGym_Text_AlbazDefeated:
	.string "Wow, you're strong.$"

LavaridgeTown_NewGym_Text_AlbazPostBattle:
	.string "Not bad. But not as good as\n"
	.string "our Gym Leader!$"

LavaridgeTown_NewGym_Text_CartesiaChallenge:
	.string "Beating all of us won't be easy.\n"
	.string "I'm up next!$"

LavaridgeTown_NewGym_Text_CartesiaDefeated:
	.string "Not enough…$"

LavaridgeTown_NewGym_Text_CartesiaPostBattle:
	.string "Hm, maybe you can take on\n"
	.string "our Gym Leader after all.$"

LavaridgeTown_NewGym_Text_QuemChallenge:
	.string "You're halfway to winning our\n"
	.string "Gym Leader's approval.\p"
	.string "Don't give up now!$"

LavaridgeTown_NewGym_Text_QuemDefeated:
	.string "I lost… you're good.$"

LavaridgeTown_NewGym_Text_QuemPostBattle:
	.string "Just one of us left now.\n"
	.string "Think you can do it?$"

LavaridgeTown_NewGym_Text_AluberChallenge:
	.string "You want to challenge Skarlon, huh?\p"
	.string "I'm the last line of defense.\n"
	.string "Now bring it!$"

LavaridgeTown_NewGym_Text_AluberDefeated:
	.string "Ach… that was intense.$"

LavaridgeTown_NewGym_Text_AluberPostBattle:
	.string "Well, that makes four.\p"
	.string "Only one thing between you\n"
	.string "and that badge now!$"

LavaridgeTown_NewGym_Text_SkarlonChallenge:
	.string "Skarlon: Congratulations.\n"
	.string "You managed to play through a\l"
	.string "whole Branded combo.\p"
	.string "Don't take this combo lightly\n"
	.string "just because it's normal.\p"
	.string "I'll demonstrate what the Normal\n"
	.string "type is capable of!\p"
	.string "…Just don't have Ash.$"

LavaridgeTown_NewGym_Text_SkarlonDefeated:
	.string "Yep, that's game.\n"
	.string "Alright, here.$"

LavaridgeTown_NewGym_Text_ReceivedHeatBadge:
	.string "{PLAYER} received the Branded Badge\n"
	.string "from Skarlon.$"

LavaridgeTown_NewGym_Text_ExplainHeatBadgeTakeThis:
	.string "That Branded Badge means all Pokémon\n"
	.string "obey up to Level 45, even if they're\l"
	.string "trades from other people.\p"
	.string "You can also now use Strength\n"
	.string "outside of battle.\p"
	.string "Also, here's a TM.\n"
	.string "Internalized screams externalized.$"

LavaridgeTown_NewGym_Text_ExplainOverheat:
	.string "That TM78 contains Hyper Voice.\p"
	.string "It's a sound-based move, so it will\n"
	.string "bypass the opponent's Substitutes.\p"
	.string "Also, it can hit both of your\n"
	.string "opponents in a double battle.$"

LavaridgeTown_NewGym_Text_RegisteredFlannery:
	.string "Registered Gym Leader Skarlon\n"
	.string "in the Pokénav.$"

LavaridgeTown_NewGym_Text_FlanneryPostBattle:
	.string "Did someone say walk?$"

