// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AirlockMathModel_Main.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AERO402USB_API UAirlockMathModel_Main : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAirlockMathModel_Main();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		float AirlockAirFunc(float DeltaTime, float mdot_in, bool bIsOn);

	UPROPERTY(BlueprintReadWrite)
		float AirOut_AL;

	UPROPERTY(BlueprintReadWrite)
		float PowerUsed_AL;

	UPROPERTY(BlueprintReadWrite)
		float ResidualAir_AL;

	UPROPERTY(BlueprintReadWrite)
		float ElapsedTime;

	UPROPERTY(BlueprintReadWrite)
		float Vol_Current_AL = 0;

	UPROPERTY(BlueprintReadWrite)
		bool bIsLightOn;

	// Following will be configurable in Config files using backend, temp for now
	UPROPERTY(BlueprintReadWrite)
		float Vol_AirShower_AL = 100;
	
};
