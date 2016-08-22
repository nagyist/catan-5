// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "HexagonTile.h"

// Sets default values
AHexagonTile::AHexagonTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    //Asset, Reference Obtained Via Right Click in Editor
    static ConstructorHelpers::FObjectFinder<UMaterial> StaticBrickMat(TEXT("Material'/Game/Textures/Hills.Hills'"));
    this->pBrickMat_ = StaticBrickMat.Object;
    static ConstructorHelpers::FObjectFinder<UMaterial> StaticOreMat(TEXT("Material'/Game/Textures/Mountains.Mountains'"));
    this->pOreMat_ = StaticOreMat.Object;
    static ConstructorHelpers::FObjectFinder<UMaterial> StaticWoolMat(TEXT("Material'/Game/Textures/Grasslands.Grasslands'"));
    this->pWoolMat_ = StaticWoolMat.Object;
    static ConstructorHelpers::FObjectFinder<UMaterial> StaticWheatMat(TEXT("Material'/Game/Textures/Plains.Plains'"));
    this->pWheatMat_ = StaticWheatMat.Object;
    static ConstructorHelpers::FObjectFinder<UMaterial> StaticWoodMat(TEXT("Material'/Game/Textures/Woods.Woods'"));
    this->pWoodMat_ = StaticWoodMat.Object;
    static ConstructorHelpers::FObjectFinder<UMaterial> StaticDesertMat(TEXT("Material'/Game/Textures/Desert.Desert'"));
    this->pDesertMat_ = StaticDesertMat.Object;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObj(TEXT("StaticMesh'/Game/Models/HexagonMesh.HexagonMesh'"));
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
    case Brick:
        dynamic_cast<UStaticMeshComponent*>(RootComponent)->SetMaterial(0, pBrickMat_);
        break;
    case Ore:
        dynamic_cast<UStaticMeshComponent*>(RootComponent)->SetMaterial(0, pOreMat_);
        break;
    case Wool:
        dynamic_cast<UStaticMeshComponent*>(RootComponent)->SetMaterial(0, pWoolMat_);
        break;
    case Wheat:
        dynamic_cast<UStaticMeshComponent*>(RootComponent)->SetMaterial(0, pWheatMat_);
        break;
    case Wood:
        dynamic_cast<UStaticMeshComponent*>(RootComponent)->SetMaterial(0, pWoodMat_);
        break;
    case Desert:
        dynamic_cast<UStaticMeshComponent*>(RootComponent)->SetMaterial(0, pDesertMat_);
        break;
    default:
        break;
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