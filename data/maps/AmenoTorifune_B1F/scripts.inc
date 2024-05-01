AmenoTorifune_B1F_MapScripts::
	.byte 0

AmenoTorifune_B1F_EventScript_Nova::
	trainerbattle_single TRAINER_ROSE_3, AmenoTorifune_B1F_Text_NovaIntro, AmenoTorifune_B1F_Text_NovaDefeated
	msgbox AmenoTorifune_B1F_Text_NovaPostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B1F_EventScript_Faye::
	trainerbattle_single TRAINER_ROSE_4, AmenoTorifune_B1F_Text_FayeIntro, AmenoTorifune_B1F_Text_FayeDefeated
	msgbox AmenoTorifune_B1F_Text_FayePostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B1F_EventScript_Gredora::
	trainerbattle_single TRAINER_ROSE_5, AmenoTorifune_B1F_Text_GredoraIntro, AmenoTorifune_B1F_Text_GredoraDefeated
	msgbox AmenoTorifune_B1F_Text_GredoraPostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B1F_EventScript_Zeros::
	trainerbattle_single TRAINER_ANDRES_2, AmenoTorifune_B1F_Text_ZerosIntro, AmenoTorifune_B1F_Text_ZerosDefeated
	msgbox AmenoTorifune_B1F_Text_ZerosPostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B1F_EventScript_Leonidas::
	trainerbattle_single TRAINER_ANDRES_3, AmenoTorifune_B1F_Text_LeonidasIntro, AmenoTorifune_B1F_Text_LeonidasDefeated
	msgbox AmenoTorifune_B1F_Text_LeonidasPostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B1F_EventScript_Blade::
	trainerbattle_single TRAINER_ANDRES_4, AmenoTorifune_B1F_Text_BladeIntro, AmenoTorifune_B1F_Text_BladeDefeated
	msgbox AmenoTorifune_B1F_Text_BladePostBattle, MSGBOX_AUTOCLOSE
	end

AmenoTorifune_B1F_EventScript_FindMaxElixir::
	finditem ITEM_MAX_ELIXIR
	end

@ I FUCKING LOVE TEXT RAHHHHHHHH

AmenoTorifune_B1F_Text_NovaIntro:
	.string "Always have to ensure\n"
	.string "stable footing when climbing.$"

AmenoTorifune_B1F_Text_NovaDefeated:
	.string "Guess that was unstable terrain.$"

AmenoTorifune_B1F_Text_NovaPostBattle:
	.string "Gotta get me some new boots.$"

AmenoTorifune_B1F_Text_FayeIntro:
	.string "YIPPEE! Our eyes have met,\n"
	.string "now prepare for the metal pipe!$"

AmenoTorifune_B1F_Text_FayeDefeated:
	.string "wtf this is literally 1984$"

AmenoTorifune_B1F_Text_FayePostBattle:
	.string "Merrli is the ideal Gigantic\n"
	.string "Spright target.\p"
	.string "The first thing to note about\n"
	.string "Merrli is that it is Level 2.\p"
	.string "Level 2 is one of the best\n"
	.string "standalone levels$"

AmenoTorifune_B1F_Text_GredoraIntro:
	.string "This ain't a show dipshit.$"

AmenoTorifune_B1F_Text_GredoraDefeated:
	.string "Goddamn.$"

AmenoTorifune_B1F_Text_GredoraPostBattle:
	.string "Wiggle.$"

AmenoTorifune_B1F_Text_ZerosIntro:
	.string "Did you know in terms of…$"

AmenoTorifune_B1F_Text_ZerosDefeated:
	.string "Damn. You got hella hax luck.$"

AmenoTorifune_B1F_Text_ZerosPostBattle:
	.string "Whatever, time to play Valorant,\n"
	.string "the better Riot game.$"

AmenoTorifune_B1F_Text_LeonidasIntro:
	.string "Please leave me alone,\n"
	.string "I'm not very funny.$"

AmenoTorifune_B1F_Text_LeonidasDefeated:
	.string "yep death.$"

AmenoTorifune_B1F_Text_LeonidasPostBattle:
	.string "What do you want?\p"
	.string "You already took my money and killed\n"
	.string "my Pokémons. Want to kill me too?$"

AmenoTorifune_B1F_Text_BladeIntro:
	.string "Did you know?\n"
	.string "The longest recorded sentence\l"
	.string "said by a Mankey is:\p"
	.string "“Give orange me give eat orange me\n"
	.string "eat orange give me eat orange give”$"

AmenoTorifune_B1F_Text_BladeDefeated:
	.string "That's how the cookie crumbles.$"

AmenoTorifune_B1F_Text_BladePostBattle:
	.string "This was karmic retribution for\n"
	.string "for the crimes I did in '08.$"

