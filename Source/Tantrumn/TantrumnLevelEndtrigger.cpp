// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumnLevelEndtrigger.h"
#include "TantrumnCharacterBase.h"
#include "TantrumnGameStateBase.h"

ATantrumnLevelEndtrigger::ATantrumnLevelEndtrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &ATantrumnLevelEndtrigger::OnOverlapBegin);
}

void ATantrumnLevelEndtrigger::BeginPlay()
{
	Super::BeginPlay();
	//GameModeRef = GetWorld()->GetAuthGameMode<ATantrumnGameModeBase>();
}

void ATantrumnLevelEndtrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (HasAuthority()) {

		if (ATantrumnGameStateBase* TantrumnGameState = GetWorld()->GetGameState<ATantrumnGameStateBase>())
		{
			ATantrumnCharacterBase* TantrumnCharacterBase = Cast<ATantrumnCharacterBase>(OtherActor);
			TantrumnGameState->OnPlayerReachedEnd(TantrumnCharacterBase);
		}
	}
}

