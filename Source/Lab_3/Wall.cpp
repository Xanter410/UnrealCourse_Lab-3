// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall.h"
#include "SnakeBase.h"

// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWall::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			FVector CurrentLocation = Snake->GetLocationSnakeHead();

			int NewLocationX = CurrentLocation.X;
			int NewLocationY = CurrentLocation.Y;


			if (CurrentLocation.X > FieldSizeX/2)
			{
				NewLocationX = -FieldSizeX / 2;
			}
			else if (CurrentLocation.X < -FieldSizeX / 2)
			{
				NewLocationX = FieldSizeX / 2;
			}

			if (CurrentLocation.Y > FieldSizeY / 2)
			{
				NewLocationY = -FieldSizeY / 2;
			}
			else if (CurrentLocation.Y < -FieldSizeY / 2)
			{
				NewLocationY = FieldSizeY / 2;
			}

			FVector NewLocation = FVector(NewLocationX, NewLocationY, 50);

			Snake->TeleportSnake(NewLocation);
		}
	}
}

