// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpActor.h"

#include "HttpGameModeBase.h"
#include "HttpModule.h"
#include "HttpUI.h"
#include "Interfaces/IHttpResponse.h"

// Sets default values
AHttpActor::AHttpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHttpActor::BeginPlay()
{
	Super::BeginPlay();

	gm = Cast<AHttpGameModeBase>(GetWorld()->GetAuthGameMode());
	
}

// Called every frame
void AHttpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHttpActor::ReqData(const FString& url)
{
	// 웹서버(url)에 정보를 요청하고싶다.

	// 1. HttpModule를 가져오고
	FHttpModule& httpModule = FHttpModule::Get();
	// 2. 요청 객체를 생성하고
	TSharedPtr<IHttpRequest> req = httpModule.CreateRequest();
	// 3. 요청 객체에 요청할 값을 설정하고
	//  3.1 어디에 보낼것인가?
	req->SetURL( url );
	//  3.2 어떻게 보낼것인가?? GET / POST
	req->SetVerb( TEXT( "GET" ) );
	//  3.3 어떤 Content-Type으로 할것인가?
	req->SetHeader( TEXT( "Content-Type" ) , TEXT( "application/json" ) );
	// 4. 요청 객체에게 서버에서 응답이 오면 알려달라고 내함수를 등록하고싶다.
	req->OnProcessRequestComplete().BindUObject( this , &AHttpActor::ResData );
	// 5. 요청 객체에게 요청하라고 한다.
	req->ProcessRequest();
}

void AHttpActor::ResData(FHttpRequestPtr Request,FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	// 만약 통신이 성공했다면
	if (bConnectedSuccessfully)
	{
		// 응답의 결과를 ui에 보내고싶다.
		gm->httpUI->SetJson( Response->GetContentAsString());
	}
	else
	{
		UE_LOG( LogTemp , Warning , TEXT( "Response Failed... %d" ), Response->GetResponseCode() );
	}
}

