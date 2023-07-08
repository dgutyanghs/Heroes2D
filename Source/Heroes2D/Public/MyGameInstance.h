// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class HEROES2D_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

	void Init() override;

	FString SaveSlot = "GameData";

	class UMySaveGame* GameData;

public:
	void SaveGameData(FVector PlayerLocation, int32 Score);
	class UMySaveGame* LoadGameData();
	class UMySaveGame* GetGameData();
};
