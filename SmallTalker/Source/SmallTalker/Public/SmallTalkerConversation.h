#pragma once

#include "CoreMinimal.h"
#include "SmallTalkerConversation.generated.h"

class USmallTalkerConversation;

UCLASS(EditInlineNew, BlueprintType, NotBlueprintable, Abstract)
class SMALLTALKER_API USmallTalkerConversationBase : public UObject
{
	GENERATED_BODY()
	
public:
	/** Return the underlying Conversation class type. This will jump through the potential USmallTalkerConversationAssetReference to get to the actual conversation data */
	virtual const USmallTalkerConversation* GetSmallTalkerConversation() const PURE_VIRTUAL(USmallTalkerConversationBase::GetSmallTalkerConversation, return nullptr;)
	virtual USmallTalkerConversation* GetSmallTalkerConversation() PURE_VIRTUAL(USmallTalkerConversationBase::GetSmallTalkerConversation, return nullptr;)

public:
	FString Category;
	FString LineID;
	
	//
	// Append GlobalVariable this conversation instance triggered,
	// and the audio source should be play
	//
};

UCLASS(EditInlineNew, BlueprintType, NotBlueprintable, Abstract)
class SMALLTALKER_API USmallTalkerConversation : public USmallTalkerConversationBase
{
	GENERATED_BODY()

	virtual const USmallTalkerConversation* GetSmallTalkerConversation() const override { return this; }
	virtual USmallTalkerConversation* GetSmallTalkerConversation() override { return this; }
};

UCLASS(BlueprintType, NotBlueprintable, AutoExpandCategories = "Small Talker Conversation")
class SMALLTALKER_API USmallTalkerConversationAsset : public UObject
{
	GENERATED_BODY()

public:
	void SetSmallTalkerConversation(USmallTalkerConversation* Conversation);
	const USmallTalkerConversation* GetSmallTalkerConversation() const { return SmallTalkerConversation; }
	USmallTalkerConversation* GetSmallTalkerConversation() { return SmallTalkerConversation; }

private:
	UPROPERTY(EditAnywhere, Category = "SmallTalker Conversation", Instanced, DisplayName = "Conversation Source")
	USmallTalkerConversation* SmallTalkerConversation = nullptr;
};