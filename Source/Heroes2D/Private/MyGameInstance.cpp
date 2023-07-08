// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

#include "MySaveGame.h"
#include "Kismet/GameplayStatics.h"

void UMyGameInstance::Init()
{
	// check if there is game data to load it
	// or create a new one if the game is just starting
	GameData = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlot, 0));

	if(!GameData)
	{
		// create a new game data
		GameData = Cast<UMySaveGame>(UGameplayStatics::
			CreateSaveGameObject(UMySaveGame::StaticClass()));

		GameData->PlayerLocation = FVector(0, 0, 0);
		GameData->Score = 0;

		UGameplayStatics::SaveGameToSlot(GameData, SaveSlot, 0);
	}
}

void UMyGameInstance::SaveGameData(FVector PlayerLocation, int32 Score)
{
	if (GameData)
	{
		GameData->PlayerLocation = PlayerLocation;
		GameData->Score = Score;

		UGameplayStatics::SaveGameToSlot(GameData, SaveSlot, 0);
	}
}

UMySaveGame* UMyGameInstance::LoadGameData()
{
	if (GameData)
	{
		return  GameData;
	}
	else
	{
		return  nullptr;
	}
}
