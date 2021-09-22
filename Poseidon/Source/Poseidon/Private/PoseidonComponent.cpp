// Fill out your copyright notice in the Description page of Project Settings.
#include "PoseidonComponent.h"

#include "CanvasTypes.h"
#include "RenderTargetTemp.h"
#include "UnrealEngine.h"
#include "RHIStaticStates.h"
#include "Engine/TextureRenderTarget2D.h"

class FPoseidonShaderCS : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FPoseidonShaderCS);
	SHADER_USE_PARAMETER_STRUCT(FPoseidonShaderCS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_STRUCT_REF(FViewUniformShaderParameters, View)
		SHADER_PARAMETER(float, time)
	END_SHADER_PARAMETER_STRUCT()

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
	}
};
IMPLEMENT_GLOBAL_SHADER(FPoseidonShaderCS, "/Plugin/Poseidon/Poseidon.usf", "PoseidonMainCS", SF_Compute)


// Sets default values for this component's properties
UPoseidonComponent::UPoseidonComponent(const FObjectInitializer& ObjectInitializer)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPoseidonComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UPoseidonComponent::OnRegister()
{
}

// Called every frame
void UPoseidonComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPoseidonComponent::CalculateHeightMap_GameThread()
{
}

void UPoseidonComponent::CalculateHeightMap_RenderThread(FRHICommandList& RHICmdList, ERHIFeatureLevel::Type featureLevel, FRHITexture* outputRT, int32 surfaceSize, const FOceanInfo& oceanInfo)
{
}

