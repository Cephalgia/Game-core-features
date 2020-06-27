#include "InteractionAction.h"

void UInteractionAction::PerformAction(UInteractionComponent * InComponent) 
{
	InteractionCounter++;
};

bool UInteractionAction::CanPerformAction(UInteractionComponent * InComponent)
{
	return bInfinite || InteractionCounter < 1;
}
