// wrapper for ID3D11DeviceContext in d3d11.h
// generated using wrapper_gen11.rb

//Borrowed from https://raw.githubusercontent.com/PeterTh/gedosato/master/source/d3d11/d3d11devcontext.cpp on 07/16/2016
//SLIGHT MODIFICATIONS TO NAMING

#include "d3d11devicecontext_wrapper.h"
#include "Config.h"
#include "Log.h"
#include "RenderInfo.h"
#include <functional>

ID3D11DeviceContext_Wrapper::ID3D11DeviceContext_Wrapper(ID3D11DeviceContext **ppID3D11DeviceContext, ID3D11Device_Wrapper* pDevWrapper) {
	Logger::Log("ID3D11DeviceContext_Wrapper created");
	pWrapped = *ppID3D11DeviceContext;
	pDeviceWrapper = pDevWrapper;
	*ppID3D11DeviceContext = this;
	pDeviceWrapper->pSwapChainWrapper->presentCallback = std::bind(&ID3D11DeviceContext_Wrapper::OnPresentCallback, this);
}

HRESULT APIENTRY ID3D11DeviceContext_Wrapper::QueryInterface(REFIID riid, void **ppvObject) {
	return pWrapped->QueryInterface(riid, ppvObject);
}

ULONG APIENTRY ID3D11DeviceContext_Wrapper::AddRef() {
	return pWrapped->AddRef();
}

ULONG APIENTRY ID3D11DeviceContext_Wrapper::Release() {
	return pWrapped->Release();
}

void APIENTRY ID3D11DeviceContext_Wrapper::GetDevice(ID3D11Device **ppDevice) {
	return pWrapped->GetDevice(ppDevice);
}

HRESULT APIENTRY ID3D11DeviceContext_Wrapper::GetPrivateData(REFGUID guid, UINT *pDataSize, void *pData) {
	return pWrapped->GetPrivateData(guid, pDataSize, pData);
}

HRESULT APIENTRY ID3D11DeviceContext_Wrapper::SetPrivateData(REFGUID guid, UINT DataSize, const void *pData) {
	return pWrapped->SetPrivateData(guid, DataSize, pData);
}

HRESULT APIENTRY ID3D11DeviceContext_Wrapper::SetPrivateDataInterface(REFGUID guid, const IUnknown *pData) {
	return pWrapped->SetPrivateDataInterface(guid, pData);
}

void APIENTRY ID3D11DeviceContext_Wrapper::VSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers) {
	return pWrapped->VSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::PSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews) {
	return pWrapped->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void APIENTRY ID3D11DeviceContext_Wrapper::PSSetShader(ID3D11PixelShader *pPixelShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances) {
	return pWrapped->PSSetShader(pPixelShader, ppClassInstances, NumClassInstances);
}

void APIENTRY ID3D11DeviceContext_Wrapper::PSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers) {
	return pWrapped->PSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::VSSetShader(ID3D11VertexShader *pVertexShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances) {
	return pWrapped->VSSetShader(pVertexShader, ppClassInstances, NumClassInstances);
}

void APIENTRY ID3D11DeviceContext_Wrapper::DrawIndexed(UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation) {
	return pWrapped->DrawIndexed(IndexCount, StartIndexLocation, BaseVertexLocation);
}

void APIENTRY ID3D11DeviceContext_Wrapper::Draw(UINT VertexCount, UINT StartVertexLocation) {
	return pWrapped->Draw(VertexCount, StartVertexLocation);
}

HRESULT APIENTRY ID3D11DeviceContext_Wrapper::Map(ID3D11Resource *pResource, UINT Subresource, D3D11_MAP MapType, UINT MapFlags, D3D11_MAPPED_SUBRESOURCE *pMappedResource) {
	return pWrapped->Map(pResource, Subresource, MapType, MapFlags, pMappedResource);
}

void APIENTRY ID3D11DeviceContext_Wrapper::Unmap(ID3D11Resource *pResource, UINT Subresource) {
	return pWrapped->Unmap(pResource, Subresource);
}

void APIENTRY ID3D11DeviceContext_Wrapper::PSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers) {
	return pWrapped->PSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::IASetInputLayout(ID3D11InputLayout *pInputLayout) {
	return pWrapped->IASetInputLayout(pInputLayout);
}

void APIENTRY ID3D11DeviceContext_Wrapper::IASetVertexBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppVertexBuffers, const UINT *pStrides, const UINT *pOffsets) {
	return pWrapped->IASetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
}

void APIENTRY ID3D11DeviceContext_Wrapper::IASetIndexBuffer(ID3D11Buffer *pIndexBuffer, DXGI_FORMAT Format, UINT Offset) {
	return pWrapped->IASetIndexBuffer(pIndexBuffer, Format, Offset);
}

void APIENTRY ID3D11DeviceContext_Wrapper::DrawIndexedInstanced(UINT IndexCountPerInstance, UINT InstanceCount, UINT StartIndexLocation, INT BaseVertexLocation, UINT StartInstanceLocation) {
	return pWrapped->DrawIndexedInstanced(IndexCountPerInstance, InstanceCount, StartIndexLocation, BaseVertexLocation, StartInstanceLocation);
}

void APIENTRY ID3D11DeviceContext_Wrapper::DrawInstanced(UINT VertexCountPerInstance, UINT InstanceCount, UINT StartVertexLocation, UINT StartInstanceLocation) {
	return pWrapped->DrawInstanced(VertexCountPerInstance, InstanceCount, StartVertexLocation, StartInstanceLocation);
}

void APIENTRY ID3D11DeviceContext_Wrapper::GSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers) {
	return pWrapped->GSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::GSSetShader(ID3D11GeometryShader *pShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances) {
	return pWrapped->GSSetShader(pShader, ppClassInstances, NumClassInstances);
}

void APIENTRY ID3D11DeviceContext_Wrapper::IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology) {
	return pWrapped->IASetPrimitiveTopology(Topology);
}

void APIENTRY ID3D11DeviceContext_Wrapper::VSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews) {
	return pWrapped->VSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void APIENTRY ID3D11DeviceContext_Wrapper::VSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers) {
	return pWrapped->VSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::Begin(ID3D11Asynchronous *pAsync) {
	return pWrapped->Begin(pAsync);
}

void APIENTRY ID3D11DeviceContext_Wrapper::End(ID3D11Asynchronous *pAsync) {
	return pWrapped->End(pAsync);
}

HRESULT APIENTRY ID3D11DeviceContext_Wrapper::GetData(ID3D11Asynchronous *pAsync, void *pData, UINT DataSize, UINT GetDataFlags) {
	return pWrapped->GetData(pAsync, pData, DataSize, GetDataFlags);
}

void APIENTRY ID3D11DeviceContext_Wrapper::SetPredication(ID3D11Predicate *pPredicate, BOOL PredicateValue) {
	return pWrapped->SetPredication(pPredicate, PredicateValue);
}

void APIENTRY ID3D11DeviceContext_Wrapper::GSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews) {
	return pWrapped->GSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void APIENTRY ID3D11DeviceContext_Wrapper::GSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers) {
	return pWrapped->GSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::OMSetRenderTargets(UINT NumViews, ID3D11RenderTargetView *const *ppRenderTargetViews, ID3D11DepthStencilView *pDepthStencilView) {
	//When the backbuffer render target is bound, do not scale the viewport
	if (justPresented)
	{
		//Ignore the first OMSetRenderTargets call after present was just called, since the first call to this function is used to clear the backbuffer.
		justPresented = false;
	}
	else if (ppRenderTargetViews && (*ppRenderTargetViews) == pDeviceWrapper->pBackBufferRenderTarget)
	{
		scaleViewport = false;
		//This causes some minor issues, such as when the player is in the menu, and the background image is statically displayed in the background, that background
		//texture is not correctly scaled consistently. I haven't looked into fixing this but it's such a minor issue that I don't really think it's worth fixing
	}
	return pWrapped->OMSetRenderTargets(NumViews, ppRenderTargetViews, pDepthStencilView);
}

void APIENTRY ID3D11DeviceContext_Wrapper::OMSetRenderTargetsAndUnorderedAccessViews(UINT NumRTVs, ID3D11RenderTargetView *const *ppRenderTargetViews, ID3D11DepthStencilView *pDepthStencilView, UINT UAVStartSlot, UINT NumUAVs, ID3D11UnorderedAccessView *const *ppUnorderedAccessViews, const UINT *pUAVInitialCounts) {
	return pWrapped->OMSetRenderTargetsAndUnorderedAccessViews(NumRTVs, ppRenderTargetViews, pDepthStencilView, UAVStartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts);
}

void APIENTRY ID3D11DeviceContext_Wrapper::OMSetBlendState(ID3D11BlendState *pBlendState, const FLOAT BlendFactor[4], UINT SampleMask) {
	return pWrapped->OMSetBlendState(pBlendState, BlendFactor, SampleMask);
}

void APIENTRY ID3D11DeviceContext_Wrapper::OMSetDepthStencilState(ID3D11DepthStencilState *pDepthStencilState, UINT StencilRef) {
	return pWrapped->OMSetDepthStencilState(pDepthStencilState, StencilRef);
}

void APIENTRY ID3D11DeviceContext_Wrapper::SOSetTargets(UINT NumBuffers, ID3D11Buffer *const *ppSOTargets, const UINT *pOffsets) {
	return pWrapped->SOSetTargets(NumBuffers, ppSOTargets, pOffsets);
}

void APIENTRY ID3D11DeviceContext_Wrapper::DrawAuto() {
	return pWrapped->DrawAuto();
}

void APIENTRY ID3D11DeviceContext_Wrapper::DrawIndexedInstancedIndirect(ID3D11Buffer *pBufferForArgs, UINT AlignedByteOffsetForArgs) {
	return pWrapped->DrawIndexedInstancedIndirect(pBufferForArgs, AlignedByteOffsetForArgs);
}

void APIENTRY ID3D11DeviceContext_Wrapper::DrawInstancedIndirect(ID3D11Buffer *pBufferForArgs, UINT AlignedByteOffsetForArgs) {
	return pWrapped->DrawInstancedIndirect(pBufferForArgs, AlignedByteOffsetForArgs);
}

void APIENTRY ID3D11DeviceContext_Wrapper::Dispatch(UINT ThreadGroupCountX, UINT ThreadGroupCountY, UINT ThreadGroupCountZ) {
	return pWrapped->Dispatch(ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ);
}

void APIENTRY ID3D11DeviceContext_Wrapper::DispatchIndirect(ID3D11Buffer *pBufferForArgs, UINT AlignedByteOffsetForArgs) {
	return pWrapped->DispatchIndirect(pBufferForArgs, AlignedByteOffsetForArgs);
}

void APIENTRY ID3D11DeviceContext_Wrapper::RSSetState(ID3D11RasterizerState *pRasterizerState) {
	return pWrapped->RSSetState(pRasterizerState);
}

void APIENTRY ID3D11DeviceContext_Wrapper::RSSetViewports(UINT NumViewports, const D3D11_VIEWPORT *pViewports) {
	//More magic happens here
	if (NumViewports == 1)
	{
		FLOAT override_x = pViewports->TopLeftX;
		FLOAT override_y = pViewports->TopLeftY;
		FLOAT override_width = pViewports->Width;
		FLOAT override_height = pViewports->Height;
		if (pViewports->Width == RenderInfo::GetRenderWidth() && pViewports->Height == RenderInfo::GetRenderHeight())
		{
			if (scaleViewport)
			{
				//We got a 1080p render viewport, scale that if scaleViewport is true
				override_height = pViewports->Height * RenderInfo::GetHeightScalar();
				override_width = pViewports->Width * RenderInfo::GetWidthScalar();
			}
			else
			{
				scaleViewport = TRUE;
				return pWrapped->RSSetViewports(NumViewports, pViewports); //Don't scale the backbuffer viewport
			}
		}
		else if (pViewports->TopLeftX == 0.0f && pViewports->TopLeftY == 0.0f && pViewports->Width == 960.0f && pViewports->Height == 540.0f)
		{
			//We got the first downscaled rendertarget viewport
			override_height = pViewports->Height * RenderInfo::GetHeightScalar();
			override_width = pViewports->Width * RenderInfo::GetWidthScalar();
		}
		else if (pViewports->TopLeftX == 0.0f && pViewports->TopLeftY == 0.0f && pViewports->Width == 480.0f && pViewports->Height == 270.0f)
		{
			//We got the secondary downscaled rendertarget viewport
			override_height = pViewports->Height * RenderInfo::GetHeightScalar();
			override_width = pViewports->Width * RenderInfo::GetWidthScalar();
		}
		else if (pViewports->TopLeftX == 0.0f && pViewports->TopLeftY == 0.0f && pViewports->Width == 256.0f && pViewports->Height == 146.0f)
		{
			//First bloom texture viewport
			override_height = pViewports->Height * RenderInfo::GetBloomScalar();
			override_width = pViewports->Width * RenderInfo::GetBloomScalar();
		}
		else if (pViewports->TopLeftX == 0.0f && pViewports->TopLeftY == 0.0f && pViewports->Width == 128.0f && pViewports->Height == 72.0f)
		{
			//Second bloom texture viewport
			override_height = pViewports->Height * RenderInfo::GetBloomScalar();
			override_width = pViewports->Width * RenderInfo::GetBloomScalar();
		}
		else if (pViewports->TopLeftX > 0.0f || pViewports->TopLeftY > 0.0f)
		{
			//GUI Viewports
			override_height = pViewports->Height * RenderInfo::GetHeightScalar();
			override_width = pViewports->Width * RenderInfo::GetWidthScalar();
			override_x = pViewports->TopLeftX * RenderInfo::GetWidthScalar();
			override_y = pViewports->TopLeftY * RenderInfo::GetHeightScalar();
		}

		if ((override_height != pViewports->Height) || (override_width != pViewports->Width) || (override_x != pViewports->TopLeftX) || (override_y != pViewports->TopLeftY))
		{
			//Only override the viewport if necessary
			D3D11_VIEWPORT override_viewport;
			override_viewport.Height = override_height;
			override_viewport.Width = override_width;
			override_viewport.MaxDepth = pViewports->MaxDepth;
			override_viewport.MinDepth = pViewports->MinDepth;
			override_viewport.TopLeftX = override_x;
			override_viewport.TopLeftY = override_y;
			return pWrapped->RSSetViewports(NumViewports, &override_viewport);
		}

		return pWrapped->RSSetViewports(NumViewports, pViewports);
	}
	return pWrapped->RSSetViewports(NumViewports, pViewports);
}

void APIENTRY ID3D11DeviceContext_Wrapper::RSSetScissorRects(UINT NumRects, const D3D11_RECT *pRects) {
	return pWrapped->RSSetScissorRects(NumRects, pRects);
}

void APIENTRY ID3D11DeviceContext_Wrapper::CopySubresourceRegion(ID3D11Resource *pDstResource, UINT DstSubresource, UINT DstX, UINT DstY, UINT DstZ, ID3D11Resource *pSrcResource, UINT SrcSubresource, const D3D11_BOX *pSrcBox) {
	return pWrapped->CopySubresourceRegion(pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox);
}

void APIENTRY ID3D11DeviceContext_Wrapper::CopyResource(ID3D11Resource *pDstResource, ID3D11Resource *pSrcResource) {
	return pWrapped->CopyResource(pDstResource, pSrcResource);
}

void APIENTRY ID3D11DeviceContext_Wrapper::UpdateSubresource(ID3D11Resource *pDstResource, UINT DstSubresource, const D3D11_BOX *pDstBox, const void *pSrcData, UINT SrcRowPitch, UINT SrcDepthPitch) {
	return pWrapped->UpdateSubresource(pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);
}

void APIENTRY ID3D11DeviceContext_Wrapper::CopyStructureCount(ID3D11Buffer *pDstBuffer, UINT DstAlignedByteOffset, ID3D11UnorderedAccessView *pSrcView) {
	return pWrapped->CopyStructureCount(pDstBuffer, DstAlignedByteOffset, pSrcView);
}

void APIENTRY ID3D11DeviceContext_Wrapper::ClearRenderTargetView(ID3D11RenderTargetView *pRenderTargetView, const FLOAT ColorRGBA[4]) {
	return pWrapped->ClearRenderTargetView(pRenderTargetView, ColorRGBA);
}

void APIENTRY ID3D11DeviceContext_Wrapper::ClearUnorderedAccessViewUint(ID3D11UnorderedAccessView *pUnorderedAccessView, const UINT Values[4]) {
	return pWrapped->ClearUnorderedAccessViewUint(pUnorderedAccessView, Values);
}

void APIENTRY ID3D11DeviceContext_Wrapper::ClearUnorderedAccessViewFloat(ID3D11UnorderedAccessView *pUnorderedAccessView, const FLOAT Values[4]) {
	return pWrapped->ClearUnorderedAccessViewFloat(pUnorderedAccessView, Values);
}

void APIENTRY ID3D11DeviceContext_Wrapper::ClearDepthStencilView(ID3D11DepthStencilView *pDepthStencilView, UINT ClearFlags, FLOAT Depth, UINT8 Stencil) {
	return pWrapped->ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil);
}

void APIENTRY ID3D11DeviceContext_Wrapper::GenerateMips(ID3D11ShaderResourceView *pShaderResourceView) {
	return pWrapped->GenerateMips(pShaderResourceView);
}

void APIENTRY ID3D11DeviceContext_Wrapper::SetResourceMinLOD(ID3D11Resource *pResource, FLOAT MinLOD) {
	return pWrapped->SetResourceMinLOD(pResource, MinLOD);
}

FLOAT APIENTRY ID3D11DeviceContext_Wrapper::GetResourceMinLOD(ID3D11Resource *pResource) {
	return pWrapped->GetResourceMinLOD(pResource);
}

void APIENTRY ID3D11DeviceContext_Wrapper::ResolveSubresource(ID3D11Resource *pDstResource, UINT DstSubresource, ID3D11Resource *pSrcResource, UINT SrcSubresource, DXGI_FORMAT Format) {
	return pWrapped->ResolveSubresource(pDstResource, DstSubresource, pSrcResource, SrcSubresource, Format);
}

void APIENTRY ID3D11DeviceContext_Wrapper::ExecuteCommandList(ID3D11CommandList *pCommandList, BOOL RestoreContextState) {
	return pWrapped->ExecuteCommandList(pCommandList, RestoreContextState);
}

void APIENTRY ID3D11DeviceContext_Wrapper::HSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews) {
	return pWrapped->HSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void APIENTRY ID3D11DeviceContext_Wrapper::HSSetShader(ID3D11HullShader *pHullShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances) {
	return pWrapped->HSSetShader(pHullShader, ppClassInstances, NumClassInstances);
}

void APIENTRY ID3D11DeviceContext_Wrapper::HSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers) {
	return pWrapped->HSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::HSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers) {
	return pWrapped->HSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::DSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews) {
	return pWrapped->DSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void APIENTRY ID3D11DeviceContext_Wrapper::DSSetShader(ID3D11DomainShader *pDomainShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances) {
	return pWrapped->DSSetShader(pDomainShader, ppClassInstances, NumClassInstances);
}

void APIENTRY ID3D11DeviceContext_Wrapper::DSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers) {
	return pWrapped->DSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::DSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers) {
	return pWrapped->DSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::CSSetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews) {
	return pWrapped->CSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void APIENTRY ID3D11DeviceContext_Wrapper::CSSetUnorderedAccessViews(UINT StartSlot, UINT NumUAVs, ID3D11UnorderedAccessView *const *ppUnorderedAccessViews, const UINT *pUAVInitialCounts) {
	return pWrapped->CSSetUnorderedAccessViews(StartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts);
}

void APIENTRY ID3D11DeviceContext_Wrapper::CSSetShader(ID3D11ComputeShader *pComputeShader, ID3D11ClassInstance *const *ppClassInstances, UINT NumClassInstances) {
	return pWrapped->CSSetShader(pComputeShader, ppClassInstances, NumClassInstances);
}

void APIENTRY ID3D11DeviceContext_Wrapper::CSSetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState *const *ppSamplers) {
	return pWrapped->CSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::CSSetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer *const *ppConstantBuffers) {
	return pWrapped->CSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::VSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppConstantBuffers) {
	return pWrapped->VSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::PSGetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView **ppShaderResourceViews) {
	return pWrapped->PSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void APIENTRY ID3D11DeviceContext_Wrapper::PSGetShader(ID3D11PixelShader **ppPixelShader, ID3D11ClassInstance **ppClassInstances, UINT *pNumClassInstances) {
	return pWrapped->PSGetShader(ppPixelShader, ppClassInstances, pNumClassInstances);
}

void APIENTRY ID3D11DeviceContext_Wrapper::PSGetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState **ppSamplers) {
	return pWrapped->PSGetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::VSGetShader(ID3D11VertexShader **ppVertexShader, ID3D11ClassInstance **ppClassInstances, UINT *pNumClassInstances) {
	return pWrapped->VSGetShader(ppVertexShader, ppClassInstances, pNumClassInstances);
}

void APIENTRY ID3D11DeviceContext_Wrapper::PSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppConstantBuffers) {
	return pWrapped->PSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::IAGetInputLayout(ID3D11InputLayout **ppInputLayout) {
	return pWrapped->IAGetInputLayout(ppInputLayout);
}

void APIENTRY ID3D11DeviceContext_Wrapper::IAGetVertexBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppVertexBuffers, UINT *pStrides, UINT *pOffsets) {
	return pWrapped->IAGetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
}

void APIENTRY ID3D11DeviceContext_Wrapper::IAGetIndexBuffer(ID3D11Buffer **pIndexBuffer, DXGI_FORMAT *Format, UINT *Offset) {
	return pWrapped->IAGetIndexBuffer(pIndexBuffer, Format, Offset);
}

void APIENTRY ID3D11DeviceContext_Wrapper::GSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppConstantBuffers) {
	return pWrapped->GSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::GSGetShader(ID3D11GeometryShader **ppGeometryShader, ID3D11ClassInstance **ppClassInstances, UINT *pNumClassInstances) {
	return pWrapped->GSGetShader(ppGeometryShader, ppClassInstances, pNumClassInstances);
}

void APIENTRY ID3D11DeviceContext_Wrapper::IAGetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY *pTopology) {
	return pWrapped->IAGetPrimitiveTopology(pTopology);
}

void APIENTRY ID3D11DeviceContext_Wrapper::VSGetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView **ppShaderResourceViews) {
	return pWrapped->VSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void APIENTRY ID3D11DeviceContext_Wrapper::VSGetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState **ppSamplers) {
	return pWrapped->VSGetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::GetPredication(ID3D11Predicate **ppPredicate, BOOL *pPredicateValue) {
	return pWrapped->GetPredication(ppPredicate, pPredicateValue);
}

void APIENTRY ID3D11DeviceContext_Wrapper::GSGetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView **ppShaderResourceViews) {
	return pWrapped->GSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void APIENTRY ID3D11DeviceContext_Wrapper::GSGetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState **ppSamplers) {
	return pWrapped->GSGetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::OMGetRenderTargets(UINT NumViews, ID3D11RenderTargetView **ppRenderTargetViews, ID3D11DepthStencilView **ppDepthStencilView) {
	return pWrapped->OMGetRenderTargets(NumViews, ppRenderTargetViews, ppDepthStencilView);
}

void APIENTRY ID3D11DeviceContext_Wrapper::OMGetRenderTargetsAndUnorderedAccessViews(UINT NumRTVs, ID3D11RenderTargetView **ppRenderTargetViews, ID3D11DepthStencilView **ppDepthStencilView, UINT UAVStartSlot, UINT NumUAVs, ID3D11UnorderedAccessView **ppUnorderedAccessViews) {
	return pWrapped->OMGetRenderTargetsAndUnorderedAccessViews(NumRTVs, ppRenderTargetViews, ppDepthStencilView, UAVStartSlot, NumUAVs, ppUnorderedAccessViews);
}

void APIENTRY ID3D11DeviceContext_Wrapper::OMGetBlendState(ID3D11BlendState **ppBlendState, FLOAT BlendFactor[4], UINT *pSampleMask) {
	return pWrapped->OMGetBlendState(ppBlendState, BlendFactor, pSampleMask);
}

void APIENTRY ID3D11DeviceContext_Wrapper::OMGetDepthStencilState(ID3D11DepthStencilState **ppDepthStencilState, UINT *pStencilRef) {
	return pWrapped->OMGetDepthStencilState(ppDepthStencilState, pStencilRef);
}

void APIENTRY ID3D11DeviceContext_Wrapper::SOGetTargets(UINT NumBuffers, ID3D11Buffer **ppSOTargets) {
	return pWrapped->SOGetTargets(NumBuffers, ppSOTargets);
}

void APIENTRY ID3D11DeviceContext_Wrapper::RSGetState(ID3D11RasterizerState **ppRasterizerState) {
	return pWrapped->RSGetState(ppRasterizerState);
}

void APIENTRY ID3D11DeviceContext_Wrapper::RSGetViewports(UINT *pNumViewports, D3D11_VIEWPORT *pViewports) {
	return pWrapped->RSGetViewports(pNumViewports, pViewports);
}

void APIENTRY ID3D11DeviceContext_Wrapper::RSGetScissorRects(UINT *pNumRects, D3D11_RECT *pRects) {
	return pWrapped->RSGetScissorRects(pNumRects, pRects);
}

void APIENTRY ID3D11DeviceContext_Wrapper::HSGetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView **ppShaderResourceViews) {
	return pWrapped->HSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void APIENTRY ID3D11DeviceContext_Wrapper::HSGetShader(ID3D11HullShader **ppHullShader, ID3D11ClassInstance **ppClassInstances, UINT *pNumClassInstances) {
	return pWrapped->HSGetShader(ppHullShader, ppClassInstances, pNumClassInstances);
}

void APIENTRY ID3D11DeviceContext_Wrapper::HSGetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState **ppSamplers) {
	return pWrapped->HSGetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::HSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppConstantBuffers) {
	return pWrapped->HSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::DSGetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView **ppShaderResourceViews) {
	return pWrapped->DSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void APIENTRY ID3D11DeviceContext_Wrapper::DSGetShader(ID3D11DomainShader **ppDomainShader, ID3D11ClassInstance **ppClassInstances, UINT *pNumClassInstances) {
	return pWrapped->DSGetShader(ppDomainShader, ppClassInstances, pNumClassInstances);
}

void APIENTRY ID3D11DeviceContext_Wrapper::DSGetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState **ppSamplers) {
	return pWrapped->DSGetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::DSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppConstantBuffers) {
	return pWrapped->DSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::CSGetShaderResources(UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView **ppShaderResourceViews) {
	return pWrapped->CSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void APIENTRY ID3D11DeviceContext_Wrapper::CSGetUnorderedAccessViews(UINT StartSlot, UINT NumUAVs, ID3D11UnorderedAccessView **ppUnorderedAccessViews) {
	return pWrapped->CSGetUnorderedAccessViews(StartSlot, NumUAVs, ppUnorderedAccessViews);
}

void APIENTRY ID3D11DeviceContext_Wrapper::CSGetShader(ID3D11ComputeShader **ppComputeShader, ID3D11ClassInstance **ppClassInstances, UINT *pNumClassInstances) {
	return pWrapped->CSGetShader(ppComputeShader, ppClassInstances, pNumClassInstances);
}

void APIENTRY ID3D11DeviceContext_Wrapper::CSGetSamplers(UINT StartSlot, UINT NumSamplers, ID3D11SamplerState **ppSamplers) {
	return pWrapped->CSGetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::CSGetConstantBuffers(UINT StartSlot, UINT NumBuffers, ID3D11Buffer **ppConstantBuffers) {
	return pWrapped->CSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void APIENTRY ID3D11DeviceContext_Wrapper::ClearState() {
	return pWrapped->ClearState();
}

void APIENTRY ID3D11DeviceContext_Wrapper::Flush() {
	return pWrapped->Flush();
}

D3D11_DEVICE_CONTEXT_TYPE APIENTRY ID3D11DeviceContext_Wrapper::GetType() {
	return pWrapped->GetType();
}

UINT APIENTRY ID3D11DeviceContext_Wrapper::GetContextFlags() {
	return pWrapped->GetContextFlags();
}

HRESULT APIENTRY ID3D11DeviceContext_Wrapper::FinishCommandList(BOOL RestoreDeferredContextState, ID3D11CommandList **ppCommandList) {
	return pWrapped->FinishCommandList(RestoreDeferredContextState, ppCommandList);
}

void ID3D11DeviceContext_Wrapper::OnPresentCallback() {
	justPresented = true;
}