// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "TantrumnGameWidget.h"
#include "GameFramework/GameModeBase.h"
#include "TantrumnGameModeBase.generated.h"

// Enum to track the current state of the game 
UENUM(BlueprintType)
enum class EGameState : uint8
{
	None		UMETA(DisplayName = "None"),
	Waiting		UMETA(DisplayName = "Waiting"),
	Playing		UMETA(DisplayName = "Playing"),
	Paused		UMETA(DisplayName = "Paused"),
	GameOver	UMETA(DisplayName = "GameOver"),
};

/**
 * 
 */
UCLASS()
class TANTRUMN_API ATantrumnGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:


	ATantrumnGameModeBase();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
		EGameState GetCurrentGameState() const;

	void PlayerReachedEnd(APlayerController* PlayerController);
	virtual void Tick(float DeltaTime) override;

	void ReceivePlayer(APlayerController* PlayerController);

private:
	UPROPERTY(VisibleAnywhere, Category = "States")
		EGameState CurrentGameState = EGameState::None;

	UPROPERTY(EditAnywhere, Category = "Game Details")
		float GameCountdownDuration = 4.0f;

	UFUNCTION(BlueprintCallable, Category = "Game Details")
		void SetNumExpectedPlayers(uint8 InNumExpectedPlayers) { NumExpectedPlayers = InNumExpectedPlayers; }

	FTimerHandle TimerHandle;
	APlayerController* PC = nullptr;

	FVector OnGroundLastPosition = FVector::ZeroVector; 
	FVector FallingPosition = FVector::ZeroVector; 

	float CurrentTime = 0.0f; 
	UPROPERTY(EditAnywhere, Category = "Game Details")
		uint8 NumExpectedPlayers = 1u;

	bool bIsPlayerBeingRescued = false;

	UPROPERTY(EditAnywhere, Category = "KillZ")
		float TimeToRescuePlayer = 3.0f;

	UPROPERTY(EditAnywhere, Category = "KillZ")
		float KillZ = -500.0f;

	UPROPERTY()
		TMap<APlayerController*, UTantrumnGameWidget*> GameWidgets;
	UPROPERTY(EditAnywhere, Category = "Widget")
		TSubclassOf<UTantrumnGameWidget> GameWidgetClass;


	void StartGame();
	void AttemptStartGame();
	void DisplayCountdown();
	void DetectPlayerFallingOffWorld(float DeltaTime);
	void MovingPlayerToGround(APawn* Player, float DeltaTime);
	void RemovingInputFromPlayer(APawn* Player);
	void RestoreInputToPlayer(APawn* Player);
};
