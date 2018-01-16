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
		 string Colour_Name;
		 
		 
	};

	//A data structure of four preset choices
	Preset_Paints Presets_Paints[2]
	{
		{
			
		},
		
		{

		},
		
		{
			
		},
		{

		} 
	};

	uint16_t Get_Paint_Colour_Code(char[] Colour_Name)
	{
		return Presets_Paints[Preset_Choice].Array_Of_Colours[Colour_Choice];
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


uint16_t Generic_Menu::Get_Area(uint8_t Length, uint8_t Width)
{
	Area = Length * Width;
    return Area;
}

uint32_t Generic_Menu::Get_Volume()
{
	Volume = ((Length) * (Width) * (Height));
    return Area
}


