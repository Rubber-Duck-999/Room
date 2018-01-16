/**************************************************************************************************
*                  <2018> Room
*          Please refer to license.txt for the
*          legal contents of this software build
***************************************************************************************************
*Project:          Room
*File Name:        Room_Class.h
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

enum Colours
{
	Pink,
	Red,
	Blue,
	White
};

//namespace Paints
//{
//	//uint16_t Get_Paint_Colour_Code(Colours Paint_Colour_Name);
//	//uint16_t Get_Spreading_Rate(Colours Paint_Colour_Name);
//};


class Generic_Room
{//Class
	private:
	  //Allows access to sub-classes
		int Length;
		int Width;
		int Height;
		int Area;
        int Volume;
		void Calculate_Area_Private(void);
		void Calculate_Volume_Private(void);
	  
public:
   
	// Constructor -   (Length)   
	//                 (Height)  
	//                 (Width)  
    Generic_Room 
	   (int Length,  
        int Width, 
        int Height);

	void Initialise(void);
	int Calculate_Area(void);
	int Calculate_Volume(void);
	int Return_Area(void);
	int Return_Volume(void);
};

#endif

