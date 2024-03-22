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
	btn_sendPost->OnClicked.AddDynamic( this , &UHttpUI::OnMySendPost );
}

void UHttpUI::OnMySend()
{
	FString tempPage = page.Replace( TEXT( "[PAGE_NO]" ), *edit_pageNo->GetText().ToString() );
	tempPage = tempPage.Replace( TEXT( "[ROW]" ) , *edit_row->GetText().ToString() );
	FString fullURL = FString::Printf(TEXT("%s%s%s"), *url,  *serviceKey, *tempPage );
	UE_LOG( LogTemp , Warning , TEXT( "url : %s" ) , *fullURL );
	gm->httpActor->ReqData( fullURL );
}

void UHttpUI::SetJson(FString str)
{
	txt_json->SetText(FText::FromString(str));
}

void UHttpUI::OnMySendPost()
{
	FString fullURL = "http://127.0.0.1:5000/test";
	gm->httpActor->ReqDataPost( fullURL );
}

void UHttpUI::SetJsonFromPost(FString str)
{
	txt_json->SetText( FText::FromString( str ) );
}
