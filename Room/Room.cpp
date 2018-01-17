/*                  <2018> Room
***************************************************************************************************
*Project:          Room
*File Name:        Room.cpp
*Description:      Main file in the project, calls the class library to create a instance of a room
***************************************************************************************************
*Change History:
*   Version        Date            Author          Description
*   -------        ----            ------          -----------
*   1.0            17/01/18        Rubber-Duck-999 First version created for use in calculating room
*                                                  measurements
*
**************************************************************************************************/



//////////////////////////////////////////////////////////
/*
              Pre processor directives 
			  - Tells the compiler which headers or libraries 
			  - to compile at program runtime
*/
//////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Namespace std allows the user to not have to declare a string
//as a type from the namespace std
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
/*
              Declared Constants
			  - Sets the pins for this particular program
			  - only constants are set not global 
			  - variables
*/
//////////////////////////////////////////////////////////
const int   TOTAL_DIMENSIONS       = 3;
//Number of maximum dimensions
const int   WINDOW_DIMENSIONS      = 2;
//Number of dimensions per Window
const float PAINT_SPREAD_PER_LITRE = 11;
//Area m2 per litre for the paint
const vector <string> dimensionNames = { "height", "width", "length" };
//One dimensional vector of the dimension names in the string type
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
/*
              Declared Enum
              - Allows the object to reference a string like 
			  - character to index into a array that has
			  - a integer value
*/
//////////////////////////////////////////////////////////
enum Dimension
{
    HEIGHT,
    WIDTH,
    LENGTH
};
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
/*
              Declared Generic_Room Class
			  - Creating an object for the room lets the user
			  - create multiple rooms without constantly 
			  - reproducing functions and code
*/
//////////////////////////////////////////////////////////
class Generic_Room
{//Class
	private:
		vector<float>         dimensions_;
		float                 area_;
        float                 volume_;
        float                 windows_;
        float                 totalWindowsArea_ = 0.0;
		vector<float>         windowsArea_;
		float                 coats_;
        vector<vector<float>> windowDimensions_;
        string Switch;
		//Setup of all the private member variables which
		//can only be accessed from this class's member
		//functions
public:
	void Initialise(void);
	void setDimensions(void);
	void setWindows(void);
	void getPaintRequired(void);
	void calculateArea(void);
	void calculateVolume(void);
	void calculateWindowAreas(void);
	void calculateTotalWindowArea(void);
	void getTotalWindowArea(void);
	//Declaration of the public member functions
	//all of the functions are are of the function type void
    //which means they have no return values
    //The void in their parameter inputs is void stating that they have no inputs,
    //this is not necessary in c++ but as the designer of the program
    //it helps with absolutely stating that fact	
};
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
/*
              Initialise Room Object Function
			  - Follows through the required sequence of
			  - functions to return three needed values
*/
//////////////////////////////////////////////////////////
void Generic_Room::Initialise(void)
{
	cout << "Hello";
	cout << '\n';
	cout << "Welcome to the room measurements calculator \n";
	cout << "Would you like to begin? (Yes/No)\n";
	//These four lines above print on the console
	//They start the program off by asking the user would he like to begin?
	//He has two choices listed but only one correct answer will start the program and
	//its stated in the string to ensure the user inputs that exact answer
	
	cin >> Switch;
	//Cin function sets the input typed on the console by the
	//user to the variable string Switch
	
	if (Switch == "Yes")
	{			
	    setDimensions();
		//Calls the set dimensions function first which
		//asks the user to input the dimensions of the room
		
		calculateArea();
		//calculateArea function takes no inputs nor passes out any inputs
		//only assigns the private member variable Area a value calculated
		//from multiplying width x length of the room
		
		calculateVolume();
		//calculateVolume is very similar to that of the function above
		//only difference is it assigns a value to the member variable Volume
		
		setWindows();
		//setWindows is of the most complicated functions called by the Initialise function
		//contains loop inside a loop that provides the function of saving window dimensions to a 
		//vector inputted by the user
		
		calculateWindowAreas();
		//Passed into the vector windowDimensions_, this function takes each window and its dimensions
		//then multiplies them together to create each window area
		//reason this was done over a array is you run into unbounded array sizes issues as you would 
		//a undeclared two dimensional array that s no decided how many windows it has until the program
		//asks the user
		
		calculateTotalWindowArea();
		//Add on to the previous function, all individual window areas are added together into 
		//one float area for the combined windows area
		
        getPaintRequired();
		//getPaintRequired asks the user the final question of how many coats of paint do
		//they require to paint their room then uses all member variables to calculate 
		//a precise value for litres of paint needed
	}
	else
	{
	    cout << "Have a nice day!\n";	
        //If the user decides to not get started this message will be shown and the program will
        //not continue until they re-run the file		
	}
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
/*
    Definition of setDimensions
	-Loop that calls three times for the value of each 
	-dimension then pushes it into the dimensions vector
*/
//////////////////////////////////////////////////////////
void Generic_Room::setDimensions(void)
{
    for (int i = 0; i < TOTAL_DIMENSIONS; i++)
    {
        float temporaryDimension = 0;
        
        cout << "Please enter the " << dimensionNames[i] << " of the room in metres.\n";
		//Each loop cycle i is replaced with a string from the dimensionNames vector

        cin >> temporaryDimension;
        
        dimensions_.push_back (temporaryDimension);
		//push into dimensions vector 
    }
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
/*
    Definition of calculateArea
	-calculateArea function takes no inputs nor passes out any inputs
	-only assigns the private member variable Area a value calculated
	-from multiplying width x length of the room
*/
//////////////////////////////////////////////////////////
void Generic_Room::calculateArea(void)
{
	area_ = dimensions_[LENGTH] * dimensions_[WIDTH];
	//Area is assigned to Length variable multiplied by the Width variable
	//in the dimensions vector
	cout << "Room floor area (m^2): \n";
    cout << area_ << "\n";
	cout << "\n";
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
/*
    Definition of calculateVolume
	-calculateVolume is very similar to that of the function above
	-only difference is it assigns a value to the member variable Volume
*/
//////////////////////////////////////////////////////////
void Generic_Room::calculateVolume(void)
{
	volume_ = dimensions_[LENGTH] * dimensions_[WIDTH] * dimensions_[HEIGHT];
	//Volume is assigned to Length variable multiplied by the Width variable
	//and by the Height variable in the dimensions vector	
	cout << "\n";
    cout << "Room Volume (m^3): \n";
	cout << volume_ << "\n";
	cout << "\n";
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
/*
    Definition of setWindows
	-setWindows is of the most complicated functions called by the initialiser function
	-contains loop inside a loop that provides the function of saving window dimensions to a 
	-vector inputted by the user
*/
//////////////////////////////////////////////////////////
void Generic_Room::setWindows(void)
{
	cout << "How many windows do you have? (E.g 2)\n";
	cin >> windows_;
	//Asks the user how many windows they have then
	//assigns it to the member variable windows_
	
	for(int i = 0; i < windows_; i++)
	{
        windowDimensions_.push_back(vector<float>());
        //First loop winds through windowDimensions outer vector and starts
		//a new row, the loop end counter is decided by how many windows were
		//entered by the user
	    for(int j = 0; j < WINDOW_DIMENSIONS; j++)
	    {
	        float temporaryDimension = 0;
	        
	        cout << "Please enter window number "<< i + 1 << "'s " << dimensionNames[j] << " in metres.\n";
	        cin >> temporaryDimension;
	        //Second loop that is inside vector for the dimensions of the window assignment
			//The first line above outputs the window number and the dimension name value needed
			
	        windowDimensions_[i].push_back (temporaryDimension);
			//Placing of the temporary float into the vector inside a vector window dimension
	    }
	}
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
/*
    Definition of calculateWindowAreas
	-Passed into the vector windowDimensions_, this function takes each window and its dimensions
	-then multiplies them together to create each window area
	-reason this was done over a array is you run into unbounded array sizes issues as you would 
	-a undeclared two dimensional array that s no decided how many windows it has until the program
	-asks the user
*/
//////////////////////////////////////////////////////////
void Generic_Room::calculateWindowAreas(void)
{
    for(int i =0; i < windows_; i++)
    {
        windowsArea_.push_back(windowDimensions_[i][HEIGHT] * windowDimensions_[i][WIDTH]);
    }
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
/*
    Definition of calculateTotalWindowArea
	-Add on to the previous function, all individual window areas are added together into 
	-one float area for the combined windows area
*/
//////////////////////////////////////////////////////////
void Generic_Room::calculateTotalWindowArea(void)
{
    for(int i = 0; i < windows_; i++)
	{
	   totalWindowsArea_ += windowsArea_[i];
	}
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
/*
    Definition of getTotalWindowArea
	-Add on to the previous function, this function allows the user
	-to see the total window area, it is not called upon 
	-so it is unused code but also future possibility
*/
//////////////////////////////////////////////////////////
void Generic_Room::getTotalWindowArea(void)
{
    cout << totalWindowsArea_ << " m^2\n";
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
/*
    Definition of getTotalWindowArea
	-getPaintRequired asks the user the final question of how many coats of paint do
	-they require to paint their room then uses all member variables to calculate 
	-a precise value for litres of paint needed
*/
//////////////////////////////////////////////////////////
void Generic_Room::getPaintRequired()
{
	cout << "How many coats of paint do you need? (E.g 3)\n";
	cin >> coats_;    
	cout << "\n";
	//Asks for the number of coats required to the use for amount of paint needed
	
    float longWallsArea = ((dimensions_[LENGTH] * dimensions_[HEIGHT]) * 2.0);
	//First local assignment where the assumption that the room is rectangle comes into
	//play. The area of the long walls is calculated by the length * height
	
    float shortWallsArea = ((dimensions_[WIDTH] * dimensions_[HEIGHT]) * 2.0);
	//The area of the short walls is calculated by the width * height
	
    float totalWallArea = shortWallsArea + shortWallsArea;
	//This assignment adds all areas of the walls together
	
    float totalWallAreaMinusWindows = totalWallArea - totalWindowsArea_;
	//This takes the windowsArea from the WallArea to have the WallArea for non windows wall area
	
    float totalPaintForOneCoat =  totalWallAreaMinusWindows / PAINT_SPREAD_PER_LITRE;
    //Calculates the required paint per all the walls for one coat of paint
	
    float totalPaintForAllCoats = totalPaintForOneCoat * coats_;
	//Calculates the required paint per all the walls for the needed number of coats of paint
	cout << "You need approximately "<< totalPaintForAllCoats << " litres of paint for " << coats_ << " coats.\n";
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
/*
    Definition of Object_Instance
	-Creates an instance of the object
	-called by main function
*/
//////////////////////////////////////////////////////////
void Object_Instance(void)
{
	Generic_Room Room;
	//Creates an instance of the Generic_Room object called Room
	
	Room.Initialise();
	//Setups the Room instance
}
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
/*
    Definition of main
	-Calls Object_Instance function
*/
//////////////////////////////////////////////////////////
int main()
{
    Object_Instance();
    return 0;
}
//////////////////////////////////////////////////////////