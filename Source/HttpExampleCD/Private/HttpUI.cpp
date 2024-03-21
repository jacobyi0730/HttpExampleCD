// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpUI.h"

#include "HttpActor.h"
#include "HttpGameModeBase.h"
#include "Components/Button.h"
#include "Components/EditableText.h"
#include "Components/TextBlock.h"

void UHttpUI::NativeConstruct()
{
	Super::NativeConstruct();

	gm = Cast<AHttpGameModeBase>(GetWorld()->GetAuthGameMode());
	btn_send->OnClicked.AddDynamic( this , &UHttpUI::OnMySend );
}

void UHttpUI::OnMySend()
{
	page = page.Replace( TEXT( "[PAGE_NO]" ), *edit_pageNo->GetText().ToString() );
	page = page.Replace( TEXT( "[ROW]" ) , *edit_row->GetText().ToString() );
	FString fullURL = FString::Printf(TEXT("%s%s%s"), *url,  *serviceKey, *page );
	gm->httpActor->ReqData( fullURL );
}

void UHttpUI::SetJson(FString str)
{
	txt_json->SetText(FText::FromString(str));
}
