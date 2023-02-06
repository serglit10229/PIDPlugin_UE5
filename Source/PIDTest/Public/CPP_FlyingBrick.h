// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PIDComponent.h"
#include "Components/TextRenderComponent.h"

#include "CPP_FlyingBrick.generated.h"

UCLASS()
class PIDTEST_API ACPP_FlyingBrick : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ACPP_FlyingBrick();

	UStaticMeshComponent* staticMeshComponent;
	UTextRenderComponent* TextComponent;
	UPIDComponent* PIDComponent;

	UPROPERTY(EditAnywhere)
		UMaterial* brickMaterial;
	UPROPERTY(EditAnywhere)
		float SetAltitude = 120.0f;
	UPROPERTY(EditAnywhere)
		float PID_P = 10000.0f;
	UPROPERTY(EditAnywhere)
		float PID_I = 0.0f;
	UPROPERTY(EditAnywhere)
		float PID_D = 0.0f;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
