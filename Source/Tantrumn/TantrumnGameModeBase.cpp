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

void ATantrumnGameModeBase::ReceivePlayer(APlayerController* PlayerController)
{
	AttemptStartGame();
}

void ATantrumnGameModeBase::AttemptStartGame()
{
	if (GetNumPlayers() == NumExpectedPlayers)
	{
		DisplayCountdown();
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATantrumnGameModeBase::StartGame, GameCountdownDuration, false);
	}
}

EGameState ATantrumnGameModeBase::GetCurrentGameState() const
{
	return CurrentGameState;
}

void ATantrumnGameModeBase::DisplayCountdown() 
{
	if (!GameWidgetClass) { return; }

	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		APlayerController* PlayerController = Iterator->Get();
		if (PlayerController && PlayerController->PlayerState && !MustSpectate(PlayerController))
		{
			if (UTantrumnGameWidget* GameWidget = CreateWidget<UTantrumnGameWidget>(PlayerController, GameWidgetClass))
			{
				//GameWidget->AddToViewport();
				GameWidget->AddToPlayerScreen();
				GameWidget->StartCountdown(GameCountdownDuration, this);
				GameWidgets.Add(PlayerController, GameWidget);
			}
		}
	}

	//PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	//GameWidget = CreateWidget<UTantrumnGameWidget>(PC, GameWidgetClass);
	//GameWidget->AddToViewport();
	//GameWidget->StartCountdown(GameCountdownDuration, this);
}


void ATantrumnGameModeBase::PlayerReachedEnd(APlayerController* PlayerController)
{
	CurrentGameState = EGameState::GameOver;
	UTantrumnGameWidget** GameWidget = GameWidgets.Find(PlayerController);
	if (GameWidget)
	{
		(*GameWidget)->LevelComplete();
		FInputModeUIOnly InputMode;
		PlayerController->SetInputMode(InputMode);
		PlayerController->SetShowMouseCursor(true);
	}
}

void ATantrumnGameModeBase::StartGame()
{
	CurrentGameState = EGameState::Playing;
	FInputModeGameOnly InputMode;
	PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PC->SetInputMode(InputMode);
	PC->SetShowMouseCursor(false);
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

