// Shoot Them Up Game, All Rights Reserved.


#include "Component/MyActor.h"

// Sets default values for this component's properties
UMyActor::UMyActor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyActor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyActor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

