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


#ifndef _ROOM_CLASS_h
#define _ROOM_CLASS_h

#define Black 
const string  = 0;

namespace Presets
{
	uint16_t Get_Paint_Colour_Code(char[] Colour_Name);
}


class Generic_Menu
{//Class
	private:
	  //Allows access to sub-classes

	  uint8_t  Length,  
      uint8_t  Width, 
      uint8_t  Height
	  uint16_t Area;
	  uint32_t Volume;
	  
public:
   
	// Constructor -   (Length)   
	//                 (Height)  
	//                 (Width)  
      Generic_Room 
	     (uint8_t Length,  
          uint8_t Width, 
          uint8_t Height);
	  

};

#endif
