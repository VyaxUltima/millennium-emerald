SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_Gentleman::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "Are you familiar with how a Pokémon's\n"
	.string "nature affects their battling?\p"
	.string "You can check how they're influenced\n"
	.string "on the summary screen.\p"
	.string "If a stat is colored red, then the\n"
	.string "nature increases that stat.\p"
	.string "Likewise, a stat colored blue means\n"
	.string "the nature decreases that stat.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "You're a Duelist, aren't you?\p"
	.string "Curse of Ra$"

