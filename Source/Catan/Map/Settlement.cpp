// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "Settlement.h"


// Sets default values
ASettlement::ASettlement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObj(TEXT("StaticMesh'/Game/Models/settlement.settlement'"));
    UStaticMeshComponent* mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Settlement"));
    mesh->SetStaticMesh(StaticMeshObj.Object);
    RootComponent = mesh;
}

// Called when the game starts or when spawned
void ASettlement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASettlement::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

