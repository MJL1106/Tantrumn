// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractInterface.h"
#include "GameFramework/Character.h"
#include "Sound/SoundCue.h"
#include "TantrumnCharacterBase.generated.h"

class AThrowableActor;

UENUM(BlueprintType)
enum class ECharacterThrowState : uint8
{
	None			UMETA(DisplayName = "None"),
	RequestingPull	UMETA(DisplayName = "RequestingPull"),
	Pulling			UMETA(DisplayName = "Pulling"),
	Attatched		UMETA(DisplayName = "Attatched"),
	Throwing		UMETA(DisplayName = "Throwing"),
};

UCLASS()
class TANTRUMN_API ATantrumnCharacterBase : public ACharacter, public IInteractInterface
{
	GENERATED_BODY()

public:
	ATantrumnCharacterBase();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Landed(const FHitResult& Hit) override;

	virtual void OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode = 0) override;
	virtual void FellOutOfWorld(const class UDamageType& dmgType) override;
	

	// Sets default values for this character's properties
	void RequestSprint();
	void RequestStopSprint();

	void RequestThrowObject();
	void RequestPullObjectStart();
	void RequestPullObjectStop();
	void ResetThrowableObject();

	void RequestUseObject();

	void OnThrowableAttached(AThrowableActor* InThrowableActor);

	bool CanThrowObject() const { return CharacterThrowState == ECharacterThrowState::Attatched; }

	UFUNCTION(BlueprintPure)
		bool IsPullingObject() const { return CharacterThrowState == ECharacterThrowState::RequestingPull || CharacterThrowState == ECharacterThrowState::Pulling; }

	UFUNCTION(BlueprintPure)
		bool IsThrowing() const { return CharacterThrowState == ECharacterThrowState::Throwing; }

	UFUNCTION(BlueprintPure)
		ECharacterThrowState GetCharacterThrowState() const { return CharacterThrowState; }

	UFUNCTION(BlueprintPure)
		bool IsStunned() const { return bIsStunned; }


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SphereCastPlayerView();
	void SphereCastActorTransform();
	void LineCastActorTransform();
	void ProcessTraceResult(const FHitResult& HitResult);

	bool PlayThrowMontage();
	void UnbindMontage();

	UFUNCTION(Server, Reliable)
		void ServerPullObject(AThrowableActor* InThrowableActor);

	UFUNCTION(Server, Reliable)
		void ServerRequestPullObject(bool bIsPulling);

	UFUNCTION(Server, Reliable)
		void ServerRequestThrowObject();

	UFUNCTION(NetMulticast, Reliable)
		void MulticastRequestThrowObject();

	UFUNCTION(Client, Reliable)
		void ClientThrowableAttached(AThrowableActor* InThrowableActor);

	UFUNCTION(Server, Reliable)
		void ServerBeginThrow();

	UFUNCTION(Server, Reliable)
		void ServerFinishThrow();

	UFUNCTION()
		void OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
		void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
		void OnNotifyBeginReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload);

	UFUNCTION()
		void OnNotifyEndReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload);

	UPROPERTY(EditAnywhere, Category = "Movement")
		float SprintSpeed = 1200.0f;

	UPROPERTY(EditAnywhere, Category = "Fall Impact")
		float MinImpactSpeed = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Fall Impact")
		float MaxImpactSpeed = 500.0f;

	UPROPERTY(EditAnywhere, Category = "Fall Impact")
		float MinStunTime = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Fall Impact")
		float MaxStunTime = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Fall Impact")
		USoundCue* HeavyLandSound = nullptr;

	void UpdateRescue(float DeltaTime);
	void StartRescue();
	void EndRescue();

	float StunTime = 0.0f;
	float StunBeginTimestamp = 0.0f;

	bool bIsStunned = false;
	bool bIsSprinting = false;

	float MaxWalkSpeed = 0.0f;

	void OnStunBegin(float StunRatio);
	void UpdateStun();
	void OnStunEnd();

	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_CharacterThrowState, Category = "Throw")
		ECharacterThrowState CharacterThrowState = ECharacterThrowState::None;

	UFUNCTION()
		void OnRep_CharacterThrowState(const ECharacterThrowState& OldCharacterThrowState);

	UPROPERTY(EditAnywhere, Category = "Throw", meta = (ClampMin = "0.0", Unnit = "ms"))
		float ThrowSpeed = 2000.0f;

	UPROPERTY(EditAnywhere, Category = "Animation")
		UAnimMontage* ThrowMontage = nullptr;

	FOnMontageBlendingOutStarted BlendingOutDelegate;
	FOnMontageEnded MontageEndedDelegate;

	FVector LastGroundPosition = FVector::ZeroVector; //Last Position on World when OnGround
	FVector FallOutOfWorldPosition = FVector::ZeroVector; //Position From Player when it Hits KillZ
	float CurrentRescueTime = 0.0f; // Used to set a timer from Moving Player back to Ground
	bool bIsPlayerBeingRescued = false;//Set to true in fell out of world
	UPROPERTY(EditAnywhere, Category = "KillZ")
	float TimeToRescuePlayer = 3.f;//Set time that takes to put Player back in Ground

private:

	UPROPERTY()
		AThrowableActor* ThrowableActor;

	void ApplyEffect_Implementation(EEffectType EffectType, bool bIsBuff) override;

	void EndEffect();

	bool bIsUnderEffect = false;
	bool bIsEffectBuff = false;

	float DefaultEffectCooldown = 5.0f;
	float EffectCooldown = 0.0f;

	EEffectType CurrentEffect = EEffectType::None;
};
