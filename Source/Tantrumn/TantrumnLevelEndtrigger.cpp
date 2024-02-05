// Fill out your copyright notice in the Description page of Project Settings.


#include "TantrumnLevelEndtrigger.h"
#include "TantrumnCharacterBase.h"
#include "TantrumnGameModeBase.h"

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
	UE_LOG(LogTemp, Warning, TEXT("Overlap Event Triggered"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Event Triggered"));
	}

	if (OtherActor == Cast<ATantrumnCharacterBase>(OtherActor))
	{
		GameModeRef->PlayerReachedEnd();
	}
}

