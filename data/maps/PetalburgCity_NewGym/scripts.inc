.set LOCALID_WALLYS_DAD, 7

PetalburgCity_NewGym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_NewGym_OnLoad
	.byte 0


PetalburgCity_NewGym_OnLoad::
	goto_if_eq VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_NewGym_EventScript_OpenUnlockedDoors
	call_if_ge VAR_PETALBURG_GYM_STATE, 7, PetalburgCity_NewGym_EventScript_UnlockAllDoors
	end


@ Opens the doors. Uncomment them when you're ready to insert trainers.
@ Underlying logic is in field_specials.c under PetalburgGymSetDoorMetatiles
@ call_if_defeated TRAINER_PLACEHOLDER, PetalburgCity_NewGym_EventScript_OpenJPDoor
@ call_if_defeated TRAINER_PLACEHOLDER, PetalburgCity_NewGym_EventScript_OpenBurnDoor
@ call_if_defeated TRAINER_PLACEHOLDER, PetalburgCity_NewGym_EventScript_OpenBlastDoor
@ call_if_defeated TRAINER_PLACEHOLDER, PetalburgCity_NewGym_EventScript_OpenCrossDoor
@ call_if_defeated TRAINER_PLACEHOLDER, PetalburgCity_NewGym_EventScript_OpenWaveDoor
PetalburgCity_NewGym_EventScript_OpenUnlockedDoors::
	setvar VAR_0x8005, 1
	call_if_defeated TRAINER_MARY, PetalburgCity_NewGym_EventScript_OpenJPDoor
	call_if_defeated TRAINER_RANDALL, PetalburgCity_NewGym_EventScript_OpenBurnDoor
	call_if_defeated TRAINER_PARKER, PetalburgCity_NewGym_EventScript_OpenBlastDoor
	call_if_defeated TRAINER_GEORGE, PetalburgCity_NewGym_EventScript_OpenCrossDoor
	call_if_defeated TRAINER_BERKE, PetalburgCity_NewGym_EventScript_OpenWaveDoor
	end

PetalburgCity_NewGym_EventScript_UnlockAllDoors::
	setvar VAR_PETALBURG_GYM_STATE, 7
	setvar VAR_0x8005, 1
	call PetalburgCity_NewGym_EventScript_OpenJPDoor
	call PetalburgCity_NewGym_EventScript_OpenBurnDoor
	call PetalburgCity_NewGym_EventScript_OpenBlastDoor
	call PetalburgCity_NewGym_EventScript_OpenCrossDoor
	call PetalburgCity_NewGym_EventScript_OpenWaveDoor
	end

PetalburgCity_NewGym_EventScript_Norman::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE05_GET, PetalburgCity_NewGym_EventScript_NormanBattle
	goto PetalburgCity_NewGym_EventScript_NormanPostBattle
	release
	end

PetalburgCity_NewGym_EventScript_NormanBattle::
	msgbox PetalburgCity_NewGym_Text_NormanIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_NewGym_Text_NormanDefeat
	message PetalburgCity_NewGym_Text_ReceivedBalanceBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PetalburgCity_NewGym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setvar VAR_PETALBURG_GYM_STATE, 7
	setflag FLAG_BADGE05_GET
	special ResetHealLocationFromDewford
	call EventScript_HideMrBriney
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
	call PetalburgCity_NewGym_EventScript_GiveFacade
	delay 30
	msgbox PetalburgCity_NewGym_Text_DadHappyAndSad, MSGBOX_DEFAULT
	closemessage
	delay 40
	playse SE_DOOR
	delay 10
	addobject LOCALID_WALLYS_DAD
	goto PetalburgCity_NewGym_EventScript_WallysDadArrives
	end

PetalburgCity_NewGym_EventScript_NormanPostBattle::
	msgbox PetalburgCity_NewGym_Text_KeepTraining, MSGBOX_DEFAULT
	release
	end

PetalburgCity_NewGym_EventScript_GiveFacade::
	giveitem ITEM_TM30
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_RECEIVED_TM42
	msgbox PetalburgCity_NewGym_Text_ExplainFacade, MSGBOX_DEFAULT
	return

PetalburgCity_NewGym_EventScript_WallysDadArrives::
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_NewGym_Movement_WallysDadEnterGym
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_WALLYS_DAD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLYS_DAD, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 10
	msgbox PetalburgCity_NewGym_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_FOLLOW_ME, FALSE
	removeobject LOCALID_WALLYS_DAD
	setvar VAR_PETALBURG_CITY_STATE, 4
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
	warp MAP_PETALBURG_CITY, 15, 8
	waitstate
	release
	end

PetalburgCity_NewGym_Movement_WallysDadEnterGym:
	walk_up
	walk_up
	step_end

PetalburgCity_NewGym_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_NewGym_Text_RandallIntro, PetalburgCity_NewGym_Text_RandallDefeat, PetalburgCity_NewGym_EventScript_SlideBurnDoor
	msgbox PetalburgCity_NewGym_Text_RandallPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_NewGym_EventScript_Parker::
	trainerbattle_single TRAINER_PARKER, PetalburgCity_NewGym_Text_ParkerIntro, PetalburgCity_NewGym_Text_ParkerDefeat, PetalburgCity_NewGym_EventScript_SlideBlastDoor
	msgbox PetalburgCity_NewGym_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_NewGym_EventScript_George::
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_NewGym_Text_GeorgeIntro, PetalburgCity_NewGym_Text_GeorgeDefeat, PetalburgCity_NewGym_EventScript_SlideCrossDoor
	msgbox PetalburgCity_NewGym_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_NewGym_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE, PetalburgCity_NewGym_Text_BerkeIntro, PetalburgCity_NewGym_Text_BerkeDefeat, PetalburgCity_NewGym_EventScript_SlideWaveDoor
	msgbox PetalburgCity_NewGym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
	end

Petalburg_EventScript_LULW::
	lockall
	call PetalburgCity_NewGym_EventScript_UnlockAllDoors
	msgbox PetalburgCity_NewGym_Text_Floodgates, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_NewGym_EventScript_SlideBurnDoor::
	setvar VAR_0x8005, 0
	call PetalburgCity_NewGym_EventScript_OpenBurnDoor
	special DrawWholeMapView
	release
	end

PetalburgCity_NewGym_EventScript_SlideBlastDoor::
	setvar VAR_0x8005, 0
	call PetalburgCity_NewGym_EventScript_OpenBlastDoor
	special DrawWholeMapView
	release
	end

PetalburgCity_NewGym_EventScript_SlideCrossDoor::
	setvar VAR_0x8005, 0
	call PetalburgCity_NewGym_EventScript_OpenCrossDoor
	special DrawWholeMapView
	release
	end

PetalburgCity_NewGym_EventScript_SlideWaveDoor::
	setvar VAR_0x8005, 0
	call PetalburgCity_NewGym_EventScript_OpenWaveDoor
	special DrawWholeMapView
	release
	end

PetalburgCity_NewGym_EventScript_OpenJPDoor::
	setvar VAR_0x8004, 2
	call_if_eq VAR_0x8005, 0, PetalburgCity_NewGym_SlideOpenDoor
	call_if_eq VAR_0x8005, 1, PetalburgCity_NewGym_UnlockDoor
	special DrawWholeMapView
	return

PetalburgCity_NewGym_EventScript_OpenBurnDoor::
	setvar VAR_0x8004, 3
	call_if_eq VAR_0x8005, 0, PetalburgCity_NewGym_SlideOpenDoor
	call_if_eq VAR_0x8005, 1, PetalburgCity_NewGym_UnlockDoor
	special DrawWholeMapView
	return

PetalburgCity_NewGym_EventScript_OpenBlastDoor::
	setvar VAR_0x8004, 4
	call_if_eq VAR_0x8005, 0, PetalburgCity_NewGym_SlideOpenDoor
	call_if_eq VAR_0x8005, 1, PetalburgCity_NewGym_UnlockDoor
	special DrawWholeMapView
	return

PetalburgCity_NewGym_EventScript_OpenCrossDoor::
	setvar VAR_0x8004, 5
	call_if_eq VAR_0x8005, 0, PetalburgCity_NewGym_SlideOpenDoor
	call_if_eq VAR_0x8005, 1, PetalburgCity_NewGym_UnlockDoor
	special DrawWholeMapView
	return

PetalburgCity_NewGym_EventScript_OpenWaveDoor::
	setvar VAR_0x8004, 6
	call_if_eq VAR_0x8005, 0, PetalburgCity_NewGym_SlideOpenDoor
	call_if_eq VAR_0x8005, 1, PetalburgCity_NewGym_UnlockDoor
	special DrawWholeMapView
	return

PetalburgCity_NewGym_SlideOpenDoor::
	special PetalburgGymSlideOpenRoomDoors
	waitstate
	return

PetalburgCity_NewGym_UnlockDoor::
	special PetalburgGymUnlockRoomDoors
	return

@ this is to check if the trainer is defeated to keep the door locked.
@ copy and paste for each of the enter scripts
@ goto_if_not_defeated TRAINER_PLACEHOLDER, PetalburgCity_NewGym_EventScript_DoorLocked
PetalburgCity_NewGym_EventScript_EnterBurnRoom::
	lockall
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_NewGym_EventScript_DoorLocked
	setvar VAR_0x8008, 4
	setvar VAR_0x8009, 55
	call PetalburgCity_NewGym_EventScript_EnterRoom
	end

PetalburgCity_NewGym_EventScript_EnterBlastRoom::
	lockall
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_NewGym_EventScript_DoorLocked
	setvar VAR_0x8008, 4
	setvar VAR_0x8009, 43
	call PetalburgCity_NewGym_EventScript_EnterRoom
	end

PetalburgCity_NewGym_EventScript_EnterCrossRoom::
	lockall
	goto_if_not_defeated TRAINER_PARKER, PetalburgCity_NewGym_EventScript_DoorLocked
	setvar VAR_0x8008, 4
	setvar VAR_0x8009, 31
	call PetalburgCity_NewGym_EventScript_EnterRoom
	end

PetalburgCity_NewGym_EventScript_EnterWaveRoom::
	lockall
	goto_if_not_defeated TRAINER_GEORGE, PetalburgCity_NewGym_EventScript_DoorLocked
	setvar VAR_0x8008, 4
	setvar VAR_0x8009, 19
	call PetalburgCity_NewGym_EventScript_EnterRoom
	end

PetalburgCity_NewGym_EventScript_EnterEngageRoom::
	lockall
	goto_if_not_defeated TRAINER_BERKE, PetalburgCity_NewGym_EventScript_DoorLocked
	setvar VAR_0x8008, 4
	setvar VAR_0x8009, 7
	call PetalburgCity_NewGym_EventScript_EnterRoom
	end


PetalburgCity_NewGym_EventScript_EnterRoom::
	lockall
	msgbox PetalburgCity_NewGym_Text_EnterNextRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_NewGym_EventScript_DontEnterRoom
	closemessage
	delay 30
	warpdoor MAP_PETALBURG_CITY_NEW_GYM, VAR_0x8008, VAR_0x8009
	waitstate
	releaseall
	end

PetalburgCity_NewGym_EventScript_DoorLocked::
	msgbox PetalburgCity_NewGym_Text_DoorAppearsLocked, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_NewGym_EventScript_DontEnterRoom::
	releaseall
	end

@ text gamers

PetalburgCity_NewGym_Text_RandallIntro:
	.string "Biggest downside of your Grinder Golem\n"
	.string "is that, you know it takes up a\l"
	.string "lot of Extra Deck space.$"

PetalburgCity_NewGym_Text_RandallDefeat:
	.string "Activate Stormforth, response?$"

PetalburgCity_NewGym_Text_RandallPostBattle:
	.string "Ah, you're unaffected.$"

PetalburgCity_NewGym_Text_ParkerIntro:
	.string "WHAAAAAAAATS GOOOOOD\n"
	.string "YOOOOTOOOBE$"

PetalburgCity_NewGym_Text_ParkerDefeat:
	.string "And welcome to the House!$"

PetalburgCity_NewGym_Text_ParkerPostBattle:
	.string "Keep an eye out for\n"
	.string "Market Watch.$"

PetalburgCity_NewGym_Text_GeorgeIntro:
	.string "Gonna show you who the real\n"
	.string "White Lightning is today.$"

PetalburgCity_NewGym_Text_GeorgeDefeat:
	.string "50 SUBSCRIBERS, WOOOO!$"

PetalburgCity_NewGym_Text_GeorgePostBattle:
	.string "Me when I lose to Gage in Prog\n"
	.string "for the week.$"

PetalburgCity_NewGym_Text_BerkeIntro:
	.string "I just like the funny fish deck.$"

PetalburgCity_NewGym_Text_BerkeDefeat:
	.string "Describe the deck you're currently\n"
	.string "playing in 3 words: losing to ash$"

PetalburgCity_NewGym_Text_BerkePostBattle:
	.string "When I die don't photoshop\n"
	.string "wings on me.$"

PetalburgCity_NewGym_Text_NormanIntro:
	.string "Nyhmnim: Hey, {PLAYER}!\p"
	.string "Four Badges already?\n"
	.string "Looking pretty clean, I gotta say.\p"
	.string "Well, hey, I promised, right?\p"
	.string "Four of those bad boys and we'll\n"
	.string "have ourselves a damn good battle!\p"
	.string "In my honest opinion?\n"
	.string "This team's broken as hell.\p"
	.string "{PLAYER}, you'd better give it your\n"
	.string "best shot, too!$"

PetalburgCity_NewGym_Text_NormanDefeat:
	.string "Damn, I lost another week!\p"
	.string "Well, alright. You earned this.$"

PetalburgCity_NewGym_Text_ReceivedBalanceBadge:
	.string "{PLAYER} received the OPTML Badge\n"
	.string "from Nyhmnim.$"

PetalburgCity_NewGym_Text_ExplainBalanceBadgeTakeThis:
	.string "Nyhmnim: Really thought I could\n"
	.string "pull it back there.\p"
	.string "I gotta ban you for that.\n"
	.string "It was all coming up me.\p"
	.string "Nah, but seriously, good battle!\p"
	.string "Anyway, that OPTML Badge lets you\n"
	.string "Surf across the water.\l"
	.string "Pretty sick, huh?\p"
	.string "Oh, I also got something for you.$"

PetalburgCity_NewGym_Text_ExplainFacade:
	.string "TM30 is Shadow Ball.\n"
	.string "Killer move for Ghost types.$"

PetalburgCity_NewGym_Text_DadHappyAndSad:
	.string "Well, your next target for a badge\n"
	.string "should be in Fortree.\p"
	.string "The Gym there is pretty toxic though.$"

PetalburgCity_NewGym_Text_KeepTraining:
	.string "Gotta think of what strat to\n"
	.string "go with now…$"

PetalburgCity_NewGym_Text_PleaseComeWithMe:
	.string "Hey, hey! You're {PLAYER}, yeah?\p"
	.string "I heard that you were challenging\n"
	.string "our new Gym Leader!\p"
	.string "Not just that, you beat him too!\n"
	.string "Congratulations!\p"
	.string "Well, in that case, I got a little\n"
	.string "gift for you!\p"
	.string "Mind coming with me?\n"
	.string "My place is just next door.$"

PetalburgCity_NewGym_Text_DoorAppearsLocked:
	.string "The door is locked right now.$"

PetalburgCity_NewGym_Text_Floodgates:
	.string "antispell fragrance$"

PetalburgCity_NewGym_Text_EnterNextRoom:
	.string "Would you like to enter the next room?$"

