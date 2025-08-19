// SpeedPickup.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SpeedPickup.generated.h"

UCLASS()
class GADE7222_API ASpeedPickup : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ASpeedPickup();

    // The collision component for detecting overlaps
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USphereComponent* CollisionSphere;

    // The visual mesh for the pickup
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* Mesh;

    // The amount to increase the player's speed by
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed Pickup")
    float SpeedBoostAmount = 200.0f;

protected:
    // Overlap event handler
    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
