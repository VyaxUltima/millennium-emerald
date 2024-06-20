MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Well, well, what have we here?\n"
	.string "A most energetic customer!\p"
	.string "Me? You may call me Rydel.\n"
	.string "I'm the owner of this cycle shop.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "Rydel: Your Running Shoes…\n"
	.string "They're awfully filthy.\p"
	.string "Did you come from far away?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "Rydel: Is that right?\p"
	.string "Then, I guess you have no need for\n"
	.string "any of my bikes.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "Rydel: Hm, hm… … … … …\p"
	.string "You came from Littleroot?\n"
	.string "That's ridiculously far!\p"
	.string "If you had one of my bikes, you could\n"
	.string "get around much more quickly.\p"
	.string "There are two kinds of bikes.\p"
	.string "They are the Mach Bike and\n"
	.string "the Acro Bike!\p"
	.string "I'm a real based guy, so you can\n"
	.string "have whichever one you like!\p"
	.string "Which one will you choose?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} chose speed.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} chose style.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "Rydel: If you get the urge to switch\n"
	.string "bikes, just come see me!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "Rydel: Oh? Were you thinking about\n"
	.string "switching bikes?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "Rydel: Okay, no problem!\n"
	.string "I'll switch bikes for you!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} got the Mach Bike exchanged\n"
	.string "for an Acro Bike.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} got the Acro Bike exchanged\n"
	.string "for a Mach Bike.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "Rydel: Good, good!\n"
	.string "I'm happy that you like it!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Oh? What happened to that bike\n"
	.string "I gave you?\p"
	.string "Oh, I get it, you stored it using your PC.\p"
	.string "Well, take it out of PC storage,\n"
	.string "and I'll be happy to exchange it!\p"
	.string "May the wind always be at your back\n"
	.string "on your adventure!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "I'm learning about bikes while\n"
	.string "I work here.\p"
	.string "If you need advice on how to ride your\n"
	.string "bikes, there're a couple handbooks in\l"
	.string "the back.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "It's a handbook on the Mach Bike.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "FAST\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "SPEED\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "HASTE\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "It's a handbook on the Acro Bike.\p"
	.string "Which page do you want to read?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "WHEELIE\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "PIZAZZ\p"
	.string "Want to read a different page?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "BALLER\p"
	.string "Want to read a different page?$"

