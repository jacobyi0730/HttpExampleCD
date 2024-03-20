// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HttpGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class HTTPEXAMPLECD_API AHttpGameModeBase : public AGameModeBase
{
	GENERATED_BODY()


public:
	AHttpGameModeBase();

	virtual void BeginPlay() override;

	// 태어날 때 WBP_HttpUI를 생성해서 화면에 보이게하고싶다.
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> httpUIFactory;

	class UHttpUI* httpUI;
};
