MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "The rich atmosphere of the mountain\n"
	.string "has elevated my skill with cards!\p"
	.string "A mere child like you…\n"
	.string "You dream of top tables?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "I drown in self-pity…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "My feature match skills have surely\n"
	.string "grown several times, but…$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahaha!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "Ahahahaha!$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Ahahahaha!"

MtPyre_3F_Text_GabrielleIntro:
	.string "Why have you come here?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "That was amazing!\n"
	.string "You're a very special Trainer.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "Why have I come here?\n"
	.string "You don't need to know.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "Please, I need to see your Pokénav.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Oh, it's you…\p"
	.string "Have you come to show me your grown\n"
	.string "POKéMON?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "How amazing!\n"
	.string "You are a special person.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "POKéMON no longer of this world.\n"
	.string "POKéMON that are with you now.\p"
	.string "And the POKéMON that you will meet\n"
	.string "in the future…\p"
	.string "They are all to be equally cherished.\n"
	.string "I see that you've remembered that.$"

