// Copyright Epic Games, Inc. All Rights Reserved.


#include "TantrumnGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"


ATantrumnGameModeBase::ATantrumnGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATantrumnGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	CurrentGameState = EGameState::Waiting;
	DisplayCountdown();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATantrumnGameModeBase::StartGame, GameCountdownDuration, false);
}

void ATantrumnGameModeBase::Tick(float DeltaTime)
{
	DetectPlayerFallingOffWorld(DeltaTime);
}

EGameState ATantrumnGameModeBase::GetCurrentGameState() const
{
	return CurrentGameState;
}

void ATantrumnGameModeBase::DisplayCountdown() 
{
	if (!GameWidgetClass) { return; }

	PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	GameWidget = CreateWidget<UTantrumnGameWidget>(PC, GameWidgetClass);
	GameWidget->AddToViewport();
	GameWidget->StartCountdown(GameCountdownDuration, this);
}
void ATantrumnGameModeBase::PlayerReachedEnd()
{
	CurrentGameState = EGameState::GameOver;

	GameWidget->LevelComplete();
	FInputModeUIOnly InputMode;
	PC->SetInputMode(InputMode);
	PC->SetShowMouseCursor(true);
}

void ATantrumnGameModeBase::StartGame()
{
	CurrentGameState = EGameState::Playing;


}

void ATantrumnGameModeBase::DetectPlayerFallingOffWorld(float DeltaTime)
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (PlayerPawn->GetMovementComponent()->IsMovingOnGround())
	{
		OnGroundLastPosition = PlayerPawn->GetActorLocation();

	}

	if (PlayerPawn->GetActorLocation().Z <= KillZ)
	{
		FallingPosition = PlayerPawn->GetActorLocation();
		RemovingInputFromPlayer(PlayerPawn);//Also removes collision
		bIsPlayerBeingRescued = true;

	}
	if (bIsPlayerBeingRescued)
	{
		MovingPlayerToGround(PlayerPawn, DeltaTime);
	}

}

void ATantrumnGameModeBase::MovingPlayerToGround(APawn* Player, float DeltaTime)
{
	CurrentTime += DeltaTime;
	float Alpha = FMath::Clamp(CurrentTime / TimeToRescuePlayer, 0.0f, 1.0f);
	FVector NewPlayerLocation = FMath::Lerp(FallingPosition, OnGroundLastPosition, Alpha);
	Player->SetActorLocation(NewPlayerLocation);

	if (NewPlayerLocation.Equals(OnGroundLastPosition))
	{
		CurrentTime = 0.0f;
		RestoreInputToPlayer(Player);//Also restores collision
		bIsPlayerBeingRescued = false;
	}

}

void ATantrumnGameModeBase::RemovingInputFromPlayer(APawn* Player)
{
	Player->GetMovementComponent()->Deactivate();
	Player->SetActorEnableCollision(false);
}
void ATantrumnGameModeBase::RestoreInputToPlayer(APawn* Player)

{
	Player->GetMovementComponent()->Activate();
	Player->SetActorEnableCollision(true);
}

