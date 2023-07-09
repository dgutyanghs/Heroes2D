// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicPaperCharacter.h"

#include "MyGameInstance.h"
#include "MySaveGame.h"
#include "Kismet/GameplayStatics.h"

void ABasicPaperCharacter::BeginPlay()
{
	Super::BeginPlay();

	MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	
}

void ABasicPaperCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("SaveGame", IE_Pressed, this, &ABasicPaperCharacter::SavePlayerLocation);
	PlayerInputComponent->BindAction("LoadGame", IE_Pressed, this, &ABasicPaperCharacter::LoadPlayerLocation);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABasicPaperCharacter::MoveForward);
	
}



#pragma  warning("When game started,repeat call MoveForward funtion  without press anykey. reason unknown")
void ABasicPaperCharacter::MoveForward(float AxisValue)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	UE_LOG(LogTemp, Display, TEXT("moveforward :%02f, %02f, %02f"), Direction.X, Direction.Y, Direction.Z);
	AddMovementInput(Direction, AxisValue);
}

void ABasicPaperCharacter::SavePlayerLocation()
{
	MyGameInstance->SaveGameData(this->GetActorLocation(),0);
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("save game!"));	
}

void ABasicPaperCharacter::LoadPlayerLocation()
{
	SetActorLocation(MyGameInstance->LoadGameData()->PlayerLocation);
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("load game!"));	
}
