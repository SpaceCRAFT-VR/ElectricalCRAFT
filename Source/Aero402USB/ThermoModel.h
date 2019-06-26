// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ThermoModel.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AERO402USB_API UThermoModel : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UThermoModel();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UFUNCTION(BlueprintCallable)
		TArray<float> Qt();

	// Heat Source 
	UPROPERTY(BlueprintReadWrite)
		int x = 1;
	UPROPERTY(BlueprintReadWrite)
		float T1 = 250.0;
	UPROPERTY(BlueprintReadWrite)
		float T2 = 298.0;
	UPROPERTY(BlueprintReadWrite)
		float k;
	UPROPERTY(BlueprintReadWrite)
		float pi = 3.14;

	UPROPERTY(BlueprintReadWrite)
		float Qhab = 32.5;
	UPROPERTY(BlueprintReadWrite)
		float Qgh = 87;
	UPROPERTY(BlueprintReadWrite)
		float Areg = 1241.1;
	UPROPERTY(BlueprintReadWrite)
		float Qreg;

	// Habitat Heat Exchanger 
	UPROPERTY(BlueprintReadWrite)
		float ma = 1.17;
	UPROPERTY(BlueprintReadWrite)
		float mb = 0.13;
	UPROPERTY(BlueprintReadWrite)
		float Ta = 2.2;
	UPROPERTY(BlueprintReadWrite)
		float Tb = 17;
	UPROPERTY(BlueprintReadWrite)
		float Cpa = 4628.2;
	UPROPERTY(BlueprintReadWrite)
		float Cpb = 4200;
	UPROPERTY(BlueprintReadWrite)
		float nphab = 50;
	UPROPERTY(BlueprintReadWrite)
		int nhab;
	UPROPERTY(BlueprintReadWrite)
		float wt = .002;
	UPROPERTY(BlueprintReadWrite)
		float lpipe = 1;
	UPROPERTY(BlueprintReadWrite)
		float dp0 = .025;
	UPROPERTY(BlueprintReadWrite)
		float row_al = 2710;
	UPROPERTY(BlueprintReadWrite)
		float Ahab;
	UPROPERTY(BlueprintReadWrite)
		float U = 100;
	UPROPERTY(BlueprintReadWrite)
		float maa;
	UPROPERTY(BlueprintReadWrite)
		float mbb;
	UPROPERTY(BlueprintReadWrite)
		float NTU;
	UPROPERTY(BlueprintReadWrite)
		float Cr;
	UPROPERTY(BlueprintReadWrite)
		float epsilon;
	UPROPERTY(BlueprintReadWrite)
		float Q_kw;
	UPROPERTY(BlueprintReadWrite)
		float Ta2;
	UPROPERTY(BlueprintReadWrite)
		float Tb2;
	UPROPERTY(BlueprintReadWrite)
		float Qhabhx;
	// GH Heat Exchanger 
	UPROPERTY(BlueprintReadWrite)
		float nghp = 100;
	UPROPERTY(BlueprintReadWrite)
		int ngh;
	UPROPERTY(BlueprintReadWrite)
		float lpipeGH = 2;
	UPROPERTY(BlueprintReadWrite)
		float Agh;
	UPROPERTY(BlueprintReadWrite)
		float NTUgh;
	UPROPERTY(BlueprintReadWrite)
		float Crgh;
	UPROPERTY(BlueprintReadWrite)
		float epsilongh;
	UPROPERTY(BlueprintReadWrite)
		float Q_kwgh;
	UPROPERTY(BlueprintReadWrite)
		float Ta2gh;
	UPROPERTY(BlueprintReadWrite)
		float Tb2gh;
	UPROPERTY(BlueprintReadWrite)
		float Qghhx;

	UPROPERTY(BlueprintReadWrite)
		float nu = 0.9;
	UPROPERTY(BlueprintReadWrite)
		float fin = 0.97;
	UPROPERTY(BlueprintReadWrite)
		float Ta2K;
	UPROPERTY(BlueprintReadWrite)
		float Sa = 0.2;
	UPROPERTY(BlueprintReadWrite)
		float alpha = 5;
	UPROPERTY(BlueprintReadWrite)
		float Gs = 1.418;
	UPROPERTY(BlueprintReadWrite)
		float sigma = 5.67e-11;
	UPROPERTY(BlueprintReadWrite)
		float Arad;
	UPROPERTY(BlueprintReadWrite)
		float Qr;
	UPROPERTY(BlueprintReadWrite)
		TArray<float> Output;
	
};
