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
#include <string>

using namespace std;

const int Paints = 4;


//namespace Paints
//{
//	//Namespace for presets for paints
//	// Contains two structures one for colours and axis
//
//	struct Preset_Paints
//	{
//		Colours  Paint_Colour_Name;
//		uint32_t Paint_Colour_Code;
//		uint8_t  Spreading_Rate;	 
//	};
//
//	//A data structure of four preset choices
//	Preset_Paints Presets_Paints[Paints]
//	{
//		{White, 0xFFFFFF, 10},	
//		{White, 0xFFFFFF, 10},
//		{           		},
//		{                   } 
//	};
//
//	//uint16_t Get_Paint_Colour_Code(Colours Paint_Colour_Name)
//	//{
//	//	return Presets_Paints[Paint_Colour_Name].Paint_Colour_Code;
//	//};
//	//uint16_t Get_Spreading_Rate(Colours Paint_Colour_Name)
//	//{
//	//	return Presets_Paints[Paint_Colour_Name].Spreading_Rate;
//	//};
//}


Generic_Room::Generic_Room
  (int Length_In,  
   int Width_In, 
   int Height_In)
	// Constructor -   (Length)   
	//                 (Width)  
	//                 (Height)  
{
	Length = Length_In;
	Width  = Width_In;
	Height = Height_In;
}

void Calculate_Area_Private(void)
{
	Area = Length * Width;
}

void Calculate_Volume_Private(void)
{
	Volume = ((Length) * (Width) * (Height));
}

void Initialise(void)
{
	Calculate_Area_Private();
	Calculate_Volume_Private();
}

int Generic_Menu::Calculate_Area(void)
{
	Area = Length * Width;
    return Area;
}

int Generic_Menu::Return_Area(void)
{
	return Area;
}

int Generic_Menu::Get_Volume(void)
{
	Volume = ((Length) * (Width) * (Height));
	return Volume;
}

int Generic_Menu::Return_Volume(void)
{
	return Volume;
}

