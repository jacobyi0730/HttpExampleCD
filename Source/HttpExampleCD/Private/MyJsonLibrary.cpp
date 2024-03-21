// Fill out your copyright notice in the Description page of Project Settings.


#include "MyJsonLibrary.h"

#include "Json.h"

FString UMyJsonLibrary::JsonParse(const FString& data)
{
	FString json;

	// JsonReader를 만든다.
	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create( data );
	// JsonObject를 만든다.
	TSharedPtr<FJsonObject> jsonObj = MakeShareable( new FJsonObject() );

	/*for (int i=0 ; i<2 ; i++)
	{
		FString title = TEXT( "CON_TITLE" );
		FString addr = TEXT( "CON_ADDRESS" );
		json.Append( FString::Printf( TEXT( "title : %s / address : %s\n" ) , *title , *addr ) );
	}*/
	// 해독(deserialize)을한다.
	if (FJsonSerializer::Deserialize( reader , jsonObj))
	{
		auto response = jsonObj->GetObjectField( TEXT( "response" ) );
		auto body = response->GetObjectField( TEXT( "body" ) );
		auto items = body->GetObjectField( TEXT( "items" ) );
		TArray<TSharedPtr<FJsonValue>> item = items->GetArrayField( TEXT( "item" ) );

		for (TSharedPtr<FJsonValue> pair : item)
		{
			FString title = pair->AsObject()->GetStringField( "CON_TITLE" );
			FString addr = pair->AsObject()->GetStringField( "CON_ADDRESS" );
			json.Append(FString::Printf(TEXT("title : %s / address : %s\n"), *title , *addr) );
		}
	}


	return json;
}
