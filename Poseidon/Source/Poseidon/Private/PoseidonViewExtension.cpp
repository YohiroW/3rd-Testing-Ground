#include "PoseidonViewExtension.h"

FPoseidonViewExtension::FPoseidonViewExtension(const FAutoRegister& AutoReg):
	FSceneViewExtensionBase(AutoReg)
{

}

FPoseidonViewExtension::~FPoseidonViewExtension()
{

}

void FPoseidonViewExtension::SetupViewFamily(FSceneViewFamily& InViewFamily)
{
	if (bRebuildGPUData)
	{
		TResourceArray<FVector4> PoseidonIndirectionBuffer;
		TResourceArray<FVector4> PoseidonDataBuffer;

		if (PoseidonIndirectionBuffer.Num() == 0)
		{
			PoseidonIndirectionBuffer.AddZeroed();
		}

		if (PoseidonDataBuffer.Num() == 0)
		{
			PoseidonDataBuffer.AddZeroed();
		}

		ENQUEUE_RENDER_COMMAND(AllocatePoseidonInstanceDataBuffer)
		(
			[this, PoseidonDataBuffer, PoseidonIndirectionBuffer](FRHICommandListImmediate& RHICmdList) mutable
			{
				FRHIResourceCreateInfo CreateInfoData(TEXT("PoseidonDataBuffer"));
				CreateInfoData.ResourceArray = &PoseidonDataBuffer;
				DataBuffer = RHICreateStructuredBuffer(sizeof(FVector4), PoseidonDataBuffer.GetResourceDataSize(), BUF_StructuredBuffer | BUF_ShaderResource | BUF_Static, ERHIAccess::SRVMask, CreateInfoData);
				DataSRV = RHICreateShaderResourceView(DataBuffer);

				FRHIResourceCreateInfo CreateInfoIndirection(TEXT("PoseidonIndirectionBuffer"));
				CreateInfoIndirection.ResourceArray = &PoseidonIndirectionBuffer;
				IndirectionBuffer = RHICreateStructuredBuffer(sizeof(FVector4), PoseidonIndirectionBuffer.GetResourceDataSize(), BUF_StructuredBuffer | BUF_ShaderResource | BUF_Static, ERHIAccess::SRVMask, CreateInfoIndirection);
				IndirectionSRV = RHICreateShaderResourceView(IndirectionBuffer);
			}
		);

		bRebuildGPUData = false;
	}
}

void FPoseidonViewExtension::PreRenderView_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView)
{
	if (DataSRV && IndirectionSRV)
	{

	}
}

