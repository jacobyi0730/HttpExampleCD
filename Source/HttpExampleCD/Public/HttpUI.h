// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HttpUI.generated.h"

/**
 * 
 */
UCLASS()
class HTTPEXAMPLECD_API UHttpUI : public UUserWidget
{
	GENERATED_BODY()


public:
	virtual  void NativeConstruct() override;

	UPROPERTY()
	class AHttpGameModeBase* gm;


	FString url = "https://apis.data.go.kr/5050000/cafeInfoService/getCafeInfo?serviceKey=";

	FString serviceKey = "xtHbWpFpd5Q8eg13ynvmWGNTHfXjZHZlCa%2B9%2F%2FsCC9AbMIBbA2FHhw%2BElWfKfq7uFEjS%2F21nuDn%2BvWl569cMnQ%3D%3D";

	FString page = "&pageNo=[PAGE_NO]&numOfRows=[ROW]";

	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	class UEditableText* edit_pageNo;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UEditableText* edit_row;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UButton* btn_send;

	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* txt_json;

	UFUNCTION()
	void OnMySend();

	void SetJson(FString str);

	UPROPERTY( EditDefaultsOnly , meta = (BindWidget) )
	class UButton* btn_sendPost;

	UFUNCTION()
	void OnMySendPost();

	void SetJsonFromPost( FString str );

};
