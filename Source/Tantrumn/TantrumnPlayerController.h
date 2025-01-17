// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Sound/SoundCue.h"
#include "TantrumnPlayerController.generated.h"

class ATantrumnGameModeBase;
class ATantrumnGameStateBase;
class UUserWidget;

/**
 * 
 */
UCLASS()
class TANTRUMN_API ATantrumnPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void SetupInputComponent() override;

	bool CanProcessRequest() const;

	void RequestJump();
	void RequestStopJump();
	


	void RequestCrouch();

	void RequestSprint();
	void RequestStopSprint();

	void RequestMoveForward(float AxisValue);
	void RequestMoveRight(float AxisValue);
	void RequestLookUp(float AxisValue);
	void RequestLookRight(float AxisValue);
	void RequestThrowObject(float AxisValue);

	void RequestPullorAimObjectStart();
	void RequestPullorAimObjectStop();

	UPROPERTY(EditAnywhere, Category = "HUD")
		TSubclassOf<class UUserWidget> HUDClass;

	UPROPERTY()
		UUserWidget* HUDWidget;

	UPROPERTY(EditAnywhere, Category = "Look")
		float BaseLookUpRate = 90.0f;

	UPROPERTY(EditAnywhere, Category = "Look")
		float BaseLookRightRate = 90.0f;

	/*UPROPERTY(EditAnywhere, Category = "Movement")
		float SprintSpeed = 1200.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
		float DefaultWalkSpeed = 0.0f;
		*/

	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundCue* JumpSound = nullptr;

	UPROPERTY()
		ATantrumnGameStateBase* TantrumnGameState;

	float LastAxis = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Input")
		float FlickThreshold = 0.75f;

public:

	virtual void BeginPlay() override;

	virtual void ReceivedPlayer() override;

	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;


	UFUNCTION(Client, Reliable)
	void ClientDisplayCountdown(float GameCountdownDuration);

	UFUNCTION(Client, Reliable)
		void ClientRestartGame();

	UFUNCTION(Client, Reliable)
		void ClientReachedEnd();

	UFUNCTION(Client, Reliable)
		void ServerRestartLevel();
};
