// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h"
#include "HttpActor.generated.h"

UCLASS()
class HTTPEXAMPLECD_API AHttpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHttpActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	class AHttpGameModeBase* gm;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ReqData(const FString& url );

	void ResData( FHttpRequestPtr Request ,  FHttpResponsePtr Response , bool bConnectedSuccessfully );


	void ReqDataPost( const FString& url );

	void ResDataPost( FHttpRequestPtr Request , FHttpResponsePtr Response , bool bConnectedSuccessfully );
};
