// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickMovePlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"


AClickMovePlayerController::AClickMovePlayerController()
{
	bShowMouseCursor = true; //마우스 보이게 하기

	// QWERASDFV 키 배열 초기화
	SkillKeys = { "Q", "W", "E", "R", "A", "S", "D", "F", "V" };

	// 초기값 설정 (스킬 상태)
	FMemory::Memset(btSkill, false, sizeof(btSkill));

}

void AClickMovePlayerController::InputRightMouseButtonPressed()
{
	bClickRightMouse = true;

}

void AClickMovePlayerController::InputRightMouseButtonReleased()
{
	bClickRightMouse = false;

}

void AClickMovePlayerController::OnSkillPressed(int32 SkillID)
{
	btSkill[SkillID] = true;
	UE_LOG(LogTemp, Warning, TEXT("Skill %d pressed!"), SkillID);
}

void AClickMovePlayerController::OnSkillReleased(int32 SkillID)
{
	btSkill[SkillID] = false;
	UE_LOG(LogTemp, Warning, TEXT("Skill %d released!"), SkillID);
}


void AClickMovePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("RightClick", IE_Pressed, this, &AClickMovePlayerController::InputRightMouseButtonPressed);
	InputComponent->BindAction("RightClick", IE_Released, this, &AClickMovePlayerController::InputRightMouseButtonReleased);

	for (int32 i = 0; i < SkillKeys.Num(); ++i)
	{
		// 키가 눌렸을 때 처리
		FInputActionBinding PressedBinding(SkillKeys[i], IE_Pressed);
		PressedBinding.ActionDelegate.GetDelegateForManualSet().BindLambda([this, i]() {
			OnSkillPressed(i);
			});
		InputComponent->AddActionBinding(PressedBinding);

		// 키가 떼어졌을 때 처리
		FInputActionBinding ReleasedBinding(SkillKeys[i], IE_Released);
		ReleasedBinding.ActionDelegate.GetDelegateForManualSet().BindLambda([this, i]() {
			OnSkillReleased(i);
			});
		InputComponent->AddActionBinding(ReleasedBinding);
	}
}

void AClickMovePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	if (bClickRightMouse) {
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
