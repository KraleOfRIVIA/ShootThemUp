//Shoot Them Up Game, All Rights Reserved.


#include "AI/Services/STUFindEnemyService.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "STUUtils.h"
#include "Component/STUAIPerceptionComponent.h"
#include "Component/STUHealthComponent.h"
USTUFindEnemyService::USTUFindEnemyService()
{
	NodeName = "FindEnemy";
}

void USTUFindEnemyService::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
	UE_LOG(LogTemp, Display, TEXT( "Find enemy"))
	const auto Blackboard = OwnerComp.GetBlackboardComponent();
	if (Blackboard)
	{
		const auto Controller = OwnerComp.GetAIOwner();
		const auto PercepsionComponent = STUUtils::GetSTUPlayerComponent<USTUAIPerceptionComponent>(Controller);
		if (PercepsionComponent)
		{
			Blackboard->SetValueAsObject(EnemyActorKey.SelectedKeyName, PercepsionComponent->GetClosestEnemy());
		}
	}
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
