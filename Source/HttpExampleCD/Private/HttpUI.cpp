// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpUI.h"

#include "HttpActor.h"
#include "HttpGameModeBase.h"
#include "Components/Button.h"
#include "Components/EditableText.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UHttpUI::NativeConstruct()
{
	Super::NativeConstruct();

	gm = Cast<AHttpGameModeBase>(GetWorld()->GetAuthGameMode());
	btn_send->OnClicked.AddDynamic( this , &UHttpUI::OnMySend );
	btn_sendPost->OnClicked.AddDynamic( this , &UHttpUI::OnMySendPost );
	btn_getWebImage->OnClicked.AddDynamic( this , &UHttpUI::OnMyGetWebImage );
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
	FString username = TEXT( "Song" );
	fullURL = fullURL + "?username=" + username;
	gm->httpActor->ReqDataPost( fullURL );
}

void UHttpUI::SetJsonFromPost(FString str)
{
	txt_json->SetText( FText::FromString( str ) );
}

void UHttpUI::OnMyGetWebImage()
{
	FString img_url = TEXT("https://cdn-icons-png.flaticon.com/512/7101/7101338.png");
	gm->httpActor->ReqWebImage( img_url );
}

void UHttpUI::SetWebImage(UTexture2D* texture)
{
	Image_web->SetBrushFromTexture( texture );
}
