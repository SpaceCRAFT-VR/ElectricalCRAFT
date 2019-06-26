// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ACTOR_ECLSS_GH.generated.h"

UCLASS()
class AERO402USB_API AACTOR_ECLSS_GH : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AACTOR_ECLSS_GH();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		TArray<float> GHAirModel_FuncV2(float DeltaSeconds, float AirMassRate_Hab2GH, float AirComp_Hab2GH_O2, float AirComp_Hab2GH_CO2, float AirComp_Hab2GH_Other, float AirMassGH_O2, float AirMassGH_CO2, float AirMassGH_Other);

	UPROPERTY(BlueprintReadWrite)
		TArray<float> AirGH;

	UPROPERTY(BlueprintReadWrite)
		float AirComp_GH_O2;

	UPROPERTY(BlueprintReadWrite)
		float AirComp_GH_CO2;

	UPROPERTY(BlueprintReadWrite)
		float AirComp_GH_Other;

	UPROPERTY(BlueprintReadWrite)
		float AirMassGH;

	UPROPERTY(BlueprintReadWrite)
		float AirMassGH_O2;

	UPROPERTY(BlueprintReadWrite)
		float AirMassGH_CO2;

	UPROPERTY(BlueprintReadWrite)
		float AirMassGH_Other;

	float PlantO2GenRate;
	float Leak;
	float AirMassRate_GH2Hab;

	
};
