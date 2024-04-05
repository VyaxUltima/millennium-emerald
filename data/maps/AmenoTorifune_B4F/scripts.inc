.set LOCALID_MIRORB, 1

AmenoTorifune_B4F_MapScripts::
	.byte 0

AmenoTorifune_B4F_EventScript_MirorBEncounter::
	lockall
	addobject LOCALID_MIRORB
	msgbox AmenoTorifune_B4F_Text_Fuhohoho, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MIRORB, AmenoTorifune_B4F_Movement_MirorBEnter
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox AmenoTorifune_B4F_Text_MirorBChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ROSE_2, AmenoTorifune_B4F_Text_MirorBDefeated
	msgbox AmenoTorifune_B4F_Text_MirorBAfterBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MIRORB, AmenoTorifune_B4F_Movement_MirorBExit
	waitmovement 0
	removeobject LOCALID_MIRORB
	setvar VAR_AMENO_TORIFUNE_MIROR_B, 1
	releaseall
	end

AmenoTorifune_B4F_Movement_MirorBEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

AmenoTorifune_B4F_Movement_MirorBExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

AmenoTorifune_B4F_Text_Fuhohoho:
	.string "Fuhohoho!$"

AmenoTorifune_B4F_Text_MirorBChallenge:
	.string "Miror B: Well, if it isn't the\n"
	.string "travelling trainer!\p"
	.string "Hoenn seems to have many secrets\n"
	.string "under lock, and my moves are the key!\p"
	.string "I may have lost once before,\n"
	.string "but now this is my dance floor!\p"
	.string "This time, I'll blow you away!\n"
	.string "Let the music play!$"

AmenoTorifune_B4F_Text_MirorBDefeated:
	.string "I just can't, no!\n"
	.string "I just can't match your tempo!$"

AmenoTorifune_B4F_Text_MirorBAfterBattle:
	.string "Miror B: This just won't do!\n"
	.string "That puts my record at 0-2!\p"
	.string "But, I can admit when I'm\n"
	.string "thoroughly outmatched at battles.\p"
	.string "Go ahead, travelling trainer!\p"
	.string "You've won this race,\n"
	.string "now seek out what you chase!\p"
	.string "Fuhohoho!$"

