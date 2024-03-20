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

	// �¾ �� WBP_HttpUI�� �����ؼ� ȭ�鿡 ���̰��ϰ�ʹ�.
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> httpUIFactory;

	class UHttpUI* httpUI;
};
