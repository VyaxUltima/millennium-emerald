RustboroCity_House2_MapScripts::
	.byte 0

RustboroCity_House2_EventScript_LittleGirl::
	msgbox RustboroCity_House2_Text_RoxanneKnowsALot, MSGBOX_NPC
	end

RustboroCity_House2_EventScript_IVChecker::
	lock
	faceplayer
	bufferpartymonnick 0, 0
	msgbox RustboroCity_House2_Text_IVChecker_1, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetHpIV
	buffernumberstring 0, VAR_RESULT
	msgbox RustboroCity_House2_Text_IVChecker_2, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetAtkIV
	buffernumberstring 0, VAR_RESULT
	msgbox RustboroCity_House2_Text_IVChecker_3, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetDefIV
	buffernumberstring 0, VAR_RESULT
	msgbox RustboroCity_House2_Text_IVChecker_4, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetSpAtkIV
	buffernumberstring 0, VAR_RESULT
	msgbox RustboroCity_House2_Text_IVChecker_5, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetSpDefIV
	buffernumberstring 0, VAR_RESULT
	msgbox RustboroCity_House2_Text_IVChecker_6, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetSpeedIV
	buffernumberstring 0, VAR_RESULT
	msgbox RustboroCity_House2_Text_IVChecker_7, MSGBOX_DEFAULT
	release
	end

RustboroCity_House2_Text_IVChecker_1:
	.string "I can use this small device I have\n"
	.string "to determine your Pokémon's IVs.\p"
	.string "Let's see…\n"
	.string "Your {STR_VAR_1}'s IVs…$"

RustboroCity_House2_Text_IVChecker_2:
	.string "The HP IV is {STR_VAR_1}.$"

RustboroCity_House2_Text_IVChecker_3:
	.string "The Attack IV is {STR_VAR_1}.$"

RustboroCity_House2_Text_IVChecker_4:
	.string "The Defense IV is {STR_VAR_1}.$"

RustboroCity_House2_Text_IVChecker_5:
	.string "The Special Attack IV is {STR_VAR_1}.$"

RustboroCity_House2_Text_IVChecker_6:
	.string "The Special Defense IV is {STR_VAR_1}.$"

RustboroCity_House2_Text_IVChecker_7:
	.string "The Speed IV is {STR_VAR_1}.\p"
	.string "Yep, that's what they are.$"

RustboroCity_House2_Text_RoxanneKnowsALot:
	.string "Farfa, the Gym Leader, really knows\n"
	.string "a lot about Burning Abyss.\p"
	.string "Not so much about math.$"

