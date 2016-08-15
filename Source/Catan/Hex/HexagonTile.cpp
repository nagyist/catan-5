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
    static ConstructorHelpers::FObjectFinder<UStaticMesh> EdgeMesh(TEXT("StaticMesh'/Game/Models/hexedge.hexedge'"));

    UStaticMeshComponent* mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HexMesh"));
    mesh->SetStaticMesh(StaticMeshObj.Object);
    RootComponent = mesh;

    this->edges_[0] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Edge1"));
    this->edges_[0]->SetStaticMesh(EdgeMesh.Object);
    //this->edges_[0]->AddLocalRotation(FRotator(0, 60, 0));
    this->edges_[0]->SetupAttachment(RootComponent);

    this->edges_[1] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Edge2"));
    this->edges_[1]->SetStaticMesh(EdgeMesh.Object);
    this->edges_[1]->AddLocalRotation(FRotator(0, 60, 0));
    this->edges_[1]->SetupAttachment(RootComponent);

    this->edges_[2] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Edge3"));
    this->edges_[2]->SetStaticMesh(EdgeMesh.Object);
    this->edges_[2]->AddLocalRotation(FRotator(0, 120, 0));
    this->edges_[2]->SetupAttachment(RootComponent);

    this->edges_[3] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Edge4"));
    this->edges_[3]->SetStaticMesh(EdgeMesh.Object);
    this->edges_[3]->AddLocalRotation(FRotator(0, 180, 0));
    this->edges_[3]->SetupAttachment(RootComponent);

    this->edges_[4] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Edge5"));
    this->edges_[4]->SetStaticMesh(EdgeMesh.Object);
    this->edges_[4]->AddLocalRotation(FRotator(0, 240, 0));
    this->edges_[4]->SetupAttachment(RootComponent);

    this->edges_[5] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Edge6"));
    this->edges_[5]->SetStaticMesh(EdgeMesh.Object);
    this->edges_[5]->AddLocalRotation(FRotator(0, 300, 0));
    this->edges_[5]->SetupAttachment(RootComponent);
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