/*                  <2018> Room
***************************************************************************************************
*Project:          Room
*File Name:        Room_Class.cpp
*Description:      Main file in the project, calls the class library to create a instance of a room
***************************************************************************************************
*Change History:
*   Version        Date            Author          Description
*   -------        ----            ------          -----------
*   1.0            24/10/17        Rubber-Duck-999 First version created for display, lack of comments
*                                                  Will be added
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

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int Set_Max_String = 3;
const int Array_Max_Value = 2;
const float Paint_Spread_Per_Litre = 11;
//Area m2 per litre for the paint
const string String_Name[Set_Max_String] = {"Height","Width", "Length"};
const int Max_Array = 4;


enum Dimension
{
    HEIGHT,
    WIDTH,
    LENGTH
};


class Generic_Room
{//Class
	private:
		float  Length;
		float  Width;
		float  Height;
		float  Area;
        float  Volume;
        float  Paint_Required;
        float  Windows;
        float  Window_Area;
		float  Windows_Area[Max_Array];
		float  Coats;
        float  Dimensions_Window_Array[][Array_Max_Value];
        string Switch;
public:
	void Initialise(void);
	void Inputs(void);
	void Get_Area_Windows(void);
	void Get_Paint_Required(void);
	void Calculate_Area(void);
	void Calculate_Volume(void);
};

void Generic_Room::Initialise(void)
{
	cout << "Hello";
	cout << '\n';
	cout << "Welcome to the room measurements calculator \n";
	cout << "Would you like to begin? (Yes/No)\n";
	cin >> Switch;
	if (Switch == "Yes")
	{			
	    Inputs();
		Calculate_Area();
		Calculate_Volume();
		Get_Area_Windows();
        Get_Paint_Required();
	}
	else
	{
	    cout << "Have a nice day!\n";	    
	}
}

void Generic_Room::Inputs(void)
{
   	cout << "Please enter the room Height? (m)\n";
	cin >> Height;
	cout << "\n";
	cout << "Please enter the room Width? (m)\n";
	cin >> Width;
	cout << "\n";
	cout << "Please enter the room Length? (m)\n";
	cin >> Length;
	cout << "\n"; 
}

void Generic_Room::Calculate_Area(void)
{
	Area = Length * Width;
	cout << "Room floor area (m*2): \n";
    cout << Area << "\n";
	cout << "\n";
}

void Generic_Room::Calculate_Volume(void)
{
	Volume = ((Length) * (Width) * (Height));
	cout << "\n";
    cout << "Room Volume (m*3): \n";
	cout << Volume << "\n";
	cout << "\n";
}

void Generic_Room::Get_Area_Windows(void)
{
	cout << "How many windows do you have? (E.g less than 5)\n";
	cin >> Windows;
	int j = 0;
	int k = 0;
	for(j = 0; j < Windows; j++)
	{
	    k = 0;
	    for(k = 0; k < Array_Max_Value; k++)
	    {
	        cout << "Please enter the window no. "<< j + 1 << "'s " << String_Name[k] << "? (m)\n";
	        cin >> Dimensions_Window_Array[j][k]; 
	    }
	    k = 0;
		Windows_Area[j] = Dimensions_Window_Array[j][k] * Dimensions_Window_Array[j][k+1];
	}
	int x = 0;
	for(x = 0; x < Windows; x++)
	{
	    Window_Area += Windows_Area[x];
	}
	cout << Window_Area << " m*2\n";
}

void Generic_Room::Get_Paint_Required()
{
	cout << "How many coats of paint do you need? (E.g 3)\n";
	cin >> Coats;    
	cout << "\n";
	
    //Paint_Required = (Coats * (((((Length * Height) * 2) + ((Width * Height) * 2)) - Window_Area) / Paint_Spread_Per_Litre));
    float Long_Walls = ((Length * Height) * 2.0);
    cout << Long_Walls << "\n";
    
    float Short_Walls = ((Width * Height) * 2.0);
    cout << Short_Walls << "\n";
    
    float Total_Wall_Area = Long_Walls + Short_Walls;
    cout << Total_Wall_Area << "\n";
    
    float Wall_Area_Windows = Total_Wall_Area - Window_Area;
    cout << Wall_Area_Windows << "\n";
    
    float Total_Area_Per_Litre =  Wall_Area_Windows / Paint_Spread_Per_Litre;
    cout << Total_Area_Per_Litre << "\n";
    
    float Total_Area_Coats = Total_Area_Per_Litre * Coats;
	cout << Total_Area_Coats << " Litres\n";
}

void Object_Instance(void)
{
	Generic_Room Room;
	Room.Initialise();
}

int main()
{
    Object_Instance();
    return 0;
}


