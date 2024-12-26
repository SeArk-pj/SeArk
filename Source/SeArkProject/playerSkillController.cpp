// Fill out your copyright notice in the Description page of Project Settings.


#include "playerSkillController.h"

AplayerSkillController::AplayerSkillController()
{
	OnSkillPressed(0);
}

void AplayerSkillController::OnQPressed()
{
	OnSkillPressed(1);
}

void AplayerSkillController::OnWPressed()
{
	OnSkillPressed(2);
}

void AplayerSkillController::OnEPressed()
{
	OnSkillPressed(3);
}

void AplayerSkillController::OnRPressed()
{
	OnSkillPressed(4);
}

void AplayerSkillController::OnAPressed()
{
	OnSkillPressed(5);
}

void AplayerSkillController::OnSPressed()
{
	OnSkillPressed(6);
}

void AplayerSkillController::OnDPressed()
{
	OnSkillPressed(7);
}

void AplayerSkillController::OnFPressed()
{
	OnSkillPressed(8);
}

void AplayerSkillController::OnVPressed()
{
	OnSkillPressed(9);
}

void AplayerSkillController::OnQReleased()
{
}

void AplayerSkillController::OnWReleased()
{
}

void AplayerSkillController::OnEReleased()
{
}

void AplayerSkillController::OnRReleased()
{
}

void AplayerSkillController::OnAReleased()
{
}

void AplayerSkillController::OnSReleased()
{
}

void AplayerSkillController::OnDReleased()
{
}

void AplayerSkillController::OnFReleased()
{
}

void AplayerSkillController::OnVReleased()
{
}

void AplayerSkillController::UseSkill(int32 SkillID)
{
	UE_LOG(LogTemp, Warning, TEXT("Skill %d used!"), SkillID);
}

void AplayerSkillController::StopSkill(int32 SkillID)
{
}

void AplayerSkillController::SetupInputComponent()
{
	if (InputComponent) {
		InputComponent->BindAction("Q", IE_Pressed, this, &AplayerSkillController::OnQPressed);
		InputComponent->BindAction("W", IE_Pressed, this, &AplayerSkillController::OnWPressed);
		InputComponent->BindAction("E", IE_Pressed, this, &AplayerSkillController::OnEPressed);
		InputComponent->BindAction("R", IE_Pressed, this, &AplayerSkillController::OnRPressed);
		InputComponent->BindAction("A", IE_Pressed, this, &AplayerSkillController::OnAPressed);
		InputComponent->BindAction("S", IE_Pressed, this, &AplayerSkillController::OnSPressed);
		InputComponent->BindAction("D", IE_Pressed, this, &AplayerSkillController::OnDPressed);
		InputComponent->BindAction("F", IE_Pressed, this, &AplayerSkillController::OnFPressed);
		InputComponent->BindAction("V", IE_Pressed, this, &AplayerSkillController::OnVPressed);
	}
}

void AplayerSkillController::BeginPlay()
{
	Super::BeginPlay();
	SetupInputComponent();
}

void AplayerSkillController::OnSkillPressed(int32 SkillID)
{
	UE_LOG(LogTemp, Warning, TEXT("Skill %d pressed!"), SkillID);
	UseSkill(SkillID);
}

void AplayerSkillController::OnSkillReleased(int32 SkillID)
{
}

