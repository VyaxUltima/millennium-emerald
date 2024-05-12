DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Gorge your eyes on this!\p"
	.string "It's a Silk Scarf. It's right at the\n"
	.string "cutting edge of fashion.\p"
	.string "I received it from a man named Flynn…\p"
	.string "Anyway, I'd like you to have it.$"

DewfordTown_House2_Text_NoRoom:
	.string "Oh, you don't have room?\p"
	.string "This Scarf is a must-have!\n"
	.string "Even if you're not a demon-hunter.$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "The Silk Scarf raises the power of\n"
	.string "Normal-type moves.\p"
	.string "It's a marvelous Scarf that will go\n"
	.string "with almost all Pokémon!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Wow, you bothered to cross the sea\n"
	.string "to visit Dewford?\p"
	.string "Did you maybe come here because you\n"
	.string "heard about Marincess combos?\p"
	.string "He's so cool…\n"
	.string "Everyone idolizes him.$"

