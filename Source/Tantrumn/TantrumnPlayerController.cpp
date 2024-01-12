// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumnPlayerController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void ATantrumnPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ATantrumnPlayerController::RequestJump);
		InputComponent->BindAction("Crouch", EInputEvent::IE_Pressed, this, &ATantrumnPlayerController::RequestCrouch);
		InputComponent->BindAction("Sprint", EInputEvent::IE_Pressed, this, &ATantrumnPlayerController::RequestSprint);
		InputComponent->BindAction("Sprint", EInputEvent::IE_Released, this, &ATantrumnPlayerController::RequestStopSprint);
		InputComponent->BindAxis("MoveForward", this, &ATantrumnPlayerController::RequestMoveForward);
		InputComponent->BindAxis("MoveRight", this, &ATantrumnPlayerController::RequestMoveRight);
		InputComponent->BindAxis("LookUp", this, &ATantrumnPlayerController::RequestLookUp);
		InputComponent->BindAxis("LookRight", this, &ATantrumnPlayerController::RequestLookRight);
	}
}

void ATantrumnPlayerController::RequestJump()
{
	if (GetCharacter())
	{
		GetCharacter()->Jump();
	}
}

void ATantrumnPlayerController::RequestCrouch()
{
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
	if (GetCharacter())
	{
		GetCharacter()->GetCharacterMovement()->MaxWalkSpeed *=2;
	}
}

void ATantrumnPlayerController::RequestStopSprint()
{
	if (GetCharacter())
	{
		GetCharacter()->GetCharacterMovement()->MaxWalkSpeed /= 2;
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
