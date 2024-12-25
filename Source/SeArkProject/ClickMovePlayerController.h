// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ClickMovePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SEARKPROJECT_API AClickMovePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AClickMovePlayerController(); //»ý¼ºÀÚ
protected:
	bool bClickRightMouse;

	void InputRightMouseButtonPressed();

	void InputRightMouseButtonReleased();

	
	void SetNewDestination(const FVector Destination);

	void MoveToMouseCursor();

	virtual void SetupInputComponent() override;
	
	virtual void PlayerTick(float DeltaTime) override;

	
};
