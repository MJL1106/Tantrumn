// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TantrumnPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANTRUMN_API ATantrumnPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	void SetupInputComponent() override;

	void RequestJump();
	void RequestCrouch();
	void RequestSprint();
	void RequestStopSprint();
	void RequestMoveForward(float AxisValue);
	void RequestMoveRight(float AxisValue);
	void RequestLookUp(float AxisValue);
	void RequestLookRight(float AxisValue);

public:
	UPROPERTY(EditAnywhere, Category = "Look")
		float BaseLookUpRate = 90.0f;

	UPROPERTY(EditAnywhere, Category = "Look")
		float BaseLookRightRate = 90.0f;
};
