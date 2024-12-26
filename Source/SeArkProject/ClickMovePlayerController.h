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
	AClickMovePlayerController(); //������
protected:
	bool bClickRightMouse;

	void InputRightMouseButtonPressed();

	void InputRightMouseButtonReleased();

	TArray<FName> SkillKeys;

	void OnSkillPressed(int32 SkillID);
	void OnSkillReleased(int32 SkillID);


	void SetNewDestination(const FVector Destination);

	void MoveToMouseCursor();

	virtual void SetupInputComponent() override;

	virtual void PlayerTick(float DeltaTime) override;
private:
	bool btSkill[9];


};
