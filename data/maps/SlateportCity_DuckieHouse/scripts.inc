SlateportCity_DuckieHouse_MapScripts::
	.byte 0

SlateportCity_DuckieHouse_EventScript_Duckie::
	msgbox SlateportCity_DuckieHouse_Text_WatchlistMan, MSGBOX_NPC
	end

SlateportCity_DuckieHouse_EventScript_DuckieComputer::
	msgbox SlateportCity_DuckieHouse_Text_WatchlistMaterial, MSGBOX_NPC
	end

SlateportCity_DuckieHouse_Text_WatchlistMan:
	.string "Hey. Don't look at my PC.\p"
	.string "OH ALSO:\n"
	.string "Hope you have Damp Pokémon. :)$"

SlateportCity_DuckieHouse_Text_WatchlistMaterial:
	.string "Let's see what we have here.\p"
	.string "…Oh.\p"
	.string "Maybe we shouldn't read these\n"
	.string "instructions.$"

