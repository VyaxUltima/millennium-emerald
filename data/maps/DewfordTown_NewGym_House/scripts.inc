DewfordTown_NewGym_House_MapScripts::
	.byte 0

DewfordTown_NewGym_House_EventScript_Brawly::
	trainerbattle_double TRAINER_BRAWLY_1, DewfordTown_NewGym_House_Text_BrawlyIntro, DewfordTown_NewGym_House_Text_BrawlyDefeat, DewfordTown_NewGym_House_Text_BrawlyNeedTwoMons, DewfordTown_NewGym_House_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_NewGym_House_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM08, DewfordTown_NewGym_House_EventScript_GiveBulkUp2
	msgbox DewfordTown_NewGym_House_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_NewGym_House_EventScript_BrawlyDefeated::
	message DewfordTown_NewGym_House_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_NewGym_House_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_NewGym_House_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_NewGym_House_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_NewGym_House_EventScript_GiveBulkUp::
	giveitem ITEM_TM03
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_NewGym_House_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM08
	return

DewfordTown_NewGym_House_EventScript_GiveBulkUp2:
	giveitem ITEM_TM03
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_NewGym_House_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM08
	release
	end

DewfordTown_NewGym_House_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_NewGym_House_Text_BrawlyPreRematch, DewfordTown_NewGym_House_Text_BrawlyRematchDefeat, DewfordTown_NewGym_House_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_NewGym_House_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_NewGym_House_Text_BrawlyIntro:
	.string "Logan: Hi there! {PLAYER}, right?\n"
	.string "Bryan: Did we surprise you?\p"
	.string "Bryan: Well, here you have it!\n"
	.string "Dewford's Gym is run by two!\p"
	.string "Logan: I hope you enjoyed hanging\n"
	.string "out on the beach a little bit.\p"
	.string "Bryan: But now, the tide's coming in.\n"
	.string "Logan: So, care for a double battle?\p"
	.string "Logan: We'll both take you on!\n"
	.string "Bryan: We'll both take you on!$"

DewfordTown_NewGym_House_Text_BrawlyNeedTwoMons:
	.string "Logan: Ooh, sorry!\n"
	.string "Bryan: We only do double battles.$"

DewfordTown_NewGym_House_Text_BrawlyDefeat:
	.string "Logan: Aww, no way!\n"
	.string "Bryan: Well, we did our best.$"

DewfordTown_NewGym_House_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} received the Virus Badge\n"
	.string "from Crush Cards.$"

DewfordTown_NewGym_House_Text_KnuckleBadgeInfoTakeThis:
	.string "Logan: Our Virus Badge means Pokémon\n"
	.string "up to Level 30, even those you get in\l"
	.string "trades, obey without question.\p"
	.string "Bryan: A Badge alone's not all we\n"
	.string "have for you, either. Here!$"

DewfordTown_NewGym_House_Text_ExplainBulkUp:
	.string "Bryan: TM03 holds Water Pulse.\p"
	.string "Logan: It's a solid attack, and\n"
	.string "it might confuse your opponent!\p"
	.string "… … … … … …$"

DewfordTown_NewGym_House_Text_RegisteredBrawly:
	.string "Registered Crush Cards\n"
	.string "in the Pokénav.$"

DewfordTown_NewGym_House_Text_BrawlyPostBattle:
	.string "Bryan: What to play tonight?\n"
	.string "Logan: Hopefully pairings go our way.$"

DewfordTown_NewGym_House_Text_BrawlyPreRematch:
	.string "BRAWLY: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Show me how much higher\n"
	.string "you've gone!$"

DewfordTown_NewGym_House_Text_BrawlyRematchDefeat:
	.string "Wow!\n"
	.string "Swamped again!$"

DewfordTown_NewGym_House_Text_BrawlyPostRematch:
	.string "BRAWLY: Battling is vast and it's deep.\n"
	.string "You can't see the bottom.\l"
	.string "It's just like the sea of HOENN!$"

DewfordTown_NewGym_House_Text_BrawlyRematchNeedTwoMons:
	.string "BRAWLY: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Oh? You only have one POKéMON\n"
	.string "that can battle.\p"
	.string "I'm sorry, but I'd like you to come back\n"
	.string "with at least two POKéMON.$"
