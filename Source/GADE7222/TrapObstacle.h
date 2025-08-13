#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "TrapObstacle.generated.h"

UCLASS()
class GADE7222_API ATrapObstacle : public AActor
{
    GENERATED_BODY()

public:
    ATrapObstacle();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    UBoxComponent* TriggerBox;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* TrapMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trap", meta = (AllowPrivateAccess = "true"))
    float DamageAmount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trap", meta = (AllowPrivateAccess = "true"))
    float TriggerCooldown;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    void DealDamage(AActor* OtherActor);

    FTimerHandle CooldownTimerHandle;
    bool bCanTrigger;
};
