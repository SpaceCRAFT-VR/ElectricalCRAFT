#include "./../libraries/Circuit_Display.h"

#include <map>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h> // for stoi

using std::string;
using std::to_string;
using std::cout;
using std::map;

using std::stof;

Circuit_Display::Circuit_Display()
{

}

void Circuit_Display::get_data()
{
	customVARIABLE = interface.recv_HW();
}

void Circuit_Display::init()
{
	//OPTIONAL:
	// Get your System's instance parameters
	
	customVARIABLE = Circuit_Display::interface.connect();
	cout<<"donioni"<<endl;
	// Can do as many as you want
}

void Circuit_Display::update()
{
	Circuit_Display::get_data();
  map<string, string> paramList;

  // List of parameters you need to perform your calculations
  float   locationX;
  float   velocityX;

	cout<<customVARIABLE<<","<<entities.size()<<endl;
	string agr = "";
	string temp = "";
	string hum = "";
	for(int i =0;i<customVARIABLE.length();i++){
		
		if(customVARIABLE[i] == ','){
			temp = agr;
			agr="";
			
		}
		else if(customVARIABLE[i] == '\r' ||
				customVARIABLE[i] == '\n'){
					break;
					
		}
		else{
			agr += customVARIABLE[i];
		}
	}
	hum = agr;
  for (int i = 0; i < entities.size(); i++)
	{
		string target = entities.at(i)->getName();
		cout<<target<<",";
		if(target == "Circuit_Display2" ){
			cout<<"here"<<endl;
			paramList  = entities.at(i)->getParameters();
			
			entities.at(i)->setParameter( "Temperature", 
										temp );
			entities.at(i)->setParameter( "Humidity", 
										hum );
										
		}
  		

            

	}
	cout<<endl;
}

extern "C"
{
  Circuit_Display* create(map<string, string> properties)
  {
    // Create new instance and return
    Circuit_Display* newInstance = new Circuit_Display();

    // Set parameters Here
    newInstance->setProperties(properties);

    return newInstance;
  }
}
