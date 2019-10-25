// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "AirDistortionActor.h"
#include "Engine.h"
#include "Engine/World.h"

AAirDistortionActor::AAirDistortionActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AAirDistortionActor::BeginPlay()
{
	Super::BeginPlay();
	this->SetActorScale3D(initialScale);
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));
}

void AAirDistortionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ScaleAnimation(DeltaTime);
}

void AAirDistortionActor::PlayDistortion(FVector locationToSet)
{
	this->SetActorLocation(locationToSet);
	canPlay = true;
}

void AAirDistortionActor::ScaleAnimation(float DeltaTime)
{
	if (canPlay)
	{
		progress += DeltaTime * progressSpeed;

		if (progress < 1.0f)
		{
			FVector currentScale = FMath::Lerp(initialScale, finalScale, progress);
			this->SetActorScale3D(currentScale);
		}
		else
		{
			canPlay = false;
			progress = 0.0f;
			this->SetActorScale3D(initialScale);
		}
	}
}