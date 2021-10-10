#pragma once

#include "CoreMinimal.h"
#include "SceneViewExtension.h"


class FPoseidonViewExtension : public FSceneViewExtensionBase
{
public:

	FPoseidonViewExtension(const FAutoRegister& AutoReg);
	~FPoseidonViewExtension();

	// FSceneViewExtensionBase implementation : 
	virtual void SetupViewFamily(FSceneViewFamily& InViewFamily) override;
	virtual void SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView) override {}
	virtual void BeginRenderViewFamily(FSceneViewFamily& InViewFamily) override {}
	virtual void PreRenderViewFamily_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& InViewFamily) override {}
	virtual void PreRenderView_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView) override;
	

	bool bRebuildGPUData = false;

	FStructuredBufferRHIRef DataBuffer;
	FShaderResourceViewRHIRef DataSRV;

	FStructuredBufferRHIRef IndirectionBuffer;
	FShaderResourceViewRHIRef IndirectionSRV;
};
