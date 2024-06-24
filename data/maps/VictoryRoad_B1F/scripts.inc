VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "The thought that I'm getting closer to\n"
	.string "the top table…\p"
	.string "I'm getting stage fright.$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "I couldn't do a thing!$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "What a letdown…$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "Hey! I'll give you a hint about\n"
	.string "the League if you beat me!$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Wow! Okay, you earned that hint.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "One of them uses the same type as\n"
	.string "a Gym Leader.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "This isn't the goal. It's only a trial\n"
	.string "on the way to Table 1.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "That's the way!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "You'll do fine, for sure!\n"
	.string "Unless you brick like a motherfucker!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "Now this looks promising.$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "I've never met anyone like you before.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Even outside of battle, I sense\n"
	.string "incredible potential from you.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Might do a profile and show y'all\n"
	.string "the guu.$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Bro, I'm sick!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Ass eff set 4 response? JAJA$"

