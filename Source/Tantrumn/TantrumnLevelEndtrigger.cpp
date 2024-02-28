// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumnLevelEndtrigger.h"
#include "TantrumnCharacterBase.h"
#include "TantrumnGameModeBase.h"
#include "TantrumnPlayerController.h"

ATantrumnLevelEndtrigger::ATantrumnLevelEndtrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &ATantrumnLevelEndtrigger::OnOverlapBegin);
}

void ATantrumnLevelEndtrigger::BeginPlay()
{
	Super::BeginPlay();
	GameModeRef = GetWorld()->GetAuthGameMode<ATantrumnGameModeBase>();
}

void ATantrumnLevelEndtrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (ATantrumnCharacterBase* TantrumnCharacterBase = Cast<ATantrumnCharacterBase>(OtherActor))
	{
		APlayerController* PlayerController = TantrumnCharacterBase->GetController<APlayerController>();
		GameModeRef->PlayerReachedEnd(PlayerController);
	}
}

