// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AL_AirMathematicalMark_Final.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AERO402USB_API UAL_AirMathematicalMark_Final : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAL_AirMathematicalMark_Final();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UFUNCTION(BlueprintCallable)
		float AirlockAirFunc(float DeltaTime, float mdot_in, bool bIsOn, bool dIsOn);

	UFUNCTION(BlueprintCallable)
		float AirlockLossFunc(float moles_air_0_AL, float moles_air_fin_AL);  // Calculates the mass of air that we lost in Kgs

	UFUNCTION(BlueprintCallable)
		float UAL_AirMathmaticalMark_getma0AL(); // Returns the amount of moles at the beginning of the current press/depress

	UFUNCTION(BlueprintCallable)
		float UAL_AirMathmaticalMark_getmafAL(); // Returns the amout of moles remaining in the airlock during the press/depress

	UFUNCTION(BlueprintCallable)
		float UAL_AirMathmaticalMark_getmassLoss(); // Returns the amout of moles remaining in the airlock during the press/depress

	UFUNCTION(BlueprintCallable)
		float UAL_AirMathmaticalMark_openDoor(); // Returns the amout of moles remaining in the airlock during the press/depress

	UPROPERTY(BlueprintReadWrite)
		float AirOut_AL;

	UPROPERTY(BlueprintReadWrite)
		float nmoles_air_0_AL; //This is the number of moles of air in the airlock at Time t = 0

	UPROPERTY(BlueprintReadWrite)
		float nmoles_air_max_AL; //This is the maximum number of moles of air in the airlock

	UPROPERTY(BlueprintReadWrite)
		float nmoles_air_min_AL; //This is the min number of moles of air in the airlock

	UPROPERTY(BlueprintReadWrite)
		float nmoles_air_curr_AL; //This is the number of moles of air in the airlock currently

	UPROPERTY(BlueprintReadWrite)
		float nmoles_air_fin_AL; //This is the final air in the airlock

	UPROPERTY(BlueprintReadWrite)
		float AirIn_AL;

	UPROPERTY(BlueprintReadWrite)
		float PowerUsed_AL;

	UPROPERTY(BlueprintReadWrite)
		float PowerReceived_AL;

	UPROPERTY(BlueprintReadWrite)
		float ResidualAir_AL;

	UPROPERTY(BlueprintReadWrite)
		float Lights;

	UPROPERTY(BlueprintReadWrite)
		float Vol_Current_AL = 0;

	UPROPERTY(BlueprintReadWrite)
		float bIsLightOn;

	UPROPERTY(BlueprintReadWrite)
		float massOut; // This is the amount of mass that HAL receives from the airlock

	UPROPERTY(BlueprintReadWrite)
		float massLoss; // This is the amount of mass that is lost to the atmosphere

	UPROPERTY(BlueprintReadWrite)
		float mdot_avg = 0.00028; //This is an average number from our pump.

	UPROPERTY(BlueprintReadWrite)
		float second_accumulation = 0; //This is counting for a second

	UPROPERTY(BlueprintReadWrite)
		float mmAir = 0.028964; //This is the molar mass of Dry Air

	UPROPERTY(BlueprintReadWrite)
		float R = 8.314; //J/Mol*K < -- Gas Constant

	UPROPERTY(BlueprintReadWrite)
		float pMoon = 2 * (10 * pow(10, -12)) * 133.322; //Pressure of the Moon in Pascals

														 // Following will be configurable in Config files using the backend, temp for now
	UPROPERTY(BlueprintReadWrite)
		float Vol_Mudroom_AL = 4.31; //m^3 air for the air shower

	UPROPERTY(BlueprintReadWrite)
		float Temp_Hab = 298; // This is in Kelvin

	UPROPERTY(BlueprintReadWrite)
		float pHab = 101325; // This is in pascals

	UPROPERTY(BluePrintReadWrite)
		float isEmpty = true; // This is an indicator telling if the airlock is empty

	UPROPERTY(BlueprintReadWrite)
		float frontDoorOpen = false; // Not sure how to check this, but you gotta be nice about it.

	UPROPERTY(BlueprintReadWrite)
		float chamitoffSpeedMode = false; // This is the speed mode.

	UPROPERTY(BlueprintReadWrite)
		float efficency_AL = 0.9316; // This was calculated in a separate MATLAB script

	UPROPERTY(BlueprintReadWrite)
		float pCurr;
	
};
