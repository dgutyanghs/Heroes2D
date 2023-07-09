// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveGame.h"

#include "Kismet/GameplayStatics.h"

void UMySaveGame::DeleteSlot(FString slot)
{
		UGameplayStatics::DeleteGameInSlot(slot,0);
}
