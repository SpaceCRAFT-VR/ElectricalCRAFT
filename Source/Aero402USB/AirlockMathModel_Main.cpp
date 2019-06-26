// Fill out your copyright notice in the Description page of Project Settings.

#include "AirlockMathModel_Main.h"


// Sets default values for this component's properties
UAirlockMathModel_Main::UAirlockMathModel_Main()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAirlockMathModel_Main::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAirlockMathModel_Main::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UAirlockMathModel_Main::AirlockAirFunc(float DeltaTime, float mdot_in, bool bIsOn)
{
	if (bIsOn)
	{

		// If switch is on, air is accumulated in airlock at rate mdot_in
		if (Vol_AirShower_AL >= Vol_Current_AL)
		{
			Vol_Current_AL = Vol_Current_AL + mdot_in*DeltaTime;
		}
		else
		{
			mdot_in = 0;
			bIsLightOn = true;
		}
	}

	return Vol_Current_AL;
}

