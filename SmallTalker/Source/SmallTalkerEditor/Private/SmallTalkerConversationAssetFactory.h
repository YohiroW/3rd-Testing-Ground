#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Factories/Factory.h"
#include "SmallTalkerConversationAssetFactory.generated.h"

UCLASS()
class USmallTalkerConversationAssetFactory : public UFactory
{
	GENERATED_BODY()

public:

	USmallTalkerConversationAssetFactory();

	// UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual FText GetToolTip() const override;
	virtual bool ShouldShowInNewMenu() const override;
	// End of UFactory interface
};