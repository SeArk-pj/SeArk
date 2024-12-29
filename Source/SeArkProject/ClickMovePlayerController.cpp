// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickMovePlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"


AClickMovePlayerController::AClickMovePlayerController()
{
	bShowMouseCursor = true; //마우스 보이게 하기
}

void AClickMovePlayerController::InputRightMouseButtonPressed()
{
	bClickRightMouse = true;

}

void AClickMovePlayerController::InputRightMouseButtonReleased()
{
	bClickRightMouse = false;

}

void AClickMovePlayerController::onSkillInputHandler()
{
	pressKeyboardButton = false;
}

void AClickMovePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("RightClick", IE_Pressed, this, &AClickMovePlayerController::InputRightMouseButtonPressed);
	InputComponent->BindAction("RightClick", IE_Released, this, &AClickMovePlayerController::InputRightMouseButtonReleased);
	InputComponent->BindAction("E", IE_Released, this, &AClickMovePlayerController::onSkillInputHandler);
}
void AClickMovePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	if (bClickRightMouse && pressKeyboardButton) {
		MoveToMouseCursor();
	}

}

void AClickMovePlayerController::SetNewDestination(const FVector Destination)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn) {
		float const Distance = FVector::Dist(Destination, MyPawn->GetNavAgentLocation());
		if (Distance > 120.0f) {
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, Destination);
		}
	}
}

void AClickMovePlayerController::MoveToMouseCursor()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	if (Hit.bBlockingHit) {
		SetNewDestination(Hit.ImpactPoint);
	}

}
