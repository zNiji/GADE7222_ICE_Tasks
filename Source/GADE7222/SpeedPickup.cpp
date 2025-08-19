// SpeedPickup.cpp

#include "SpeedPickup.h"

// Sets default values
ASpeedPickup::ASpeedPickup()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    // Create and set up the collision sphere
    CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
    RootComponent = CollisionSphere;
    CollisionSphere->SetSphereRadius(50.0f); // Adjust radius as needed
    CollisionSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

    // Create and set up the mesh
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(RootComponent);
    Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision); // Mesh is visual only

    // Bind the overlap event
    CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ASpeedPickup::OnOverlapBegin);
}

// Called when the collision sphere overlaps with another actor
void ASpeedPickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor != this)
    {
        // Attempt to cast the other actor to ACharacter (assuming the player is a character)
        ACharacter* PlayerCharacter = Cast<ACharacter>(OtherActor);
        if (PlayerCharacter)
        {
            // Optional: Check if this is the player-controlled character
            AController* Controller = PlayerCharacter->GetController();
            if (Controller && Controller->IsPlayerController())
            {
                // Get the character's movement component and increase max walk speed
                UCharacterMovementComponent* MovementComponent = PlayerCharacter->GetCharacterMovement();
                if (MovementComponent)
                {
                    MovementComponent->MaxWalkSpeed += SpeedBoostAmount;

                    // Destroy the pickup after it's collected
                    Destroy();
                }
            }
        }
    }
}

