// Copyright Sarah Cheung 2018.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"

#include "OpenDoor.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEGAME_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();

	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// property is visible in property windows but cannot be edited at all (VisibleAnywhere)
	UPROPERTY(EditAnywhere)
	// set door angle at the start
	float OpenAngle = -170.0f; // -90.0f
	
	// property is editable
	UPROPERTY(EditAnywhere)
	// invisible volume in the game worlld that can be used to tell code to do something
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.6f;

	float LastDoorOpenTime;

	AActor* Owner; // the owning door
	
	// Returns total mass in kg
	float GetTotalMassOfActorsOnPlate();
};
