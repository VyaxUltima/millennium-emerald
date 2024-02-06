PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "Nyhmnim became our town's new\n"
	.string "Gym Leader.\p"
	.string "I think he banned some people.$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "I battled Nyhmnim once, but, whew,\n"
	.string "he was way too rich.\p"
	.string "How would I put it?\p"
	.string "I just got the feeling that he\n"
	.string "lives for sealed-only.$"

