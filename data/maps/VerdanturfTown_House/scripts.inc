VerdanturfTown_House_MapScripts::
	.byte 0

VerdanturfTown_House_EventScript_Woman1::
	msgbox VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague, MSGBOX_NPC
	end

VerdanturfTown_House_EventScript_Woman2::
	msgbox VerdanturfTown_House_Text_DefeatEliteFourInARow, MSGBOX_NPC
	end

VerdanturfTown_House_Photo::
	msgbox VerdanturfTown_House_Text_Lily, MSGBOX_SIGN
	clearflag FLAG_HIDE_MT_PYRE_VYAX
	end

VerdanturfTown_House_Desktop::
	msgbox VerdanturfTown_House_Text_Development, MSGBOX_SIGN
	end

VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague:
	.string "Far away, deep in EVER GRANDE CITY,\n"
	.string "is the POKéMON LEAGUE.\p"
	.string "The TRAINERS who gather there are\n"
	.string "all frighteningly well skilled.$"

VerdanturfTown_House_Text_DefeatEliteFourInARow:
	.string "In the POKéMON LEAGUE, I think the\n"
	.string "rules say that you have to battle the\l"
	.string "ELITE FOUR all in a row.\p"
	.string "If you lose to any of them, you have\n"
	.string "to begin your challenge again from the\l"
	.string "first one.$"

VerdanturfTown_House_Text_Lily:
	.string "It appears to be a photo of a cat.\n"
	.string "There's something written under it.\p"
	.string "“Lily”\n"
	.string "September 22, 2012 - March 17, 2024\p"
	.string "…You suspect the owner loved their\n"
	.string "cat very much.$"

VerdanturfTown_House_Text_Development:
	.string "There's a ton of files.\n"
	.string "You can read various bits of code…\p"
	.string "The open project appears to be\n"
	.string "called Millennium Emerald.\p"
	.string "Perhaps this workspace is used by\n"
	.string "the lead developer.$"

