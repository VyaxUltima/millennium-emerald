.set LOCALID_RIVAL, 16
.set LOCALID_RIVAL_ON_BIKE, 25
.set LOCALID_SCOTT, 43
.set LOCALID_MIRORB, 44

Route119_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

Route119_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
	end

Route119_EventScript_TryRemoveKecleon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

Route119_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_EventScript_MoveInstituteWorkersDownstairs
	special SetRoute119Weather
	end

Route119_EventScript_MoveInstituteWorkersDownstairs::
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
	return

Route119_EventScript_RivalTrigger1::
	setvar VAR_TEMP_1, 1
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalTrigger2::
	setvar VAR_TEMP_1, 2
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_MirorBTrigger1::
	setvar VAR_TEMP_1, 1
	goto Route119_EventScript_MirorBEncounter
	end

Route119_EventScript_MirorBTrigger2::
	setvar VAR_TEMP_1, 2
	goto Route119_EventScript_MirorBEncounter
	end

Route119_EventScript_RivalEncounter::
	lockall
	addobject LOCALID_RIVAL_ON_BIKE
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route119_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route119_EventScript_PlayBrendanMusic
	delay 65
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalEnter1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalEnter2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_RIVAL_ON_BIKE
	addobject LOCALID_RIVAL
	delay 30
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route119_EventScript_BattleMay
	goto_if_eq VAR_RESULT, FEMALE, Route119_EventScript_BattleBrendan
	releaseall
	end

Route119_EventScript_MirorBEncounter::
	lockall
	addobject LOCALID_MIRORB
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_MirorBEnter1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_MirorBEnter2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox Route119_Text_MirorBChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route119_Text_MirorBDefeated
	msgbox Route119_Text_MirorBExit, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_MirorBExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_MirorBExit2
	removeobject LOCALID_MIRORB
	setvar VAR_MIROR_B_ROUTE119, 1
	releaseall
	end

Route119_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route119_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route119_EventScript_BattleMay::
	msgbox Route119_Text_MayIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_BattleBrendanTreecko
	case 1, Route119_EventScript_BattleBrendanTreecko
	case 2, Route119_EventScript_BattleBrendanTreecko
	end

Route119_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_DefeatedMay::
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExitScottArrive
	end

Route119_EventScript_BattleBrendan::
	msgbox Route119_Text_BrendanIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_BattleBrendanTreecko
	case 1, Route119_EventScript_BattleBrendanTreecko
	case 2, Route119_EventScript_BattleBrendanTreecko
	end

Route119_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_DefeatedBrendan::
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
	goto Route119_EventScript_RivalExitScottArrive
	end

Route119_EventScript_GiveFlyHM::
	giveitem ITEM_HM02
	setflag FLAG_RECEIVED_HM02
	return

Route119_EventScript_RivalExitScottArrive::
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_ROUTE119_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 60
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetScottPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetScottPos2
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, Route119_Movement_ScottEnter
	waitmovement 0
	addvar VAR_SCOTT_STATE, 1
	msgbox Route119_Text_ScottWayToGoBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_ScottExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_ScottExit2
	removeobject LOCALID_SCOTT
	releaseall
	end

Route119_EventScript_SetScottPos1::
	setobjectxyperm LOCALID_SCOTT, 27, 25
	return

Route119_EventScript_SetScottPos2::
	setobjectxyperm LOCALID_SCOTT, 28, 25
	return

Route119_EventScript_ScottExit1::
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit1
	waitmovement 0
	return

Route119_EventScript_ScottExit2::
	applymovement LOCALID_SCOTT, Route119_Movement_ScottExit2
	waitmovement 0
	return

Route119_EventScript_RivalEnter1::
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter1
	waitmovement 0
	return

Route119_EventScript_RivalEnter2::
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalEnter2
	waitmovement 0
	return

Route119_EventScript_MirorBEnter1::
	applymovement LOCALID_MIRORB, Route119_Movement_MirorBEnter1
	waitmovement 0
	return

Route119_EventScript_MirorBEnter2::
	applymovement LOCALID_MIRORB, Route119_Movement_MirorBEnter2
	waitmovement 0
	return

Route119_EventScript_RivalExit1::
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit1
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit1
	waitmovement 0
	return

Route119_EventScript_RivalExit2::
	applymovement OBJ_EVENT_ID_PLAYER, Route119_Movement_PlayerWatchRivalExit2
	applymovement LOCALID_RIVAL_ON_BIKE, Route119_Movement_RivalExit2
	waitmovement 0
	return

Route119_EventScript_MirorBExit1::
	applymovement LOCALID_MIRORB, Route119_Movement_MirorBExit1
	waitmovement 0
	return

Route119_EventScript_MirorBExit2::
	applymovement LOCALID_MIRORB, Route119_Movement_MirorBExit2
	waitmovement 0
	return

Route119_EventScript_SetRivalPos1::
	setobjectxyperm LOCALID_RIVAL, 25, 32
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 25, 32
	return

Route119_EventScript_SetRivalPos2::
	setobjectxyperm LOCALID_RIVAL, 26, 32
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 26, 32
	return

Route119_Movement_PlayerWatchRivalExit1:
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_PlayerWatchRivalExit2:
	delay_16
	walk_in_place_faster_left
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_RivalEnter1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

Route119_Movement_RivalEnter2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

Route119_Movement_MirorBEnter1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route119_Movement_MirorBEnter2:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route119_Movement_RivalExit1:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_Movement_RivalExit2:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_Movement_MirorBExit1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_Movement_MirorBExit2:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route119_Movement_ScottExit1:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_Movement_ScottExit2:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_EventScript_CyclingTriathleteM::
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
	end

Route119_EventScript_RouteSignFortree::
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
	end

Route119_EventScript_WeatherInstituteSign::
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
	end

Route119_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Taylor::
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Doug::
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Greg::
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Kent::
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Jackson::
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_RegisterJackson::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKSON_1
	release
	end

Route119_EventScript_RematchJackson::
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Catherine::
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_RegisterCatherine::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CATHERINE_1
	release
	end

Route119_EventScript_RematchCatherine::
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hugh::
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Yasu::
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Takashi::
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hideo::
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Chris::
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Fabian::
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Dayton::
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Rachel::
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_BridgeAquaGrunt1::
	lock
	faceplayer
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_BridgeAquaGrunt2::
	lock
	faceplayer
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_Boy1::
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
	end

Route119_EventScript_Boy2::
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
	end

Route119_EventScript_TrainerTipsDecoration::
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
	end

Route119_EventScript_ScottWonAtFortreeGymCall::
	lockall
	pokenavcall Route119_Text_ScottYouWonAtFortreeGym
	waitmessage
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

Route119_Text_MayIntro:
	.string "Ruggles: {PLAYER}! So this is where\n"
	.string "you've been looking for Pokémon?\p"
	.string "Let me see if your team can\n"
	.string "still stand up to mine.\p"
	.string "Alright, come on!\n"
	.string "Let's make this a good battle!$"

Route119_Text_MayDefeat:
	.string "Ha ha!\n"
	.string "I can't get one over you.$"

Route119_Text_MayPresentForYou:
	.string "Ruggles: You've gotten really\n"
	.string "good since we battled on Route 103.\p"
	.string "And I've got something else that\n"
	.string "I think you'll find useful.$"

Route119_Text_MayExplainFly:
	.string "Ruggles: Once you beat Fortree Gym,\n"
	.string "you can Fly around the region.\p"
	.string "Alright, I'm off.\n"
	.string "I'll definitely win next time!$"

Route119_Text_BrendanIntro:
	.string "Ruggles: {PLAYER}! So this is where\n"
	.string "you've been looking for Pokémon?\p"
	.string "Let me see if your team can\n"
	.string "still stand up to mine.\p"
	.string "Alright, come on!\n"
	.string "Let's make this a good battle!$"

Route119_Text_BrendanDefeat:
	.string "Ha ha!\n"
	.string "I can't get one over you.$"

Route119_Text_BrendanIllGiveYouThis:
	.string "Ruggles: You've gotten really\n"
	.string "good since we battled on Route 103.\p"
	.string "And I've got something else that\n"
	.string "I think you'll find useful.$"

Route119_Text_BrendanExplainFly:
	.string "Ruggles: Once you beat Fortree Gym,\n"
	.string "you can Fly around the region.\p"
	.string "Alright, I'm off.\n"
	.string "I'll definitely win next time!$"

Route119_Text_ScottWayToGoBeSeeingYou:
	.string "Trif: YO I KNOW WHO THAT GUY IS$"

Route119_Text_ScottYouWonAtFortreeGym:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Trif: THEY THINK THAT I'M\n"
	.string "INVISIBLE\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Route119_Text_StayAwayFromWeatherInstitute:
	.string "Oh, man…\n"
	.string "That groovy guy beat us bad.\p"
	.string "Now we're stuck on watch here.$"

Route119_Text_DontGoNearWeatherInstitute:
	.string "Jeez…\n"
	.string "Since when was disco back in?$"

Route119_Text_ThoughtFlyByCatchingBirdMons:
	.string "I recently made a deck around\n"
	.string "Winged Beast cards.\p"
	.string "I know! I'll call it Bird Up!\n"
	.string "I'm so smart.$"

Route119_Text_TallGrassSnaresBikeTires:
	.string "Tch…\n"
	.string "It's a no-go…\p"
	.string "The tall grass snares bike tires.\n"
	.string "There's no way you can cycle here.$"

Route119_Text_CanYourMonMakeSecretBase:
	.string "I hear Fortree's a pretty major\n"
	.string "hub for online collabs.\p"
	.string "Though I'm not sure what sort of\n"
	.string "personalities collide there.$"

Route119_Text_MirorBChallenge:
	.string "Fuhohoho!\n"
	.string "What perfect timing!\p"
	.string "I sense the strength of a\n"
	.string "travelling Trainer!\p"
	.string "I hail from the Orre region,\n"
	.string "here now without my legion.\p"
	.string "Are Hoenn's trainers as good\n"
	.string "as they say?\p"
	.string "I have to see for myself\n"
	.string "right away!\p"
	.string "Let the music play!$"

Route119_Text_MirorBDefeated:
	.string "Oh no no no!\n"
	.string "My rhythm has gone ragged!$"

Route119_Text_MirorBExit:
	.string "Miror B: Hm hm!\p"
	.string "Hoenn is one talented nation.\n"
	.string "I have to recover my beat\l"
	.string "without hesitation!\p"
	.string "Next time we meet,\n"
	.string "I'll knock you off your feet!\p"
	.string "Fuhohoho!$"

Route119_Text_RouteSignFortree:
	.string "Route 119\n"
	.string "{RIGHT_ARROW} Fortree City$"

Route119_Text_WeatherInstitute:
	.string "Weather Institute$"

Route119_Text_TrainerTipsDecoration:
	.string "Dev Team Quotes\p"
	.string "Ref: make rustboro more earthen for the\n"
	.string "fucking volcano that exists underneath\p"
	.string "Vyax: fuck logic, we have two gyms\n"
	.string "with full ass fucking beaches in them$"
