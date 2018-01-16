/**************************************************************************************************
*                  <2018> Room
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

#include "stdafx.h"
#include "Room_Class.h"
#include <iostream>
using namespace std;

int main()
{
	while(1)
	{
		cout << "Hello";
		cout << '\n';
		cout << "Welcome to the room measurements calculator \n";
		int Length_In = 0;
		cout << "Please enter the room Length (m): \n";
		cin >> Length_In;
		int Width_In = 0;
		cout << "Please enter the room Width (m): ";
		cin >> Width_In;
		int Height_In = 0;
		cout << "Please enter the room Height (m): ";
		cin >> Height_In;
		Generic_Room Room
		(Length_In,
         Width_In,
		 Height_In);
	}
    return 0;
}

