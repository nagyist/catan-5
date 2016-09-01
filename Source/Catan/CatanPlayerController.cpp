// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "hex/HexagonTile.h"
#include "CatanPlayerController.h"

void ACatanPlayerController::BeginPlay()
{
    Super::BeginPlay();

    bShowMouseCursor = true;
    bEnableClickEvents = true;
}

void ACatanPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    
    InputComponent->BindAction(TEXT("Select"),
        IE_Pressed,
        this,
        &ACatanPlayerController::SelectPressed);

    InputComponent->BindAction(TEXT("Select"),
        IE_Released,
        this,
        &ACatanPlayerController::SelectReleased);
}

void ACatanPlayerController::SelectPressed()
{
    FVector cursorlocation;
    FVector cursordirection;
    DeprojectMousePositionToWorld(cursorlocation, cursordirection);
    FVector traceend = cursorlocation + cursordirection * 10000;

    FHitResult hitresult;
    if (GetWorld()->LineTraceSingleByChannel(hitresult, cursorlocation, traceend, ECC_Camera))
    {
        UE_LOG(LogTemp, Display, TEXT("Selected %s %s"), *hitresult.Actor->GetName(), *hitresult.ImpactPoint.ToString());
        auto mappiece = dynamic_cast<AHexagonTile*>(hitresult.Actor.Get());
        if (mappiece != nullptr)
        {
            mappiece->SetResourceType(Desert);
        }
    }
}

void ACatanPlayerController::SelectReleased()
{

}
