// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "HexagonTile.h"

// Sets default values
AHexagonTile::AHexagonTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    //Asset, Reference Obtained Via Right Click in Editor
    static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObj(TEXT("StaticMesh'/Game/Models/HexagonMesh.HexagonMesh'"));
    static ConstructorHelpers::FObjectFinder<UMaterial> StaticBrickMat(TEXT("Material'/Game/Textures/Hills.Hills'"));
    this->pBrickMat_ = StaticBrickMat.Object;

    UStaticMeshComponent* mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HexMesh"));
    mesh->SetStaticMesh(StaticMeshObj.Object);
    RootComponent = mesh;
}

// Called when the game starts or when spawned
void AHexagonTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHexagonTile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AHexagonTile::SetResourceType(ResourceType type)
{
    switch (type)
    {
    case ResourceType::Brick:
        {
        dynamic_cast<UStaticMeshComponent*>(RootComponent)->SetMaterial(0, pBrickMat_);
        }
    }
}

void AHexagonTile::SetCoordinates(const FVector& cubecoordinates)
{
    cubeCoordinates_ = cubecoordinates;
}

FVector AHexagonTile::GetCoordinates() const
{
    return this->cubeCoordinates_;
}

const float AHexagonTile::Border = 0;
// 10px border
const float AHexagonTile::Size = 100 + 10;