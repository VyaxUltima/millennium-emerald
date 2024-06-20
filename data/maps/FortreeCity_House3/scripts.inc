FortreeCity_House3_MapScripts::
	.byte 0

FortreeCity_House3_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SKILL_MANUAL, FortreeCity_House3_EventScript_ExplainSkillManual
	msgbox FortreeCity_House3_Text_WantYouToHaveSkillManual, MSGBOX_DEFAULT
	giveitem ITEM_SKILL_MANUAL
	goto_if_eq VAR_RESULT, FALSE, FortreeCity_House3_EventScript_NoRoomForBook
	setflag FLAG_RECEIVED_SKILL_MANUAL
	release
	end

FortreeCity_House3_EventScript_NoRoomForBook::
	msgbox FortreeCity_House3_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

FortreeCity_House3_EventScript_ExplainSkillManual::
	msgbox FortreeCity_House3_Text_ExplainSkillManual, MSGBOX_DEFAULT
	release
	end

FortreeCity_House3_Text_WantYouToHaveSkillManual:
	.string "You seem like an experienced Trainer.\p"
	.string "I've been looking for someone who\n"
	.string "could make use of this book.\l"
	.string "It's called a Skill Manual.\p"
	.string "It can be used to change the ability\n"
	.string "of the first Pokémon you obtained,\l"
	.string "provided it has fully evolved.$"

FortreeCity_House3_Text_NoRoom:
	.string "Oh, you don't have room?$"

FortreeCity_House3_Text_ExplainSkillManual:
	.string "Keep in mind that once you use it,\n"
	.string "you can't change the ability back.\p"
	.string "Consider your decision.$"

