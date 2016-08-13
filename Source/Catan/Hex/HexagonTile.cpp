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

    UStaticMeshComponent* mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HexMesh"));
    mesh->SetStaticMesh(StaticMeshObj.Object);

    mesh->bOwnerNoSee = false;
    mesh->bCastDynamicShadow = true;
    mesh->CastShadow = true;
    mesh->BodyInstance.SetObjectType(ECC_WorldDynamic);
    mesh->BodyInstance.SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    mesh->BodyInstance.SetResponseToAllChannels(ECR_Ignore);
    mesh->BodyInstance.SetResponseToChannel(ECC_WorldStatic, ECR_Block);
    mesh->BodyInstance.SetResponseToChannel(ECC_WorldDynamic, ECR_Block);
    mesh->BodyInstance.SetResponseToChannel(ECC_Pawn, ECR_Block);
    mesh->SetHiddenInGame(false);

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

void AHexagonTile::SetCoordinates(int q, int r, int s)
{
    this->cubeCoords.X = q;
    this->cubeCoords.Y = r;
    this->cubeCoords.Z = s;
}

FVector AHexagonTile::GetCoordinates() const
{
    return this->cubeCoords;
}

const float AHexagonTile::Border = 0;
// 10px border
const float AHexagonTile::Size = 100 + 10;