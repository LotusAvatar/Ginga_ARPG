// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "AirDistortionActor.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONRPG_API AAirDistortionActor : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	AAirDistortionActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void PlayDistortion(FVector locationToSet);

protected:
	virtual void BeginPlay() override;

private:
	bool canPlay = false;
	void ScaleAnimation(float DeltaTime);

	UPROPERTY(EditDefaultsOnly)
		FVector finalScale = FVector(3);

	UPROPERTY(EditDefaultsOnly)
		float progressSpeed = 1.0f;

	float progress;
	FVector initialScale = FVector(0);
};
