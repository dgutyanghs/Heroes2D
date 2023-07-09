// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class HEROES2D_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()


public:
	UPROPERTY()
	FVector PlayerLocation;

	UPROPERTY()
	int32 Score;

	/*
	UPROPERTY()
	FString SaveSlot = "GameData";
	*/

	static void DeleteSlot(FString slot = "GameData");
};
