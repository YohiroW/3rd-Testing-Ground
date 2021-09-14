// Fill out your copyright notice in the Description page of Project Settings.
#include "PoseidonComponent.h"

BEGIN_UNIFORM_BUFFER_STRUCT(FOceanInfo, )
	UNIFORM_MEMBER(FVector4, OceanTime)
END_UNIFORM_BUFFER_STRUCT(FOceanInfo)

IMPLEMENT_UNIFORM_BUFFER_STRUCT(FOceanInfo, TEXT("OceanInfoBuffer"))

class FPoseidonShader : public GlobalShader
{
	DECLARE_SHADER_TYPE(FOceeanCSShader, Global)

public:
	FPoseidonShader();
	FPoseidonShader(const ShaderMetaType::CompiledShaderInitializerType& Initializer) :
		FGlobalShader(Initializer)
	{
		// Bind params here
		OutputSurface.Bind(Initializer.ParameterMap, TEXT("OutputSurface"));
		SurfaceColor.Bind(Initializer.ParameterMap, TEXT("SurfaceColor"));
	}

private:
	FShaderResourceParameter OutputSurface;
	FShaderParameter SurfaceColor;
};

IMPLEMENT_SHADER_TYPE(, FOceeanCSShader, TEXT("/Plugin/Poseidon/Poseidon.usf"), TEXT("PoseidonMainCS"), SF_Compute)


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

