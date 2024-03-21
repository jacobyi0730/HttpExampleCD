// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpGameModeBase.h"

#include "HttpActor.h"
#include "HttpUI.h"

AHttpGameModeBase::AHttpGameModeBase()
{
	ConstructorHelpers::FClassFinder<UUserWidget> tempHttpUI(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/WBP_HttpUI.WBP_HttpUI_C'"));

	if (tempHttpUI.Succeeded())
	{
		httpUIFactory = tempHttpUI.Class;
	}
}

void AHttpGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	if (httpUIFactory)
	{
		httpUI = CreateWidget<UHttpUI>(GetWorld(), httpUIFactory);
		if (httpUI)
			httpUI->AddToViewport();
	}
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);

	// 태어날 때 통신을 주고받을 주체인 액터를 만들고싶다.
	httpActor = GetWorld()->SpawnActor<AHttpActor>( AHttpActor::StaticClass() , FVector(0) , FRotator(0) );
}
