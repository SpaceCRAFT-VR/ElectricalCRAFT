// Fill out your copyright notice in the Description page of Project Settings.

#include "ThermoModel.h"


// Sets default values for this component's properties
UThermoModel::UThermoModel()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UThermoModel::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UThermoModel::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<float> UThermoModel::Qt()
{
	// Overall Heat Source 

	k = -(9 * pow(10, -6))*pow(T1, 2.0) + 0.0039*T1 + 0.0173;
	Qreg = (k*Areg / x)*(T1 - T2) / 1000;
	float Qtotal = Qhab + Qgh + Qreg;

	// Habitat Heat Exchanger 
	Ahab = nphab * pi*dp0*lpipe;
	maa = ma * Cpa;
	mbb = mb * Cpb;
	NTU = U * Ahab / mbb;
	Cr = mbb / maa;
	epsilon = (1 - exp(-NTU * (1 - Cr))) / (1 - Cr * exp(-NTU * (1 - Cr)));
	Q_kw = epsilon * mbb*(Tb - Ta) / 1000;
	Ta2 = Q_kw / maa + Ta;
	Tb2 = Tb - Q_kw / mbb;

	float rhab = 0.25;
	float load = rhab * Qtotal;
	nhab = round(load / Q_kw);

	if (nhab*Q_kw < load) {
		nhab = nhab + 1;
	}
	else {
		nhab = nhab;
	}





	Qhabhx = nhab * Q_kw;

	// Greeenhouse Heat Exchanger 
	Agh = nghp*pi*dp0*lpipeGH;
	NTUgh = U*Agh / mbb;
	epsilongh = (1 - exp(-NTUgh*(1 - Cr))) / (1 - Cr*exp(-NTUgh*(1 - Cr)));
	Q_kwgh = epsilongh*mbb*(Tb - Ta) / 1000;
	Ta2gh = Q_kwgh / maa + Ta;
	Tb2gh = Tb - Q_kwgh / mbb;

	float rgh = 0.75;
	float loadgh = rgh * Qtotal;
	ngh = loadgh / Q_kwgh;

	if (ngh*Q_kwgh< loadgh) {
		ngh = ngh + 1;
	}
	else {
		ngh = ngh;
	}



	Qghhx = Q_kwgh * ngh;


	// Radiator
	Ta2K = Ta2 + 273.15;
	Arad = (Qtotal + Gs * cos(alpha)*Sa) / (nu*fin*sigma*pow(Ta2K, 4));
	Qr = Qhabhx + Qghhx;


	Output.Add(load);
	Output.Add(nhab);
	Output.Add(Qhabhx);
	Output.Add(ngh);
	Output.Add(loadgh);
	Output.Add(Qghhx);
	Output.Add(Qtotal);
	Output.Add(Qr);



	return Output;
}

