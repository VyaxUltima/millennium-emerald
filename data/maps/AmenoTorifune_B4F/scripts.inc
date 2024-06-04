.set LOCALID_MIRORB, 1

AmenoTorifune_B4F_MapScripts::
	.byte 0

AmenoTorifune_B4F_EventScript_Bingo::
	trainerbattle_single TRAINER_RICKY_2, AmenoTorifune_B4F_Text_BingoIntro, AmenoTorifune_B4F_Text_BingoDefeated
	msgbox AmenoTorifune_B4F_Text_BingoPostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B4F_EventScript_Plaguey::
	trainerbattle_single TRAINER_RICKY_3, AmenoTorifune_B4F_Text_PlagueyIntro, AmenoTorifune_B4F_Text_PlagueyDefeated
	msgbox AmenoTorifune_B4F_Text_PlagueyPostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B4F_EventScript_Noelle::
	trainerbattle_single TRAINER_RICKY_4, AmenoTorifune_B4F_Text_NoelleIntro, AmenoTorifune_B4F_Text_NoelleDefeated
	msgbox AmenoTorifune_B4F_Text_NoellePostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B4F_EventScript_Alex::
	trainerbattle_single TRAINER_RICKY_5, AmenoTorifune_B4F_Text_AlexIntro, AmenoTorifune_B4F_Text_AlexDefeated
	msgbox AmenoTorifune_B4F_Text_AlexPostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B4F_EventScript_FindPowerHerb::
	finditem ITEM_POWER_HERB
	end

AmenoTorifune_B4F_EventScript_FindPPMax::
	finditem ITEM_PP_MAX
	end

AmenoTorifune_B4F_EventScript_FindShellBell::
	finditem ITEM_SHELL_BELL
	end

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

AmenoTorifune_B4F_Text_BingoIntro:
	.string "Hello there.$"

AmenoTorifune_B4F_Text_BingoDefeated:
	.string "Well, I guess you got me.$"

AmenoTorifune_B4F_Text_BingoPostBattle:
	.string "According to all known laws of aviation,\n"
	.string "a Ribombee shouldn't be able to fly.$"

AmenoTorifune_B4F_Text_PlagueyIntro:
	.string "Can you help me test out\n"
	.string "this new fish I caught?$"

AmenoTorifune_B4F_Text_PlagueyDefeated:
	.string "Aww fuck, that didn't go\n"
	.string "as planned…$"

AmenoTorifune_B4F_Text_PlagueyPostBattle:
	.string "Well, that was fun! If you see\n"
	.string "my husband, tell him I stole-\p"
	.string "I mean, bought a new Hawaiian for him!$"

AmenoTorifune_B4F_Text_NoelleIntro:
	.string "Frittata, strike them down!$"

AmenoTorifune_B4F_Text_NoelleDefeated:
	.string "Not fair! I misclicked!$"

AmenoTorifune_B4F_Text_NoellePostBattle:
	.string "Best two out of three?$"

AmenoTorifune_B4F_Text_AlexIntro:
	.string "It might be time for ol' reliable.$"

AmenoTorifune_B4F_Text_AlexDefeated:
	.string "Sorry for interrupting.$"

AmenoTorifune_B4F_Text_AlexPostBattle:
	.string "Your honor, I'd like to activate\n"
	.string "Crossout in response to this result.$"

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

