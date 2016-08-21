// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "Road.h"


// Sets default values
ARoad::ARoad()
{    
    // setup mesh
    static ConstructorHelpers::FObjectFinder<UStaticMesh> RoadMesh(TEXT("StaticMesh'/Game/Models/road.road'"));
    mesh_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Road"));
    mesh_->SetStaticMesh(RoadMesh.Object);
    RootComponent = mesh_;

    // Setup click handler
    FScriptDelegate clickedDelegate;
    clickedDelegate.BindUFunction(this, TEXT("OnRoadClicked"));
    FActorOnClickedSignature onClicked;
    onClicked.Add(clickedDelegate);
    this->OnClicked = onClicked;
}

// Called when the game starts or when spawned
void ARoad::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARoad::OnRoadClicked()
{
    GetWorld()->GetFirstPlayerController()->ClientMessage(TEXT("Clicked a road!"));
}