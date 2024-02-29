// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumnPlayerController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TantrumnCharacterBase.h"
#include "TantrumnGameModeBase.h"

static TAutoConsoleVariable<bool> CVarDisplayLaunchInputDelta(
	TEXT("Tantrum.Character.Debug.DisplayLaunchInputDelta"),
	false,
	TEXT("Display Launch Input Delta"),
	ECVF_Default);




void ATantrumnPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//GameModeRef = Cast<ATantrumnGameModeBase>(GetWorld()->GetAuthGameMode());
}


void ATantrumnPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ATantrumnPlayerController::RequestJump);
		InputComponent->BindAction("Jump", EInputEvent::IE_Released, this, &ATantrumnPlayerController::RequestStopJump);

		InputComponent->BindAction("Crouch", EInputEvent::IE_Pressed, this, &ATantrumnPlayerController::RequestCrouch);
		InputComponent->BindAction("Sprint", EInputEvent::IE_Pressed, this, &ATantrumnPlayerController::RequestSprint);
		InputComponent->BindAction("Sprint", EInputEvent::IE_Released, this, &ATantrumnPlayerController::RequestStopSprint);

		InputComponent->BindAxis("MoveForward", this, &ATantrumnPlayerController::RequestMoveForward);
		InputComponent->BindAxis("MoveRight", this, &ATantrumnPlayerController::RequestMoveRight);
		InputComponent->BindAxis("LookUp", this, &ATantrumnPlayerController::RequestLookUp);
		InputComponent->BindAxis("LookRight", this, &ATantrumnPlayerController::RequestLookRight);
		//InputComponent->BindAction("ThrowObject", EInputEvent::IE_Pressed, this, &ATantrumnPlayerController::RequestThrowObject);

		InputComponent->BindAction(TEXT("PullObject"),EInputEvent::IE_Pressed,this,&ATantrumnPlayerController::RequestPullObjectStart);
		InputComponent->BindAction(TEXT("PullObject"),EInputEvent::IE_Released,this,&ATantrumnPlayerController::RequestPullObjectStop);
		InputComponent->BindAxis(TEXT("ThrowObject"), this, &ATantrumnPlayerController::RequestThrowObject);
	}
}

void ATantrumnPlayerController::RequestJump()
{
	if (!GameModeRef || GameModeRef->GetCurrentGameState() != EGameState::Playing) { return; }
	if (GetCharacter())
	{
		GetCharacter()->Jump();
	}
}

void ATantrumnPlayerController::RequestStopJump()
{
	if (GetCharacter())
	{
		GetCharacter()->StopJumping();
	}
}

void ATantrumnPlayerController::ReceivedPlayer()
{
	Super::ReceivedPlayer();
	GameModeRef = Cast<ATantrumnGameModeBase>(GetWorld()->GetAuthGameMode());
	if (ensureMsgf(GameModeRef, TEXT("ATantrumnPlayerController::ReceivedPLayer missing GameMode Reference")))
	{
		GameModeRef->ReceivePlayer(this);
	}

	if (HUDClass)
	{
		HUDWidget = CreateWidget(this, HUDClass);
		if (HUDWidget)
		{
			HUDWidget->AddToPlayerScreen();
		}
	}
}

void ATantrumnPlayerController::RequestCrouch()
{

	if (!GetCharacter()->GetCharacterMovement()->IsMovingOnGround()) {return;}
	if (GetCharacter())
	{
		if (GetCharacter()->GetCharacterMovement()->IsCrouching())
		{
			GetCharacter()->UnCrouch();
		}
		else
		{
			GetCharacter()->Crouch();
		}
	}
}

void ATantrumnPlayerController::RequestSprint()
{
	
	if (ATantrumnCharacterBase* TantrumnCharacterBase = Cast<ATantrumnCharacterBase>(GetCharacter()))
	{
		TantrumnCharacterBase->RequestSprint();
	}
}

void ATantrumnPlayerController::RequestStopSprint()
{
	if (ATantrumnCharacterBase* TantrumnCharacterBase = Cast<ATantrumnCharacterBase>(GetCharacter()))
	{
		TantrumnCharacterBase->RequestStopSprint();
	}
}

void ATantrumnPlayerController::RequestMoveForward(float AxisValue)
{
	
	if (AxisValue != 0.f)
	{
		FRotator const ControlSpaceRot = GetControlRotation();
		GetPawn()->AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), AxisValue);
	}
}

void ATantrumnPlayerController::RequestMoveRight(float AxisValue)
{
	
	if (AxisValue != 0.f)
	{
		FRotator const ControlSpaceRot = GetControlRotation();
		GetPawn()->AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), AxisValue);
	}
}

void ATantrumnPlayerController::RequestLookUp(float AxisValue) 
{
	AddPitchInput(AxisValue * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ATantrumnPlayerController::RequestLookRight(float AxisValue)
{
	AddYawInput(AxisValue * BaseLookRightRate * GetWorld()->GetDeltaSeconds());
}

void ATantrumnPlayerController::RequestThrowObject(float AxisValue)
{
	if (ATantrumnCharacterBase* TantrumnCharacterBase = Cast<ATantrumnCharacterBase>(GetCharacter()))
	{

		if (TantrumnCharacterBase->CanThrowObject())
		{
			float currentDelta = AxisValue - LastAxis;

			if (CVarDisplayLaunchInputDelta->GetBool())
			{
				if (fabs(currentDelta) > 0.0f)
				{
					UE_LOG(LogTemp, Warning, TEXT("Axis: %f LastAxis: %f currentDelta: %f"), AxisValue, LastAxis);
				}
			}
			LastAxis = AxisValue;
			const bool IsFlick = fabs(currentDelta) > FlickThreshold;
			if (IsFlick)
			{
				if (AxisValue > 0)
				{
					TantrumnCharacterBase->RequestThrowObject();
				}
				else
				{
					TantrumnCharacterBase->RequestUseObject();
				}
			}
		}
		else
		{
			LastAxis = 0.0f;
		}
	}
}

void ATantrumnPlayerController::RequestPullObjectStart()
{
	if (ATantrumnCharacterBase* TantrumnCharacterBase = Cast<ATantrumnCharacterBase>(GetCharacter()))
	{
		TantrumnCharacterBase->RequestPullObjectStart();
	}
}

void ATantrumnPlayerController::RequestPullObjectStop()
{
	if (ATantrumnCharacterBase* TantrumnCharacterBase = Cast<ATantrumnCharacterBase>(GetCharacter()))
	{
		TantrumnCharacterBase->RequestPullObjectStop();
	}
}
