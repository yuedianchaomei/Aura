


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const auto& InputAction : AbilityInputActions)
	{
		if (InputAction.InputTag == InputTag)
		{
			return InputAction.InputAction;
		}
	}
	return nullptr;
}
