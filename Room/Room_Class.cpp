/**************************************************************************************************
*                  <2018> Room
*          Please refer to license.txt for the
*          legal contents of this software build
***************************************************************************************************
*Project:          Room
*File Name:        Room_Class.cpp
*Description:      Main file in the project, calls the class library to create a instance of a room
***************************************************************************************************
*Change History:
*   Version        Date            Author          Description
*   -------        ----            ------          -----------
*   1.0            24/10/17        Rubber-Duck-999 The comment lines must not be edited, this is a
*                                                  set format that must be followed
*
***************************************************************************************************
*
*Parameters:
*   Name           Direction       Description
*   ----           ---------       ----
*   Input_Type     Input           This is a type value
*   Output_Type    Output          This is a type value
*
***************************************************************************************************/


#include "Room_Class.h"
#include <stdint.h>
#include <string>

using namespace std;

const uint8_t Paints = 4;

enum Colours
{
	Pink,
	Red,
	Blue,
	White
};


namespace Paints
{
	//Namespace for presets for paints
	// Contains two structures one for colours and axis

	struct Preset_Paints
	{
		Colours  Paint_Colour_Name;
		uint32_t Paint_Colour_Code;
		uint8_t  Spreading_Rate;	 
	};

	//A data structure of four preset choices
	Preset_Paints Presets_Paints[Paints]
	{
		{White, 0xFFFFFF, 10},	
		{                   },
		{           		},
		{                   } 
	};

	uint16_t Get_Paint_Colour_Code(Colours Paint_Colour_Name)
	{
		return Presets_Paints[Paint_Colour_Name].;
	};
	uint16_t Get_Paint_Colour_Code(Colours Paint_Colour_Code)
	{
		return Presets_Paints[Paint_Colour_Name].;
	};
}


Generic_Room::Generic_Room
(uint8_t Length,  
 uint8_t Width, 
 uint8_t Height)
	// Constructor -   (Length)   
	//                 (Width)  
	//                 (Height)  
{
	//Constructor Function
	//Initialises all Member Values

}

uint16_t Calculate_Area_Private(void)
{
	Area = Length * Width;
	return Area;
}

uint32_t Calculate_Volume_Private(void)
{
	Volume = ((Length) * (Width) * (Height));
	return Volume;
}


uint16_t Generic_Menu::Calculate_Area(void)
{
	Area = Length * Width;
    return Area;
}

uint32_t Generic_Menu::Get_Volume(void)
{
	Volume = ((Length) * (Width) * (Height));
	return Volume;
}



