#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SmallTalkerDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FSmallTalkerTextEntry
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DataEntry, meta = (DisplayPriority = "1"))
	FString Category;

	// Id- LineText
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DataEntry)
	TMap<FString, FString> StringBundleEntry;
};

USTRUCT(BlueprintType)
struct FSmallTalkerDataEntry
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SmallTalkerData)
	FSmallTalkerTextEntry SmallTalkerData;
};

/**
 * 
 */
UCLASS(Blueprintable)
class SMALLTALKER_API USmallTalkerDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
#if WITH_EDITORONLY_DATA 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "String Bundle")
	TArray< FSmallTalkerDataEntry> StringBundleData;
#endif

#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};
