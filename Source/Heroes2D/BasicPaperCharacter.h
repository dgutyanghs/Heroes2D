// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "BasicPaperCharacter.generated.h"

/**
 * 
 */
UCLASS()
class HEROES2D_API ABasicPaperCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void MoveForward(float AxisValue);

private:

	class UMyGameInstance* MyGameInstance;

	void SavePlayerLocation();
	void LoadPlayerLocation();
};
