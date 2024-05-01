Route125_BlackMarket_MapScripts::
	.byte 0

Route125_BlackMarket_Vendor1::
	lock
	message gText_LookingForSomething
	waitmessage
	pokemart Route125_BlackMarket_Shop1
	msgbox gText_IfThatsAll, MSGBOX_DEFAULT
	release
	end

Route125_BlackMarket_Vendor2::
	lock
	message gText_LookingForSomething
	waitmessage
	pokemart Route125_BlackMarket_Shop2
	msgbox gText_IfThatsAll, MSGBOX_DEFAULT
	release
	end

Route125_BlackMarket_Vendor3::
	lock
	message gText_LookingForSomething
	waitmessage
	pokemart Route125_BlackMarket_Shop3
	msgbox gText_IfThatsAll, MSGBOX_DEFAULT
	release
	end

	.align 2
Route125_BlackMarket_Shop1:
	.2byte ITEM_TM24 @ Thunderbolt
	.2byte ITEM_TM29 @ Psychic
	.2byte ITEM_TM35 @ Flamethrower
	.2byte ITEM_TM50 @ Overheat
	.2byte ITEM_TM59 @ Dragon Pulse
	.2byte ITEM_TM64 @ Knock Off
	.2byte ITEM_TM75 @ Swords Dance
	.2byte ITEM_TM80 @ Rock Slide
	.2byte ITEM_TM84 @ Poison Jab
	.2byte ITEM_TM90 @ Substitute
	.2byte ITEM_TM91 @ Flash Cannon
	.2byte ITEM_NONE
	release
	end

	.align 2
Route125_BlackMarket_Shop2:
	.2byte ITEM_CHOICE_BAND
	.2byte ITEM_CHOICE_SPECS
	.2byte ITEM_CHOICE_SCARF
	.2byte ITEM_FOCUS_SASH
	.2byte ITEM_TOXIC_ORB
	.2byte ITEM_FLAME_ORB
	.2byte ITEM_EXPERT_BELT
	.2byte ITEM_LIFE_ORB
	.2byte ITEM_SHED_SHELL
	.2byte ITEM_NONE
	release
	end

	.align 2
Route125_BlackMarket_Shop3:
	.2byte ITEM_PROTECTOR
	.2byte ITEM_MAGMARIZER
	.2byte ITEM_ELECTIRIZER
	.2byte ITEM_REAPER_CLOTH
	.2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_RAZOR_FANG
	.2byte ITEM_RAZOR_CLAW
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_LINKING_CORD
	.2byte ITEM_NONE
	release
	end
