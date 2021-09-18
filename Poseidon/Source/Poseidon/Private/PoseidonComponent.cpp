// Fill out your copyright notice in the Description page of Project Settings.
#include "PoseidonComponent.h"

//BEGIN_UNIFORM_BUFFER_STRUCT(FOceanInfo, )
//	UNIFORM_MEMBER(FVector4, OceanTime)
//END_UNIFORM_BUFFER_STRUCT(FOceanInfo)
//
//IMPLEMENT_UNIFORM_BUFFER_STRUCT(FOceanInfo, TEXT("OceanInfoBuffer"))

class FPoseidonShaderCS : public FGlobalShader
{
	//DECLARE_GLOBAL_SHADER_TYPE(FPoseidonShaderCS)
	DECLARE_INLINE_TYPE_LAYOUT(FPoseidonShaderCS, NonVirtual);
	//SHADER_USE_PARAMETER_STRUCT_WITH_LEGACY_BASE(FPoseidonShaderCS, FGlobalShader); // Bind everything
	SHADER_USE_PARAMETER_STRUCT(FPoseidonShaderCS, FGlobalShader);


	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_STRUCT_REF(FViewUniformShaderParameters, View)
		SHADER_PARAMETER_STRUCT_REF(FOceanInfo, Time)
		RENDER_TARGET_BINDING_SLOTS()
	END_SHADER_PARAMETER_STRUCT()

public:
	FPoseidonShaderCS() = default;
	FPoseidonShaderCS(const ShaderMetaType::CompiledShaderInitializerType& Initializer) :
		FGlobalShader(Initializer)
	{
		// Bind params here
		OutputSurface.Bind(Initializer.ParameterMap, TEXT("OutputSurface"));
		SurfaceColor.Bind(Initializer.ParameterMap, TEXT("SurfaceColor"));
	}
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
	}

	// Functions below are copied from other shader as reference
	//static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	//{
	//	FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
	//	OutEnvironment.SetDefine(TEXT("GRID_SUBDIVISION_X"), kGridSubdivisionX);
	//	OutEnvironment.SetDefine(TEXT("GRID_SUBDIVISION_Y"), kGridSubdivisionY);
	//}

	template<typename TShaderRHIParamRef>
	void SetParameters(FRHICommandListImmediate& RHICmdList, const TShaderRHIParamRef ShaderRHI, const FTextureResource* PreComputedDisplacementMap, const FIntPoint& DisplacementMapResolution)
	{
		//FVector2D PixelUVSizeValue(1.f / float(DisplacementMapResolution.X), 1.f / float(DisplacementMapResolution.Y));

		//SetShaderValue(RHICmdList, ShaderRHI, PixelUVSize, PixelUVSizeValue);
		//SetTextureParameter(RHICmdList, ShaderRHI, UndistortDisplacementMap, BilinearSampler, TStaticSamplerState<SF_Bilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI(), PreComputedDisplacementMap->TextureRHI);
	}
private:

	LAYOUT_FIELD(FShaderParameter, SurfaceColor);
	LAYOUT_FIELD(FShaderResourceParameter, OutputSurface);

};

IMPLEMENT_GLOBAL_SHADER(FPoseidonShaderCS, TEXT("/Plugin/Poseidon/Poseidon.usf"), TEXT("PoseidonMainCS"), SF_Compute)


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

