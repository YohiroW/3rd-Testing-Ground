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

// As uniform buffer
USTRUCT(BlueprintType)
struct FOceanInfo
{
	GENERATED_BODY()

	FOceanInfo() {}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector4 OceanTime;
};

UCLASS(HideCategories = (Object, LOD, Physics, Collision), editinlinenew, meta = (BlueprintSpawnableComponent), ClassGroup = Rendering, DisplayName = "PoseidonComponent")
class POSEIDON_API UPoseidonComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPoseidonComponent(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	//
	virtual void OnRegister() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PoseidonComponent")
	UTextureRenderTarget2D* OutputRenderTarget2D;

	// Specified uniform buffer data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PoseidonComponent")
	FOceanInfo OceanInfoBuffer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PoseidonComponent")
	int32 TargetSize;

	ETextureRenderTargetFormat RenderTargetFormat;

private:
	void CalculateHeightMap_GameThread();

	void CalculateHeightMap_RenderThread(FRHICommandList& RHICmdList, ERHIFeatureLevel::Type featureLevel, FRHITexture* outputRT, int32 surfaceSize, const FOceanInfo& oceanInfo);

private:
	FTexture2DRHIRef OutputTexture;
	FUnorderedAccessViewRHIRef OutputTextureUAV;

};
