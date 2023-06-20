// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Wall.generated.h"


UCLASS()
class LAB_3_API AWall : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWall();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 FieldSizeX = 1200;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 FieldSizeY = 2600;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact(AActor* Interactor, bool bIsHead) override;
};
