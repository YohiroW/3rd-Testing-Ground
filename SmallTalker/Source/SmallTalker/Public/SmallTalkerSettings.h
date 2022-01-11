#pragma once

#include "Engine/DeveloperSettings.h"
#include "SmallTalkerSettings.generated.h"

/**
* Settings for SmallTalker
*/
UCLASS(Config = SmallTalker, DefaultConfig, Meta = (DisplayName = "SmallTalker"))
class SMALLTALKER_API USmallTalkerSettings : public UDeveloperSettings
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY(Config, EditAnywhere, Category = General)
	FString DefaultStringBundlePath;

	FName GetCategoryName() const override;

#if WITH_EDITOR
	FText GetSectionText() const override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	
	
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnSmallTalkerSettingsChanged, const FString&, const USmallTalkerSettings*);

	static FOnSmallTalkerSettingsChanged& OnSettingsChanged();
protected:
	static FOnSmallTalkerSettingsChanged SettingsChangedDelegate;
#endif

};