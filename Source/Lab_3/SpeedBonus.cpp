// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedBonus.h"
#include "SnakeBase.h"

// Sets default values
ASpeedBonus::ASpeedBonus()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpeedBonus::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpeedBonus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpeedBonus::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			Snake->SetActorTickInterval(Snake-> MovementSpeed -= Power);

			int RandomX = FMath::RandRange(-600, 600);
			RandomX = (RandomX / 100) * 100;
			int RandomY = FMath::RandRange(-1300, 1300);
			RandomY = (RandomX / 100) * 100;

			this->SetActorLocation(FVector(RandomX, RandomY, 50));
		}
	}
}

