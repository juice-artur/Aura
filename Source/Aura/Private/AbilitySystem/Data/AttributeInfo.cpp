// Aura, Copyright 2025 – 2025, Juicy, Inc.

#include "AbilitySystem/Data/AttributeInfo.h"

#include "Aura/AuraLogChannels.h"


FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& Tag, bool bLogNotFound)
{
	for (auto& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(Tag))
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogAura, Error, TEXT("Can`t find info for AttributeTag [%s] on AttributeInfo [%s]"),
			*Tag.ToString(), *GetNameSafe(this));
	}
	
	return FAuraAttributeInfo();
}
