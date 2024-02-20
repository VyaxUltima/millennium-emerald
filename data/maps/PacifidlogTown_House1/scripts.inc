.set LOCALID_CYNTHIA, 1

@ The beginning of the end for any motherfucker that walks into this house.
PacifidlogTown_House1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PacifidlogTown_House1_OnFrame
	.byte 0

PacifidlogTown_House1_OnFrame::
	map_script_2 VAR_DEFEATED_SCC, 0, PacifidlogTown_House1_ImminentDeath
	.2byte 0

PacifidlogTown_House1_ImminentDeath::
	lockall
	playse SE_PIN
	applymovement LOCALID_CYNTHIA, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_CYNTHIA, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CYNTHIA, Common_Movement_Delay48
	waitmovement 0
	playbgm MUS_IMMINENT_DEATH, FALSE
	msgbox PacifidlogTown_House1_Text_TimeToDie, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TORCHIC, PacifidlogTown_House1_Text_Survival
	msgbox PacifidlogTown_House1_Text_Congrats, MSGBOX_DEFAULT
	call PacifidlogTown_House1_EventScript_GiveGracidea
	msgbox PacifidlogTown_House1_Text_GracideaExplanation, MSGBOX_DEFAULT
	setvar VAR_DEFEATED_SCC, 1
	closemessage
	releaseall
	end

PacifidlogTown_House1_EventScript_Cynthia::
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_GiveGracidea::
	giveitem ITEM_GRACIDEA
	return

PacifidlogTown_House1_Text_RegiStory:
	.string "Cynthia: You are certainly a\n"
	.string "Trainer to be reckoned with.$"

PacifidlogTown_House1_Text_TimeToDie:
	.string "Ah, hello. You are?\p"
	.string "{PLAYER}… I'll remember that.\n"
	.string "My name is Cynthia.\p"
	.string "I have an insatiable curiosity for\n"
	.string "researching Pokémon myths and stories.\p"
	.string "However, I've found myself at a bit\n"
	.string "of a standstill on my latest work.\p"
	.string "Unfortunately, that leaves me with\n"
	.string "little to do… other than battle.\p"
	.string "I hope you don't mind indulging me.\p"
	.string "I, Cynthia, Sinnoh's Champion,\n"
	.string "will not hold back!$"

PacifidlogTown_House1_Text_Survival:
	.string "My heart is pounding.\p"
	.string "I haven't had a battle that\n"
	.string "good in a long time.\p"
	.string "You are certainly a\n"
	.string "skilled Trainer.$"

PacifidlogTown_House1_Text_Congrats:
	.string "Cynthia: That was magnificent.\n"
	.string "Sinnoh, Unova, and now Hoenn…\p"
	.string "Every region has their own roster\n"
	.string "of incredible Trainers.\p"
	.string "As a token of gratitude,\n"
	.string "I'd like you to have this.$"

PacifidlogTown_House1_Text_GracideaExplanation:
	.string "That is a Gracidea flower.\p"
	.string "It has a special connection to a\n"
	.string "Pokémon called Shaymin.\p"
	.string "Gracideas are often given as gifts\n"
	.string "to convey a feeling of gratitude.\p"
	.string "I think it fitting that I gift\n"
	.string "one of these blooms to you.$"

