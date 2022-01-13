#include "SmallTalkerConversation.h"

void USmallTalkerConversationAsset::SetSmallTalkerConversation(USmallTalkerConversation* Conversation)
{
	if (Conversation != SmallTalkerConversation)
	{
//#if WITH_EDITOR
//		RegisterOnUpdateWavesData(WaterWaves, /*bRegister = */false);
//#endif // WITH_EDITOR

		SmallTalkerConversation = Conversation;

//#if WITH_EDITOR
//		RegisterOnUpdateWavesData(WaterWaves, /*bRegister = */true);
//		OnUpdateWavesAssetData.Broadcast(this, EPropertyChangeType::ValueSet);
//#endif // WITH_EDITOR		
	}
}