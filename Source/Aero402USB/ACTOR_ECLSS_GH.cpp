// Fill out your copyright notice in the Description page of Project Settings.

#include "ACTOR_ECLSS_GH.h"


// Sets default values
AACTOR_ECLSS_GH::AACTOR_ECLSS_GH()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AACTOR_ECLSS_GH::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AACTOR_ECLSS_GH::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<float> AACTOR_ECLSS_GH::GHAirModel_FuncV2(float DeltaSeconds, float AirMassRate_Hab2GH, float AirComp_Hab2GH_O2, float AirComp_Hab2GH_CO2, float AirComp_Hab2GH_Other, float AirMassGH_O2, float AirMassGH_CO2, float AirMassGH_Other)
{
	AirMassGH_O2 = AirMassGH_O2 + DeltaSeconds*AirMassRate_Hab2GH*AirComp_Hab2GH_O2;
	AirMassGH_CO2 = AirMassGH_CO2 + DeltaSeconds*AirMassRate_Hab2GH*AirComp_Hab2GH_CO2;
	AirMassGH_Other = AirMassGH_Other + DeltaSeconds*AirMassRate_Hab2GH*AirComp_Hab2GH_Other;

	AirMassGH = AirMassGH_O2 + AirMassGH_CO2 + AirMassGH_Other;

	AirComp_GH_O2 = AirMassGH_O2 / AirMassGH;
	AirComp_GH_CO2 = AirMassGH_CO2 / AirMassGH;
	AirComp_GH_Other = AirMassGH_Other / AirMassGH;



	//Internal Processes


	//Plant Respiration
	PlantO2GenRate = 8 / (3600 * 24); //Generation per second for 1 petal at 100% untilitzation

	AirMassGH_O2 = AirMassGH_O2 + DeltaSeconds*PlantO2GenRate;
	AirMassGH_CO2 = AirMassGH_CO2 - DeltaSeconds*PlantO2GenRate / .6363; //.6363 is ratio of CO2 mass to O2 mass



	AirMassRate_GH2Hab = AirMassRate_Hab2GH + 5;
	//Air leaving greenhouse to hab
	AirMassGH_O2 = AirMassGH_O2 - DeltaSeconds*AirMassRate_GH2Hab*AirComp_GH_O2;
	AirMassGH_CO2 = AirMassGH_CO2 - DeltaSeconds*AirMassRate_GH2Hab*AirComp_GH_CO2;
	AirMassGH_Other = AirMassGH_Other - DeltaSeconds*AirMassRate_GH2Hab*AirComp_GH_Other;


	Leak = 0;
	if (AirMassGH <= 2340)
	{
		Leak = 1;
	}

	AirGH.Empty();
	AirGH.Add(AirMassGH_O2);
	AirGH.Add(AirMassGH_CO2);
	AirGH.Add(AirMassGH_Other);
	AirGH.Add(AirComp_GH_O2);
	AirGH.Add(AirComp_GH_CO2);
	AirGH.Add(AirComp_GH_Other);
	AirGH.Add(AirMassGH);
	AirGH.Add(Leak);



	return AirGH;
}

