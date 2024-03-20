// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpUI.h"

#include "Components/TextBlock.h"

void UHttpUI::NativeConstruct()
{
	Super::NativeConstruct();
}

void UHttpUI::OnMySend()
{
}

void UHttpUI::SetJson(FString str)
{
	txt_json->SetText(FText::FromString(str));
}
