#include "SmallTalkerDataAsset.h"

#if WITH_EDITOR
void USmallTalkerDataAsset::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	// const FName PropertyName = PropertyChangedEvent.MemberProperty ? PropertyChangedEvent.MemberProperty->GetFName() : NAME_None;

	// if (PropertyName == FName(TEXT("SphericalLimitsData")))
	// {
	// 	if (PropertyChangedEvent.ChangeType == EPropertyChangeType::Duplicate)
	// 	{
	// 		SphericalLimitsData[PropertyChangedEvent.GetArrayIndex(PropertyName.ToString())].Guid = FGuid::NewGuid();
	// 	}

	// 	SphericalLimits.Empty();
	// 	for (FSphericalLimitData& Data : SphericalLimitsData)
	// 	{
	// 		SphericalLimits.Add(Data.Convert());
	// 	}
	// }
}


#endif
