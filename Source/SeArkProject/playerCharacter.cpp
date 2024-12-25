// Fill out your copyright notice in the Description page of Project Settings.


#include "playerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AplayerCharacter::AplayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true; // 비긴 스타트 이후 실행되게 함

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f); //캐릭터 클래스에 있는 기본 콜라이더를 가져와서 캡슐콜라이더 함수의 크기를 정한다.

	bUseControllerRotationPitch = false; 
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false; //캐릭터가 카메라의 회전을 따라가지 않게 false로 변경 true면 캐릭터가 카메라를 따라감

	GetCharacterMovement()-> bOrientRotationToMovement = true; 
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f); //캐릭터가 바라보는 방향과 이동방향이 다를시 해당 방향으로 캐릭터가 회전하고 그 회전 속도를 설정함
	GetCharacterMovement()->bConstrainToPlane = true; //캐릭터의 이동을 평면으로 전환
	GetCharacterMovement()->bSnapToPlaneAtStart = true; //캐릭터생성의 위치가 평면을 벗어나면 주변 평면에서 생성

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm")); //스프링암 생성 초기화
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->SetUsingAbsoluteRotation(true); //스프링 암의 회전이 루트 컴포넌트와 상위 컴포넌트의 회전을 따르지 않고 월드 좌표계의 회전을 따르게 함
	SpringArmComponent->TargetArmLength = 800.0f; //카메라와 캐릭터의 거리 
	SpringArmComponent->SetRelativeRotation(FRotator(-60.0f, 45.0f, 0.0f)); //스프링 암을 회전시켜 캐릭터를 내려다 보게함
	SpringArmComponent->bDoCollisionTest = false; //카메라가 벽에 닿으면 충돌 계산을 통해 카메라와 캐릭터의 거리를 좁히는 함수 탑다운은 해당 x이므로 false

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera")); //카메라 컴포넌트 생성
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName); //카메라 컴포넌트를 스프링 암 컴포넌트에 붙이기
	CameraComponent->bUsePawnControlRotation = false; //카메라의 회전이 폰의 회전에 영향을 주지 않게함
}

// Called when the game starts or when spawned
void AplayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AplayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AplayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

