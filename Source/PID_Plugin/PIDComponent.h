// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PIDComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PID_PLUGIN_API UPIDComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPIDComponent();


	UFUNCTION(BlueprintCallable, Category = "PID")
		float Calculate(float setPoint, float processValue, float Kp, float Ki, float Kd, float deltaTime);

private:

	float error = 0.0f;
	float errorD = 0.0f;
	float errorI = 0.0f;
	float lastError = 0.0f;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
