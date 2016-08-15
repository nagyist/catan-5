// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "Road.h"


// Sets default values
ARoad::ARoad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    pEdge1 = nullptr;
    pEdge2 = nullptr;

}

// Called when the game starts or when spawned
void ARoad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoad::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ARoad::SetEdge(UStaticMeshComponent* edge)
{
    if (pEdge1 == nullptr)
    {
        pEdge1 = edge;
    }
    else if (pEdge2 == nullptr)
    {
        pEdge2 = edge;
    }
    else
    {
        throw;
    }
}