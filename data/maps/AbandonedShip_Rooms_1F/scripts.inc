AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Ships of this sort are rare, so I'm\n"
	.string "taking a look around.\p"
	.string "There's loot to be had.$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "What on earth would compel you to\n"
	.string "come here? This place blows.$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Blown away…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "The man next door…\p"
	.string "He says he's just sightseeing,\n"
	.string "but he looks like a looter.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "You're such a tough Trainer!\n"
	.string "Let me register you as a memento!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "What on earth would compel you to\n"
	.string "come back? You must really be curious!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Aren't you too strong?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "I'm sure that man's up to something!\n"
	.string "He just acts so suspiciously!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Waaah!\n"
	.string "I've been found! …Huh?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Oh, you're not my mom.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "Don't make a joke about my mom!$"

