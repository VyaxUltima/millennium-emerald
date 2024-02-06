PetalburgCity_BlackMarket_MapScripts::
	.byte 0

PetalburgCity_BlackMarket_Vendor1::
	lock
	message gText_LookingForSomething
	waitmessage
	pokemart PetalburgCity_BlackMarket_Shop1
	msgbox gText_IfThatsAll, MSGBOX_DEFAULT
	release
	end

PetalburgCity_BlackMarket_Vendor2::
	lock
	message gText_LookingForSomething
	waitmessage
	pokemart PetalburgCity_BlackMarket_Shop2
	msgbox gText_IfThatsAll, MSGBOX_DEFAULT
	release
	end

PetalburgCity_BlackMarket_Vendor3::
	lock
	message gText_LookingForSomething
	waitmessage
	pokemart PetalburgCity_BlackMarket_Shop3
	msgbox gText_IfThatsAll, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_BlackMarket_Shop1:
	.2byte ITEM_TM49 @ Gastro Acid
	.2byte ITEM_TM55 @ Brine
	.2byte ITEM_TM62 @ Silver Wind
	.2byte ITEM_TM63 @ Embargo
	.2byte ITEM_TM66 @ Payback
	.2byte ITEM_TM72 @ Avalanche
	.2byte ITEM_TM74 @ Gyro Ball
	.2byte ITEM_TM77 @ Psych Up
	.2byte ITEM_TM81 @ X-Scissor
	.2byte ITEM_TM86 @ Grass Knot
	.2byte ITEM_TM88 @ Pluck
	.2byte ITEM_TM92 @ Trick Room
	.2byte ITEM_NONE
	release
	end

	.align 2
PetalburgCity_BlackMarket_Shop2:
	.2byte ITEM_BLACK_SLUDGE
	.2byte ITEM_LIGHT_CLAY
	.2byte ITEM_MUSCLE_BAND
	.2byte ITEM_WISE_GLASSES
	.2byte ITEM_WIDE_LENS
	.2byte ITEM_DAMP_ROCK
	.2byte ITEM_HEAT_ROCK
	.2byte ITEM_SMOOTH_ROCK
	.2byte ITEM_ICY_ROCK
	.2byte ITEM_NONE
	release
	end

	.align 2
PetalburgCity_BlackMarket_Shop3:
	.2byte ITEM_PROTECTOR
	.2byte ITEM_MAGMARIZER
	.2byte ITEM_ELECTIRIZER
	.2byte ITEM_REAPER_CLOTH
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_RAZOR_FANG
	.2byte ITEM_RAZOR_CLAW
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_LINKING_CORD
	.2byte ITEM_NONE
	release
	end
