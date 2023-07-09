// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"

#include "MyGameInstance.h"
#include "MySaveGame.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//UMySaveGame::DeleteSlot();

	GameData = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlot, 0));
	if (GameData)
	{
		LoadGameBtn->SetIsEnabled(true);	
		LoadGameBtn->OnClicked.AddDynamic(this, &UMainMenuWidget::LoadGame);
		UE_LOG(LogTemp, Display, TEXT("GameData not nullptr"));
	} else
	{
		ContinueBtn->SetIsEnabled(false);
		LoadGameBtn->SetIsEnabled(false);
		UE_LOG(LogTemp, Display, TEXT("GameData is nullptr"));
		
	}
	
}

void UMainMenuWidget::LoadGame()
{
	UE_LOG(LogTemp, Display, TEXT("loading game"));
}

void UMainMenuWidget::OnButtonClicked()
{
	
}

