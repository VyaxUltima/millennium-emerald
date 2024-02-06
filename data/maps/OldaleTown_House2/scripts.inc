OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Recently, we've discovered new\n"
	.string "TMs here in Hoenn.\p"
	.string "Far as I recall, there's 92 total.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Some of Hoenn's native TMs have\n"
	.string "been re-programmed.\p"
	.string "Is there a list of the new ones?$"

