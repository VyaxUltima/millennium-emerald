AmenoTorifune_B5F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AmenoTorifune_B5F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AmenoTorifune_B5F_OnTransition
	.byte 0

AmenoTorifune_B5F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AmenoTorifune_B5F_EventScript_TryRemoveBeast
	end

AmenoTorifune_B5F_EventScript_TryRemoveBeast::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AmenoTorifune_B5F_OnTransition:
	call EventScript_SetupLegendaryGfx
	call_if_unset FLAG_DEFEATED_JOHTO_BEAST, AmenoTorifune_B5F_EventScript_ShowBeast
	end

AmenoTorifune_B5F_EventScript_ShowBeast::
	clearflag FLAG_HIDE_LEGEND_MON_AMENO_TORIFUNE
	return

@ Beast is determined by the starter chosen
EventScript_SetupLegendaryGfx::
	switch VAR_STARTER_MON
	case 0, EventScript_SetupEnteiGfx
	case 1, EventScript_SetupSuicuneGfx
	case 2, EventScript_SetupRaikouGfx
	end

EventScript_SetupEnteiGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BIG_CHARIZARD_DOLL
	return

EventScript_SetupSuicuneGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BIG_VENUSAUR_DOLL
	return

EventScript_SetupRaikouGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BIG_BLASTOISE_DOLL
	return

AmenoTorifune_B5F_EventScript_JohtoBeast::
	lock
	switch VAR_STARTER_MON
	case 0, AmenoTorifune_B5F_EventScript_Entei
	case 1, AmenoTorifune_B5F_EventScript_Suicune
	case 2, AmenoTorifune_B5F_EventScript_Raikou
	end

AmenoTorifune_B5F_EventScript_Entei::
	waitse
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	settotemboost 1, 1, 0, 1, 1
	setwildbattle SPECIES_ENTEI, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AmenoTorifune_B5F_EventScript_DefeatedBeast
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AmenoTorifune_B5F_EventScript_RanFromEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AmenoTorifune_B5F_EventScript_RanFromEntei
	setflag FLAG_DEFEATED_JOHTO_BEAST
	release
	end

AmenoTorifune_B5F_EventScript_Suicune::
	waitse
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	settotemboost 1, 1, 0, 1, 1
	setwildbattle SPECIES_SUICUNE, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AmenoTorifune_B5F_EventScript_DefeatedBeast
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AmenoTorifune_B5F_EventScript_RanFromSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AmenoTorifune_B5F_EventScript_RanFromSuicune
	setflag FLAG_DEFEATED_JOHTO_BEAST
	release
	end

AmenoTorifune_B5F_EventScript_Raikou::
	waitse
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	settotemboost 1, 1, 0, 1, 1
	setwildbattle SPECIES_RAIKOU, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AmenoTorifune_B5F_EventScript_DefeatedBeast
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AmenoTorifune_B5F_EventScript_RanFromRaikou
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AmenoTorifune_B5F_EventScript_RanFromRaikou
	setflag FLAG_DEFEATED_JOHTO_BEAST
	release
	end

AmenoTorifune_B5F_EventScript_DefeatedBeast::
	setflag FLAG_DEFEATED_JOHTO_BEAST
	setflag FLAG_HIDE_LEGEND_MON_AMENO_TORIFUNE
	goto Common_EventScript_RemoveStaticPokemon
	end

AmenoTorifune_B5F_EventScript_RanFromEntei::
	setflag FLAG_HIDE_LEGEND_MON_AMENO_TORIFUNE
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryFlewAway
	end

AmenoTorifune_B5F_EventScript_RanFromSuicune::
	setflag FLAG_HIDE_LEGEND_MON_AMENO_TORIFUNE
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto Common_EventScript_LegendaryFlewAway
	end

AmenoTorifune_B5F_EventScript_RanFromRaikou::
	setflag FLAG_HIDE_LEGEND_MON_AMENO_TORIFUNE
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto Common_EventScript_LegendaryFlewAway
	end

