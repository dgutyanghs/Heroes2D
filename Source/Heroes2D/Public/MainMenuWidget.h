// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class HEROES2D_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UButton* NewGameBtn;
	//class UTextBlock* TextLabels;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UButton* ContinueBtn;

	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UButton* LoadGameBtn;

	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	class UButton* ExitBtn;

	virtual void NativeConstruct() override;

	UFUNCTION()
	void LoadGame();

	UFUNCTION()
	void OnButtonClicked();

	class UMySaveGame* GameData;
	FString SaveSlot = "GameData";
};
