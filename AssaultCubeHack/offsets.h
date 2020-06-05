#define application L"ac_client.exe"
#define applicationName L"AssaultCube"

//Game offsets
#define player_offset 0x10F4F4
#define view_matrix_offset 0x101AE8 
#define entity_list_offset 0x10F4F8 
#define ac_client_ammoOffsets 0x374,0x14,0x0 

/*
// in assault cube entity list is an array of entity pointers
// the first element is always empty
*/


//Player offsets
#define name_offset 0x225 // max len of name seems to be 20
#define health_offset 0xF8
#define number_of_player_offset 0x0C
#define team_offset 0x032C 

#define headPos_offset 0x04 // 3 floats X,Y,Z
#define footPos_offset 0x34 // 3 floats X,Y,Z

#define yaw_offset 0x40
#define pitch_offset 0x44







//f4f4 is you (player)
//f4f8 is entity list, first element in the list is always empty
//headpos 0x04


//size of player is 0x0349?

