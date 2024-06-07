MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_TM70
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Hey there, Trainer!\p"
	.string "The ground should explode!\n"
	.string "Don't you agree?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "You bet, you bet!\p"
	.string "As a fellow explosive ground enjoyer,\n"
	.string "you can have this!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "Special attacking Ground types exist\n"
	.string "too, you know!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "I hope your ground explodes.$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Go after the seafloor Pokémon with\n"
	.string "your new Earth Power.$"

