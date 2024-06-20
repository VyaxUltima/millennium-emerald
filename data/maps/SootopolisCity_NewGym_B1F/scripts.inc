SootopolisCity_NewGym_B1F_MapScripts::
	.byte 0

SootopolisCity_NewGym_B1F_EventScript_Juan::
	goto_if_lt VAR_SOOTOPOLIS_GYM_STATE, 4, SootopolisCity_NewGym_B1F_EventScript_JuanEducate
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_NewGym_B1F_Text_JuanIntro, SootopolisCity_NewGym_B1F_Text_JuanDefeat, SootopolisCity_NewGym_B1F_EventScript_JuanDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_TM03, SootopolisCity_NewGym_B1F_EventScript_GiveWaterPulse2
	msgbox SootopolisCity_NewGym_B1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_NewGym_B1F_EventScript_JuanEducate::
	msgbox SootopolisCity_NewGym_B1F_Text_JuanEducateSelf, MSGBOX_NPC
	release
	end

SootopolisCity_NewGym_B1F_EventScript_JuanDefeated::
	SootopolisCity_NewGym_B1F_EventScript_JuanDefeated::
	message SootopolisCity_NewGym_B1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_NewGym_B1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_NewGym_B1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_NewGym_B1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_NewGym_B1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM22
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_NewGym_B1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM03
	return

SootopolisCity_NewGym_B1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM22
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_NewGym_B1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM03
	release
	end

SootopolisCity_NewGym_B1F_EventScript_Educated::
	addvar VAR_SOOTOPOLIS_GYM_STATE, 1
	return

SootopolisCity_NewGym_B1F_EventScript_Nadhir::
	trainerbattle_single TRAINER_BRIANNA, SootopolisCity_NewGym_B1F_Text_NadhirIntro, SootopolisCity_NewGym_B1F_Text_NadhirDefeat, SootopolisCity_NewGym_B1F_EventScript_NadhirLearning
	msgbox SootopolisCity_NewGym_B1F_Text_NadhirPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_NewGym_B1F_EventScript_NadhirLearning::
	call SootopolisCity_NewGym_B1F_EventScript_Educated
	msgbox SootopolisCity_NewGym_B1F_Text_NadhirBonusCards, MSGBOX_DEFAULT
	release
	end

SootopolisCity_NewGym_B1F_EventScript_Caleb::
	trainerbattle_single TRAINER_ANDREA, SootopolisCity_NewGym_B1F_Text_CalebIntro, SootopolisCity_NewGym_B1F_Text_CalebDefeat, SootopolisCity_NewGym_B1F_EventScript_CalebLearning
	msgbox SootopolisCity_NewGym_B1F_Text_CalebPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_NewGym_B1F_EventScript_CalebLearning::
	call SootopolisCity_NewGym_B1F_EventScript_Educated
	msgbox SootopolisCity_NewGym_B1F_Text_CalebTopic, MSGBOX_DEFAULT
	release
	end

SootopolisCity_NewGym_B1F_EventScript_Scarlet::
	trainerbattle_single TRAINER_CRISSY, SootopolisCity_NewGym_B1F_Text_ScarletIntro, SootopolisCity_NewGym_B1F_Text_ScarletDefeat, SootopolisCity_NewGym_B1F_EventScript_ScarletLearning
	msgbox SootopolisCity_NewGym_B1F_Text_ScarletPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_NewGym_B1F_EventScript_ScarletLearning::
	call SootopolisCity_NewGym_B1F_EventScript_Educated
	msgbox SootopolisCity_NewGym_B1F_Text_ScarletTopic, MSGBOX_DEFAULT
	release
	end

SootopolisCity_NewGym_B1F_EventScript_DarthNash::
	trainerbattle_single TRAINER_CONNIE, SootopolisCity_NewGym_B1F_Text_DarthNashIntro, SootopolisCity_NewGym_B1F_Text_DarthNashDefeat, SootopolisCity_NewGym_B1F_EventScript_DarthNashLearning
	msgbox SootopolisCity_NewGym_B1F_Text_DarthNashPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_NewGym_B1F_EventScript_DarthNashLearning::
	call SootopolisCity_NewGym_B1F_EventScript_Educated
	msgbox SootopolisCity_NewGym_B1F_Text_DarthNashTopic, MSGBOX_DEFAULT
	release
	end
	
SootopolisCity_NewGym_B1F_EventScript_Janitor::
	msgbox SootopolisCity_NewGym_B1F_Text_Bald, MSGBOX_NPC
	end
	
SootopolisCity_NewGym_B1F_EventScript_Student1::
	msgbox SootopolisCity_NewGym_B1F_Text_GAMING, MSGBOX_NPC
	end

SootopolisCity_NewGym_B1F_EventScript_Student2::
	msgbox SootopolisCity_NewGym_B1F_Text_Detention, MSGBOX_NPC
	end

SootopolisCity_NewGym_B1F_EventScript_Student3::
	msgbox SootopolisCity_NewGym_B1F_Text_Stats, MSGBOX_NPC
	end

SootopolisCity_NewGym_B1F_EventScript_Student4::
	msgbox SootopolisCity_NewGym_B1F_Text_Striker, MSGBOX_NPC
	end

SootopolisCity_NewGym_B1F_EventScript_Student5::
	msgbox SootopolisCity_NewGym_B1F_Text_Believe, MSGBOX_NPC
	end

SootopolisCity_NewGym_B1F_EventScript_Student6::
	msgbox SootopolisCity_NewGym_B1F_Text_GX, MSGBOX_NPC
	end

SootopolisCity_NewGym_B1F_EventScript_Student7::
	msgbox SootopolisCity_NewGym_B1F_Text_NewDeck, MSGBOX_NPC
	end

SootopolisCity_NewGym_B1F_EventScript_Student8::
	msgbox SootopolisCity_NewGym_B1F_Text_Ratios, MSGBOX_NPC
	end

SootopolisCity_NewGym_B1F_EventScript_Student9::
	msgbox SootopolisCity_NewGym_B1F_Text_YoungerKids, MSGBOX_NPC
	end

SootopolisCity_NewGym_B1F_EventScript_Student10::
	msgbox SootopolisCity_NewGym_B1F_Text_Shrimp, MSGBOX_NPC
	end

SootopolisCity_NewGym_B1F_EventScript_Teacher1::
	msgbox SootopolisCity_NewGym_B1F_Text_WhyThough, MSGBOX_NPC
	end
@ Text

SootopolisCity_NewGym_B1F_Text_JuanEducateSelf:
	.string "Hey. You're the new challenger?\n"
	.string "Good to meet you.\p"
	.string "If you want a battle, then talk\n"
	.string "to the other staff.\l"
	.string "I'll be waiting here.$"

SootopolisCity_NewGym_B1F_Text_JuanIntro:
	.string "Eva: Hello. I assume you are\n"
	.string "here to earn a Badge?\p"
	.string "How'd you like the Gym I set up?\n"
	.string "I'm quite proud of it.\p"
	.string "Education is important.\n"
	.string "It's the foundation upon which\l"
	.string "a student's knowledge can build.\p"
	.string "You, too, are a student in my eyes.\p"
	.string "I'll give you a lesson on your\n"
	.string "knowledge of acquiring Badges!$"

SootopolisCity_NewGym_B1F_Text_JuanDefeat:
	.string "Ahahaha, excellent!\n"
	.string "Very well, you are the winner.\p"
	.string "Here, I believe this is yours.$"

SootopolisCity_NewGym_B1F_Text_ReceivedRainBadge:
	.string "{PLAYER} received the Memento Badge\n"
	.string "from Eva.$"

SootopolisCity_NewGym_B1F_Text_ExplainRainBadgeTakeThis:
	.string "The Memento Badge ensures that all\n"
	.string "your Pokémon follow your commands.\p"
	.string "You'll also be able to use Waterfall\n"
	.string "outside battle to scale Waterfalls.\p"
	.string "And, as another reward, you should\n"
	.string "accept this.$"

SootopolisCity_NewGym_B1F_Text_ExplainWaterPulse:
	.string "TM22 contains Solar Beam.\p"
	.string "Normally, it takes two turns to\n"
	.string "fully perform.\p"
	.string "If you have strong sunlight over the\n"
	.string "field, however, it fires instantly.$"

SootopolisCity_NewGym_B1F_Text_RegisteredJuan:
	.string "Registered Gym Leader Eva\n"
	.string "in the Pokénav.$"

SootopolisCity_NewGym_B1F_Text_JuanPostBattle:
	.string "Using Waterfall, it should be possible\n"
	.string "to travel to Ever Grande now.\p"
	.string "The Pokémon League…\p"
	.string "That would be the final step on\n"
	.string "this journey of yours.\p"
	.string "They won't take it easy on you.$"

SootopolisCity_NewGym_B1F_Text_Bald:
	.string "I swear I saw some kid run\n"
	.string "in here earlier…$"

SootopolisCity_NewGym_B1F_Text_GAMING:
	.string "I'm in here GAMING.$"

SootopolisCity_NewGym_B1F_Text_Detention:
	.string "I got put in detention for\n"
	.string "stealing a pack of chalk.$"

SootopolisCity_NewGym_B1F_Text_WhyThough:
	.string "What was even the point of\n"
	.string "stealing chalk?\p"
	.string "It's not exactly a luxury\n"
	.string "item.$"

SootopolisCity_NewGym_B1F_Text_Stats:
	.string "Hey, do you know how stat\n"
	.string "changing moves work?\p"
	.string "They're really useful.$"

SootopolisCity_NewGym_B1F_Text_Striker:
	.string "This guy knows a lot about\n"
	.string "Spell Cards!$"

SootopolisCity_NewGym_B1F_Text_Believe:
	.string "My teacher gave me a card with\n"
	.string "his face on it that says “Believe.”$"

SootopolisCity_NewGym_B1F_Text_GX:
	.string "When I grow up, I'm going to\n"
	.string "attend Duel Academy!$"

SootopolisCity_NewGym_B1F_Text_NewDeck:
	.string "My big brother taught me how\n"
	.string "to play Boarder stun!$"

SootopolisCity_NewGym_B1F_Text_Ratios:
	.string "I'm learning optimal ratios for\n"
	.string "deckbuilding today.$"

SootopolisCity_NewGym_B1F_Text_YoungerKids:
	.string "I heard a younger kid using some\n"
	.string "completely off the wall phrases.\p"
	.string "What is going on these days?$"

SootopolisCity_NewGym_B1F_Text_Shrimp:
	.string "I'm learning from a shrimp how\n"
	.string "to properly fry rice.$"

SootopolisCity_NewGym_B1F_Text_NadhirIntro:
	.string "You! Do you know about Raye's\n"
	.string "Bonus Cards?\p"
	.string "…What do you mean, I look familiar?$"

SootopolisCity_NewGym_B1F_Text_NadhirDefeat:
	.string "A Gym Leader? No, I just teach\n"
	.string "about Bonus Cards.$"

SootopolisCity_NewGym_B1F_Text_NadhirPostBattle:
	.string "Who's Farfa?\n"
	.string "Is he from Glasgow?$"

SootopolisCity_NewGym_B1F_Text_NadhirBonusCards:
	.string "Well, now you've learned something!\n"
	.string "Probably.\p"
	.string "Pickle Jeff.$"

SootopolisCity_NewGym_B1F_Text_CalebIntro:
	.string "How much do you know about\n"
	.string "time sinks?$"

SootopolisCity_NewGym_B1F_Text_CalebDefeat:
	.string "See, this was a time sink.$"

SootopolisCity_NewGym_B1F_Text_CalebPostBattle:
	.string "Should probably arrange another\n"
	.string "podcast episode.$"

SootopolisCity_NewGym_B1F_Text_CalebTopic:
	.string "How much did you learn from that?$"

SootopolisCity_NewGym_B1F_Text_DarthNashIntro:
	.string "Today, you'll learn about some\n"
	.string "Duel Terminal lore!$"

SootopolisCity_NewGym_B1F_Text_DarthNashDefeat:
	.string "Ah, right. Wrong game.$"

SootopolisCity_NewGym_B1F_Text_DarthNashPostBattle:
	.string "How does one solo a glass of water?$"

SootopolisCity_NewGym_B1F_Text_DarthNashTopic:
	.string "Well, uh. That was an educational\n"
	.string "battle, right?$"

SootopolisCity_NewGym_B1F_Text_ScarletIntro:
	.string "“I am being as precise as a\n"
	.string "tiger hunting its prey.”\p"
	.string "Real quote from one of my students.$"

SootopolisCity_NewGym_B1F_Text_ScarletDefeat:
	.string "You're manually breathing.$"

SootopolisCity_NewGym_B1F_Text_ScarletPostBattle:
	.string "Our Gym Leader approves of\n"
	.string "diss tracks.$"

SootopolisCity_NewGym_B1F_Text_ScarletTopic:
	.string "You have learned that my students\n"
	.string "are funnier than me.$"


