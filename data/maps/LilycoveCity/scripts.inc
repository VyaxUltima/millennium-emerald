.set LOCALID_WOMAN_1, 19
.set LOCALID_MAN_1, 20

LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTreecko
	case 2, LilycoveCity_EventScript_BattleBrendanTreecko
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTreecko
	case 2, LilycoveCity_EventScript_BattleBrendanTreecko
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_NPC
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "Ruggles: Oh, hey, it's {PLAYER}.\p"
	.string "I'm running an errand for Birch.\n"
	.string "They've got some new stock here, too.\p"
	.string "Anyways, it's been a while.\n"
	.string "Remember what I said on Route 119?\p"
	.string "I'm definitely going to win this time.\n"
	.string "Assuming you're up for it?$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "Ruggles: Not feeling it?\n"
	.string "Well, I'll be here if you want to.$"

LilycoveCity_Text_MayBattleMe:
	.string "Ruggles: Changed your mind?$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "Ruggles: Alright!\n"
	.string "{PLAYER}, give it 100%!$"

LilycoveCity_Text_MayDefeat:
	.string "………\p"
	.string "You know, I really appreciate\n"
	.string "having someone like you around.\p"
	.string "Motivating each other to keep\n"
	.string "working hard.$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "Ruggles: Congratulations!\n"
	.string "Couldn't even let me have one, huh?\p"
	.string "Ah, well. I'm all done my business\n"
	.string "here, so I should probably head back\l"
	.string "to Littleroot to see Birch.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}, you're collecting all\n"
	.string "the Badges to challenge the League?\p"
	.string "Then I wish you good luck.\n"
	.string "Anyway, see you around!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}, you've gotten all of\n"
	.string "the Badges to challenge the League?\p"
	.string "Then I wish you good luck.\n"
	.string "Anyway, see you around!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "fuck$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "Ruggles: Oh, hey, it's {PLAYER}.\p"
	.string "I'm running an errand for Birch.\n"
	.string "They've got some new stock here, too.\p"
	.string "Anyways, it's been a while.\n"
	.string "Remember what I said on Route 119?\p"
	.string "I'm definitely going to win this time.\n"
	.string "Assuming you're up for it?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "Ruggles: Not feeling it?\n"
	.string "Well, I'll be here if you want to.$"

LilycoveCity_Text_BrendanBattleMe:
	.string "Ruggles: Changed your mind?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "Ruggles: Alright!\n"
	.string "{PLAYER}, give it 100%!$"

LilycoveCity_Text_BrendanDefeat:
	.string "………\p"
	.string "You know, I really appreciate\n"
	.string "having someone like you around.\p"
	.string "Motivating each other to keep\n"
	.string "working hard.$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "Ruggles: Congratulations!\n"
	.string "Couldn't even let me have one, huh?\p"
	.string "Ah, well. I'm all done my business\n"
	.string "here, so I should probably head back\l"
	.string "to Littleroot to see Birch.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, you're collecting all\n"
	.string "the Badges to challenge the League?\p"
	.string "Then I wish you good luck.\n"
	.string "Anyway, see you around!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, you've gotten all of\n"
	.string "the Badges to challenge the League?\p"
	.string "Then I wish you good luck.\n"
	.string "Anyway, see you around!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "fuck$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Fufufu…\p"
	.string "We moved more loot into our secret\n"
	.string "Hideout today…\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "I'm just a chatter, so I don't know\n"
	.string "what the GOAT is thinking…\p"
	.string "But being in his chat, I know I'll get\n"
	.string "the chance to do big things!\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Hey, you!\p"
	.string "Don't go near the cave in the cove!\p"
	.string "Why? You don't need a reason why!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "If this whole wide world becomes ours,\n"
	.string "Twitch's, it will be a happier\l"
	.string "place for Joel, too.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "There! Wailmer!\n"
	.string "Belly flop!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Hunh? What do you want?\p"
	.string "You're messing up our training,\n"
	.string "so can you, like, get lost?$"

LilycoveCity_Text_ContestHallInTown:
	.string "There's a Contest Hall right here\n"
	.string "this here town. \p"
	.string "But it's closed for now.$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Have you seen that strange cave in\n"
	.string "the cove at the edge of town?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "I'm going to teach my Pokémon some new\n"
	.string "moves for entering a Contest.\p"
	.string "So, I'm going to see the Move Deleter\n"
	.string "and make it forget HM moves.$"

LilycoveCity_Text_ImFromKanto:
	.string "I came from Kanto.\n"
	.string "Bikes are fucking expensive there.$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "Twitch chatters have been pissing\n"
	.string "Wailmer off in the cove.\p"
	.string "We can't get our boats out\n"
	.string "to sea with them in the way!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Ahoy, did you know?\p"
	.string "Someone punted those terminally online\n"
	.string "bozos out of the way for us!$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "I was taking a relaxing snooze at the\n"
	.string "seaside inn to the sound of waves…\p"
	.string "When someone stole my nose!$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "My missing nose…\n"
	.string "It came back without me noticing!$"

LilycoveCity_Text_ImArtDealer:
	.string "I'm an art dealer.\p"
	.string "…Yes, a legal art dealer.\n"
	.string "Don't give me that look.$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Even as we grow old and wrinkled,\n"
	.string "the sea remains forever young with\l"
	.string "the vivid brilliance of life…\p"
	.string "And plastic.$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "It was sixty years ago that my husband\n"
	.string "proposed to me here.\l"
	.string "The sea remains as beautiful as ever.\p"
	.string "Other than the oil.$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Hm, you know of the peculiar cavern\n"
	.string "in this cove?\p"
	.string "That had been a natural formation,\n"
	.string "but then that Twitch lot came\l"
	.string "along and made their renovations.\p"
	.string "They call themselves\n"
	.string "the “fish-loving Twitch chat”!\p"
	.string "But what they do and what they say\n"
	.string "don't match at all!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "That cave in the cove…\p"
	.string "I didn't notice it right away,\n"
	.string "but it's completely empty now.\p"
	.string "That goon squad, they must\n"
	.string "have gone away for good.$"

LilycoveCity_Text_CitySign:
	.string "Lilycove City\n"
	.string "“We removed those fucking ledges”$"

LilycoveCity_Text_ContestHallSign:
	.string "Pokémon Contest Hall\p"
	.string "“The gathering place for Trainers!\n"
	.string "Currently under renovation.”$"

LilycoveCity_Text_MotelSign:
	.string "Cove Lily Motel\p"
	.string "“5/5 as voted by me.”$"

LilycoveCity_Text_MuseumSign:
	.string "Lilycove Museum\p"
	.string "“It's just meme references.”$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "Lilycove\p"
	.string "“{PLAYER}'s Pokémon Collection\n"
	.string "on exhibit!”$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "Lilycove Harbor\p"
	.string "“Days Without Incident: 872”$"

LilycoveCity_Text_HarborSign:
	.string "Lilycove Harbor\p"
	.string "“Days Without Incident: 872”$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "Trainer Fan Club\p"
	.string "The names of Trainer are scribbled\n"
	.string "all over the sign… including yours!$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "Lilycove Department Store\p"
	.string "“Overflowing with capitalism!”$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "Move Deleter's House\p"
	.string "“I forgor”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "The Contest Hall's closed for\n"
	.string "renovations at the moment.$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "People have to work together to get it\n"
	.string "to spin faster.\p"
	.string "The faster you can make it spin, the\n"
	.string "better {POKEBLOCK}s you can get, I've heard.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "It's used for making a kind of candy\n"
	.string "called a {POKEBLOCK}.\p"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
	.string "its condition will improve by a lot.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "I heard there's a tower somewhere out\n"
	.string "on the sea routes.\p"
	.string "It's called the Sky Pillar, I hear.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "I saw this tall tower somewhere\n"
	.string "around Route 131.\p"
	.string "Could that possibly be…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "We just arrived here on our\n"
	.string "honeymoon vacation.\p"
	.string "We happened to see a Dragon-type\n"
	.string "Pokémon flying way up in the sky.\p"
	.string "This place is nuts.$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "On our honeymoon, we vowed to see as\n"
	.string "many rare Pokémon as we can.\p"
	.string "So we were delighted to see a rare\n"
	.string "Pokémon as soon as we arrived.\p"
	.string "I mean, we are totally happy!$"

