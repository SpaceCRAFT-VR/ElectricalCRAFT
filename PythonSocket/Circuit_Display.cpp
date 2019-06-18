#include "./../libraries/Circuit_Display.h"

#include <map>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h> // for stoi

// using std::string;
// using std::to_string;
// using std::cout;
// using std::map;

// using std::stof;

using namespace std;

Circuit_Display::Circuit_Display()
{

}

// void Circuit_Display::get_data()
// {
// 	// customVARIABLE = interface.recv_HW();
// }

void Circuit_Display::init()
{

}

void Circuit_Display::update()
{
	// Circuit_Display::get_data();
  map<string, string> paramList;

  // List of parameters you need to perform your calculations
  string   voltage;
  string   current;

    cout<<"Print out Circuit Entity Size"<<endl;
	// cout<<customVARIABLE<<","<<entities.size()<<endl;



  for (int i = 0; i < entities.size(); i++)
	{
	  	paramList  = entities.at(i)->getParameters();

		// Lookup the paramaters you need inside return map
		//get Name of component
		string target = entities.at(i)->getName();
		cout<<"Here is Maria's Electrical Sim"<<endl;

		//Update Parameter Values
		voltage = "3.3v";
		current = "1.2mA";

		//Update the entity data
		entities.at(i)->setParameter( "Voltage", voltage);
		entities.at(i)->setParameter( "Current", current);

	}
	cout << endl ;
}

extern "C"
{
  Circuit_Display* create(map<string, string> parameters)
  {
    // Create new instance and return
    Circuit_Display* newInstance = new Circuit_Display();

    // Set parameters Here
    newInstance->setProperties(parameters);

    return newInstance;
  }
}
