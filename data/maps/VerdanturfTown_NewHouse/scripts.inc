VerdanturfTown_NewHouse_MapScripts::
	.byte 0

VerdanturfTown_House_Photo::
	msgbox VerdanturfTown_House_Text_Lily, MSGBOX_SIGN
	clearflag FLAG_HIDE_MT_PYRE_VYAX
	end

VerdanturfTown_House_Desktop::
	msgbox VerdanturfTown_House_Text_Development, MSGBOX_SIGN
	end

VerdanturfTown_House_Text_Lily:
	.string "It appears to be a photo of a cat.\n"
	.string "There's something written under it.\p"
	.string "“Lily”\n"
	.string "September 22, 2012 - March 17, 2024$"

VerdanturfTown_House_Text_Development:
	.string "There's a ton of files.\n"
	.string "You can read various bits of code…\p"
	.string "The open project appears to be\n"
	.string "called Millennium Emerald.\p"
	.string "Perhaps this workspace is used by\n"
	.string "the lead developer.$"

