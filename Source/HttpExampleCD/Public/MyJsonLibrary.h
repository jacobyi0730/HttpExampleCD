// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyJsonLibrary.generated.h"

/**
 * 
 */
UCLASS()
class HTTPEXAMPLECD_API UMyJsonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	static FString JsonParse(const FString& data );

	
};
