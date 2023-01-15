// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/UnlockingKey.h"
#include "Components/StaticMeshComponent.h"
#include "StealthGame/StealthGameCharacter.h"

// Sets default values
AUnlockingKey::AUnlockingKey()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	UnlockingKeyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UnlockingKey Mesh"));
	RootComponent = UnlockingKeyMesh;

}

// Called when the game starts or when spawned
void AUnlockingKey::BeginPlay()
{
	Super::BeginPlay();
	
}

void AUnlockingKey::Interact(AStealthGameCharacter* Character)
{
	if (Character)
	{
		Character->AddItemToInventory(this);
		UnlockingKeyMesh->SetHiddenInGame(true);
		UnlockingKeyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

//// Called every frame
//void AUnlockingKey::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

