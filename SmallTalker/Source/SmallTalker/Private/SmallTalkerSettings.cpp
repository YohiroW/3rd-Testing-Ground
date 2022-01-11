#include "SmallTalkerSettings.h"

USmallTalkerSettings::USmallTalkerSettings(const FObjectInitializer & ObjectInitializer)
	: Super(ObjectInitializer),
	DefaultStringBundlePath(TEXT(""))
{

}

FName USmallTalkerSettings::GetCategoryName() const
{
	return TEXT("Plugins");
}

#if WITH_EDITOR
FText USmallTalkerSettings::GetSectionText() const
{
	return NSLOCTEXT("SmallTalker", "SmallTalkerSettingsSection", "SmallTalker");
}

void USmallTalkerSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.Property != nullptr)
	{
		SettingsChangedDelegate.Broadcast(PropertyChangedEvent.Property->GetName(), this);
	}
}

USmallTalkerSettings::FOnSmallTalkerSettingsChanged& USmallTalkerSettings::OnSettingsChanged()
{
	return SettingsChangedDelegate;
}

USmallTalkerSettings::FOnSmallTalkerSettingsChanged USmallTalkerSettings::SettingsChangedDelegate;
#endif