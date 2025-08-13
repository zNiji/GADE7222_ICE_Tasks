#include "TrapObstacle.h"
#include "GameFramework/Character.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"

ATrapObstacle::ATrapObstacle()
{
    PrimaryActorTick.bCanEverTick = false;

    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    RootComponent = TriggerBox;
    TriggerBox->SetCollisionProfileName(TEXT("Trigger"));
    TriggerBox->SetBoxExtent(FVector(100.f, 100.f, 100.f));

    TrapMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TrapMesh"));
    TrapMesh->SetupAttachment(RootComponent);
    TrapMesh->SetCollisionProfileName(TEXT("NoCollision"));

    DamageAmount = 25.f;
    TriggerCooldown = 1.f;
    bCanTrigger = true;
}

void ATrapObstacle::BeginPlay()
{
    Super::BeginPlay();
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ATrapObstacle::OnOverlapBegin);
}

void ATrapObstacle::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (bCanTrigger && OtherActor)
    {
        ACharacter* Character = Cast<ACharacter>(OtherActor);
        if (Character)
        {
            DealDamage(OtherActor);
            bCanTrigger = false;
            GetWorld()->GetTimerManager().SetTimer(CooldownTimerHandle, [this]() { bCanTrigger = true; }, TriggerCooldown, false);
        }
    }
}

void ATrapObstacle::DealDamage(AActor* OtherActor)
{
    UGameplayStatics::ApplyDamage(OtherActor, DamageAmount, nullptr, this, UDamageType::StaticClass());
}

