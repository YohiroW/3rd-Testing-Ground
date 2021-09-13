// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TextureRenderTarget2D.h"
#include "RHI/Public/RHIResources.h"
#include "PoseidonComponent.generated.h"

class FRHITexture;
class FRHIUnorderedAccessView;
class FRHICommandListImmediate;

USTRUCT(BlueprintType)
struct FOceanInfo
{
	GENERATED_BODY()

	FOceanInfo() {}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector4 OceanTime;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class POSEIDON_API UPoseidonComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPoseidonComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
