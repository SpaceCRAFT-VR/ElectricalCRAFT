// Fill out your copyright notice in the Description page of Project Settings.

#include "AL_AirMathematicalMark_Final.h"


// Sets default values for this component's properties
UAL_AirMathematicalMark_Final::UAL_AirMathematicalMark_Final()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAL_AirMathematicalMark_Final::BeginPlay()
{
	Super::BeginPlay();

	nmoles_air_max_AL = (pHab*Vol_Mudroom_AL) / (R * Temp_Hab); // This is the max pressure that we want to achieve
	nmoles_air_min_AL = (pMoon*Vol_Mudroom_AL) / (R * Temp_Hab); // This is the Min Pressure Achievable on the surface without generating hella vacuum
	if (isEmpty)
	{
		nmoles_air_0_AL = nmoles_air_min_AL; // Sets the initial "mass" in the airlock to 0
		nmoles_air_curr_AL = nmoles_air_0_AL; // Sets the current "mass" in the airlock to the same as the initial
		pCurr = pMoon; // Sets the interior pressure to that of the moon.
	} // End of the True Case
	else
	{
		nmoles_air_0_AL = nmoles_air_max_AL; // This calculates the number of moles of air in the airlock at the beginning
		nmoles_air_curr_AL = nmoles_air_0_AL; // Sets the current "mass" in the airlock to the same as the initial
		pCurr = pHab; // Sets the interior pressure to that of the habitat.
	} // End of the case if the Airlock is filled with Gas initially.
	  // ...
	
}


// Called every frame
void UAL_AirMathematicalMark_Final::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UAL_AirMathematicalMark_Final::AirlockAirFunc(float DeltaTime, float mdot_in, bool bIsOn, bool dIsOn)
{
	if (bIsOn)
	{
		// If switch is on, air is accumulated in airlock at rate mdot_in
		if (nmoles_air_max_AL >= nmoles_air_curr_AL)
		{
			// This will check whether mdot_in is trying to push more air to the system that the average
			if (mdot_in != mdot_avg)
			{
				nmoles_air_curr_AL = nmoles_air_curr_AL + mdot_in / mmAir * DeltaTime; // This adds air to the airlock
				nmoles_air_fin_AL = nmoles_air_curr_AL; // This is setting the final amount of air to the current amount of air in the facilitiy.
				pCurr = (R*Temp_Hab*nmoles_air_curr_AL) / (Vol_Mudroom_AL);  // This calculates the current pressure in the Mudroom
			} // This case is using an mdot that is different from the average
			else
			{
				nmoles_air_curr_AL = nmoles_air_curr_AL + mdot_avg / mmAir * DeltaTime; // This adds air to the airlock
				nmoles_air_fin_AL = nmoles_air_curr_AL; // This is setting the final amount of air to the current amount of air in the facilitiy.
				pCurr = (R*Temp_Hab*nmoles_air_curr_AL) / (Vol_Mudroom_AL);  // This calculates the current pressure in the Mudroom
			} //  This is the case that we just use the average air
		} //Adding to the volume
	} // Checking if the Airlock is pressurizing
	else if (dIsOn)
	{
		// If switch is on, air is accumulated in airlock at rate mdot_in
		if (nmoles_air_curr_AL >= nmoles_air_min_AL)
		{
			// This will check whether mdot_in is trying to push more air to the system that the average
			if (mdot_in != mdot_avg)
			{
				nmoles_air_curr_AL = nmoles_air_curr_AL - mdot_in / mmAir * DeltaTime; // This adds air to the airlock
				nmoles_air_fin_AL = nmoles_air_curr_AL; // This is setting the final amount of air to the current amount of air in the facilitiy.
				pCurr = (R*Temp_Hab*nmoles_air_curr_AL) / (Vol_Mudroom_AL);  // This calculates the current pressure in the Mudroom
			} // This case is using an mdot that is different from the average
			else
			{
				nmoles_air_curr_AL = nmoles_air_curr_AL - mdot_avg / mmAir * DeltaTime; // This adds air to the airlock
				nmoles_air_fin_AL = nmoles_air_curr_AL; // This is setting the final amount of air to the current amount of air in the facilitiy.
				pCurr = (R*Temp_Hab*nmoles_air_curr_AL) / (Vol_Mudroom_AL);  // This calculates the current pressure in the Mudroom
			} //  This is the case that we just use the average air
		} //Adding to the volume
	} // Check if the airlock is depressurizing
	else
	{
		nmoles_air_curr_AL = nmoles_air_curr_AL; // Just setting the number of moles equal
		bIsLightOn = true;
	} //This is holding off adding any mass until a second has passed
	return pCurr;
}


float UAL_AirMathematicalMark_Final::UAL_AirMathmaticalMark_getma0AL()
{
	return nmoles_air_0_AL; // returns the initial amount of air
}


float UAL_AirMathematicalMark_Final::UAL_AirMathmaticalMark_getmafAL()
{
	return nmoles_air_fin_AL;
} // Get the final number of moles


float UAL_AirMathematicalMark_Final::AirlockLossFunc(float moles_air_0_AL, float moles_air_fin_AL)
{
	massOut = mmAir * (moles_air_fin_AL - moles_air_0_AL); // Calculate the amount of air reused
	massLoss = massOut * (1 - efficency_AL); //Calculate the amount of air that we lose on operation
	massOut = massOut * efficency_AL; // This is the amount of air we send to HAL
	return massOut;
} // This function calculates how much air has been lost through airlock operations


float UAL_AirMathematicalMark_Final::UAL_AirMathmaticalMark_getmassLoss()
{
	return massLoss;
} // Returns the amount of lost air


float UAL_AirMathematicalMark_Final::UAL_AirMathmaticalMark_openDoor()
{
	nmoles_air_curr_AL = nmoles_air_min_AL; // This sets the number of moles in the airlock interior to the minimum available to our system.
	pCurr = pMoon; // This sets the pressures for each system equal
	return 1.0;
} // How the model will react if a door is opened




