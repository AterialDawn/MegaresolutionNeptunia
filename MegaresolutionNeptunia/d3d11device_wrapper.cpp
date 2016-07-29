// wrapper for ID3D11Device in d3d11.h
// generated using wrapper_gen11.rb

//Borrowed from https://github.com/PeterTh/gedosato/blob/master/source/d3d11/d3d11dev.cpp on 07/16/2016 d58126e
//SLIGHT MODIFICATIONS TO NAMING

#include "d3d11device_wrapper.h"
#include "Config.h"
#include "Log.h"
#include <d3dcommon.h>
#include "RenderInfo.h"
#include <sstream>

using namespace std;

ID3D11Device_Wrapper::ID3D11Device_Wrapper(ID3D11Device **ppID3D11Device, IDXGISwapChain_Wrapper* swapWrap) {
	Logger::Log("ID3D11Device_Wrapper created", Logger::Verbosity::Normal);
	pWrapped = *ppID3D11Device;
	pSwapChainWrapper = swapWrap;
	*ppID3D11Device = this;
}

HRESULT APIENTRY ID3D11Device_Wrapper::QueryInterface(REFIID riid, void **ppvObject) {
	return pWrapped->QueryInterface(riid, ppvObject);
}

ULONG APIENTRY ID3D11Device_Wrapper::AddRef() {
	return pWrapped->AddRef();
}

ULONG APIENTRY ID3D11Device_Wrapper::Release() {
	return pWrapped->Release();
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateBuffer(const D3D11_BUFFER_DESC *pDesc, const D3D11_SUBRESOURCE_DATA *pInitialData, ID3D11Buffer **ppBuffer) {
	return pWrapped->CreateBuffer(pDesc, pInitialData, ppBuffer);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateTexture1D(const D3D11_TEXTURE1D_DESC *pDesc, const D3D11_SUBRESOURCE_DATA *pInitialData, ID3D11Texture1D **ppTexture1D) {
	return pWrapped->CreateTexture1D(pDesc, pInitialData, ppTexture1D);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateTexture2D(const D3D11_TEXTURE2D_DESC *pDesc, const D3D11_SUBRESOURCE_DATA *pInitialData, ID3D11Texture2D **ppTexture2D) {
#if _DEBUG
	//Log some useful texture creation information on a debug build only
	if (pDesc->BindFlags & D3D11_BIND_RENDER_TARGET)
	{
		stringstream message;
		message << "ID3D11Device::CreateTexture2D RENDERTARGET TEXTURE, ";
		message << "width = " << pDesc->Width << ", ";
		message << "height = " << pDesc->Height << ", ";
		message << "format = " << pDesc->Format;
		Logger::Log(message.str(), Logger::Verbosity::Debug);
	}
	else if (pDesc->Width == static_cast<UINT>(RenderInfo::GetRenderWidth()) && pDesc->Height == static_cast<UINT>(RenderInfo::GetRenderHeight()))
	{
		std::stringstream message;
		message << "ID3D11Device::CreateTexture2D RenderSize TEXTURE, ";
		message << "width = " << pDesc->Width << ", ";
		message << "height = " << pDesc->Height << ", ";
		message << "format = " << pDesc->Format;
		Logger::Log(message.str(), Logger::Verbosity::Debug);
	}
#endif
	UINT override_width = pDesc->Width;
	UINT override_height = pDesc->Height;

	//Here's where the magic happens.
	//Quite a hefty if check!
	//Render textures are 1920x1080, 1 of 3 formats, are not D3D11_USAGE_DYNAMIC, and do not have any initial data
	if (pDesc->Width == static_cast<UINT>(RenderInfo::GetRenderWidth()) && pDesc->Height == static_cast<UINT>(RenderInfo::GetRenderHeight()) && (pDesc->Format == DXGI_FORMAT_R8G8B8A8_UNORM || pDesc->Format == DXGI_FORMAT_D32_FLOAT || pDesc->Format == DXGI_FORMAT_R32_FLOAT) && pDesc->Usage != D3D11_USAGE_DYNAMIC && pInitialData == nullptr)
	{
#if _DEBUG
		if (pDesc->Format == DXGI_FORMAT_D32_FLOAT)
		{
			Logger::Log("Got a depth render texture.", Logger::Verbosity::Debug);
		}
		else if (pDesc->Format == DXGI_FORMAT_R32_FLOAT)
		{
			Logger::Log("Got a R32_FLOAT (effects) texture.", Logger::Verbosity::Debug);
		}
		else
		{
			Logger::Log("Got a main render texture.", Logger::Verbosity::Debug);
		}
#endif
		//Main render texture
		override_width = static_cast<UINT>(pDesc->Width * RenderInfo::GetWidthScalar());
		override_height = static_cast<UINT>(pDesc->Height * RenderInfo::GetHeightScalar());
	}
	else if (pDesc->Width == 960 && pDesc->Height == 540 && pDesc->Format == DXGI_FORMAT_R8G8B8A8_UNORM && pDesc->BindFlags == (D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET))
	{
		Logger::Log("Got the first downscaled render texture.", Logger::Verbosity::Normal);
		//First downscaled texture used for the bloom effect
		override_width = static_cast<UINT>(pDesc->Width * RenderInfo::GetWidthScalar());
		override_height = static_cast<UINT>(pDesc->Height * RenderInfo::GetHeightScalar());
	}
	else if (pDesc->Width == 480 && pDesc->Height == 270 && pDesc->Format == DXGI_FORMAT_R8G8B8A8_UNORM && pDesc->BindFlags == (D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET))
	{
		Logger::Log("Got the second downscaled render texture.", Logger::Verbosity::Normal);
		//We got the secondary render texture used for the bloom effect
		override_width = static_cast<UINT>(pDesc->Width * RenderInfo::GetWidthScalar());
		override_height = static_cast<UINT>(pDesc->Height * RenderInfo::GetHeightScalar());
	}
	else if (pDesc->Width == 256 && pDesc->Height == 146 && pDesc->Format == DXGI_FORMAT_R32G32B32A32_FLOAT)
	{
		Logger::Log("Got a primary bloom texture", Logger::Verbosity::Normal);
		//We got the primary bloom texture
		override_width = static_cast<UINT>(pDesc->Width * RenderInfo::GetBloomScalar());
		override_height = static_cast<UINT>(pDesc->Height * RenderInfo::GetBloomScalar());
	}
	else if (pDesc->Width == 128 && pDesc->Height == 72 && pDesc->Format == DXGI_FORMAT_R32G32B32A32_FLOAT)
	{
		Logger::Log("Got a secondary bloom texture", Logger::Verbosity::Normal);
		//We got the secondary bloom texture
		override_width = static_cast<UINT>(pDesc->Width * RenderInfo::GetBloomScalar());
		override_height = static_cast<UINT>(pDesc->Height * RenderInfo::GetBloomScalar());
	}
	if (override_width != pDesc->Width || override_height != pDesc->Height)
	{
		//Only override texture if necessary
		D3D11_TEXTURE2D_DESC overridden_desc;
		overridden_desc.ArraySize = pDesc->ArraySize;
		overridden_desc.BindFlags = pDesc->BindFlags;
		overridden_desc.CPUAccessFlags = pDesc->CPUAccessFlags;
		overridden_desc.Format = pDesc->Format;
		overridden_desc.Height = override_height;
		overridden_desc.MipLevels = pDesc->MipLevels;
		overridden_desc.MiscFlags = pDesc->MiscFlags;
		overridden_desc.SampleDesc = pDesc->SampleDesc;
		overridden_desc.Usage = pDesc->Usage;
		overridden_desc.Width = override_width;

#if _DEBUG
		std::stringstream sS;
		sS << "OverrideWidth = " << override_width;
		sS << ", OverrideHeight = " << override_height;
		Logger::Log(sS.str(), Logger::Verbosity::Debug);
#endif

		return pWrapped->CreateTexture2D(&overridden_desc, pInitialData, ppTexture2D);
	}
	return pWrapped->CreateTexture2D(pDesc, pInitialData, ppTexture2D);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateTexture3D(const D3D11_TEXTURE3D_DESC *pDesc, const D3D11_SUBRESOURCE_DATA *pInitialData, ID3D11Texture3D **ppTexture3D) {
	return pWrapped->CreateTexture3D(pDesc, pInitialData, ppTexture3D);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateShaderResourceView(ID3D11Resource *pResource, const D3D11_SHADER_RESOURCE_VIEW_DESC *pDesc, ID3D11ShaderResourceView **ppSRView) {
	return pWrapped->CreateShaderResourceView(pResource, pDesc, ppSRView);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateUnorderedAccessView(ID3D11Resource *pResource, const D3D11_UNORDERED_ACCESS_VIEW_DESC *pDesc, ID3D11UnorderedAccessView **ppUAView) {
	return pWrapped->CreateUnorderedAccessView(pResource, pDesc, ppUAView);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateRenderTargetView(ID3D11Resource *pResource, const D3D11_RENDER_TARGET_VIEW_DESC *pDesc, ID3D11RenderTargetView **ppRTView) {
	if (pResource == pSwapChainWrapper->pBackbufferTex)
	{
		//Got the backbuffer rendertarget that we use to determine if the viewport should be scaled or not
		Logger::Log("Got the backbuffer RenderTargetView", Logger::Verbosity::Normal);
		HRESULT retVal = pWrapped->CreateRenderTargetView(pResource, pDesc, ppRTView);
		pBackBufferRenderTarget = *ppRTView;
		return retVal;
	}
	return pWrapped->CreateRenderTargetView(pResource, pDesc, ppRTView);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateDepthStencilView(ID3D11Resource *pResource, const D3D11_DEPTH_STENCIL_VIEW_DESC *pDesc, ID3D11DepthStencilView **ppDepthStencilView) {
	return pWrapped->CreateDepthStencilView(pResource, pDesc, ppDepthStencilView);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC *pInputElementDescs, UINT NumElements, const void *pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength, ID3D11InputLayout **ppInputLayout) {
	return pWrapped->CreateInputLayout(pInputElementDescs, NumElements, pShaderBytecodeWithInputSignature, BytecodeLength, ppInputLayout);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateVertexShader(const void *pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage *pClassLinkage, ID3D11VertexShader **ppVertexShader) {
	return pWrapped->CreateVertexShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppVertexShader);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateGeometryShader(const void *pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage *pClassLinkage, ID3D11GeometryShader **ppGeometryShader) {
	return pWrapped->CreateGeometryShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppGeometryShader);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateGeometryShaderWithStreamOutput(const void *pShaderBytecode, SIZE_T BytecodeLength, const D3D11_SO_DECLARATION_ENTRY *pSODeclaration, UINT NumEntries, const UINT *pBufferStrides, UINT NumStrides, UINT RasterizedStream, ID3D11ClassLinkage *pClassLinkage, ID3D11GeometryShader **ppGeometryShader) {
	return pWrapped->CreateGeometryShaderWithStreamOutput(pShaderBytecode, BytecodeLength, pSODeclaration, NumEntries, pBufferStrides, NumStrides, RasterizedStream, pClassLinkage, ppGeometryShader);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreatePixelShader(const void *pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage *pClassLinkage, ID3D11PixelShader **ppPixelShader) {
	return pWrapped->CreatePixelShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppPixelShader);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateHullShader(const void *pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage *pClassLinkage, ID3D11HullShader **ppHullShader) {
	return pWrapped->CreateHullShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppHullShader);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateDomainShader(const void *pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage *pClassLinkage, ID3D11DomainShader **ppDomainShader) {
	return pWrapped->CreateDomainShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppDomainShader);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateComputeShader(const void *pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage *pClassLinkage, ID3D11ComputeShader **ppComputeShader) {
	return pWrapped->CreateComputeShader(pShaderBytecode, BytecodeLength, pClassLinkage, ppComputeShader);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateClassLinkage(ID3D11ClassLinkage **ppLinkage) {
	return pWrapped->CreateClassLinkage(ppLinkage);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateBlendState(const D3D11_BLEND_DESC *pBlendStateDesc, ID3D11BlendState **ppBlendState) {
	return pWrapped->CreateBlendState(pBlendStateDesc, ppBlendState);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateDepthStencilState(const D3D11_DEPTH_STENCIL_DESC *pDepthStencilDesc, ID3D11DepthStencilState **ppDepthStencilState) {
	return pWrapped->CreateDepthStencilState(pDepthStencilDesc, ppDepthStencilState);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateRasterizerState(const D3D11_RASTERIZER_DESC *pRasterizerDesc, ID3D11RasterizerState **ppRasterizerState) {
	return pWrapped->CreateRasterizerState(pRasterizerDesc, ppRasterizerState);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateSamplerState(const D3D11_SAMPLER_DESC *pSamplerDesc, ID3D11SamplerState **ppSamplerState) {
	return pWrapped->CreateSamplerState(pSamplerDesc, ppSamplerState);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateQuery(const D3D11_QUERY_DESC *pQueryDesc, ID3D11Query **ppQuery) {
	return pWrapped->CreateQuery(pQueryDesc, ppQuery);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreatePredicate(const D3D11_QUERY_DESC *pPredicateDesc, ID3D11Predicate **ppPredicate) {
	return pWrapped->CreatePredicate(pPredicateDesc, ppPredicate);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateCounter(const D3D11_COUNTER_DESC *pCounterDesc, ID3D11Counter **ppCounter) {
	return pWrapped->CreateCounter(pCounterDesc, ppCounter);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CreateDeferredContext(UINT ContextFlags, ID3D11DeviceContext **ppDeferredContext) {
	return pWrapped->CreateDeferredContext(ContextFlags, ppDeferredContext);
}

HRESULT APIENTRY ID3D11Device_Wrapper::OpenSharedResource(HANDLE hResource, REFIID ReturnedInterface, void **ppResource) {
	return pWrapped->OpenSharedResource(hResource, ReturnedInterface, ppResource);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CheckFormatSupport(DXGI_FORMAT Format, UINT *pFormatSupport) {
	return pWrapped->CheckFormatSupport(Format, pFormatSupport);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CheckMultisampleQualityLevels(DXGI_FORMAT Format, UINT SampleCount, UINT *pNumQualityLevels) {
	return pWrapped->CheckMultisampleQualityLevels(Format, SampleCount, pNumQualityLevels);
}

void APIENTRY ID3D11Device_Wrapper::CheckCounterInfo(D3D11_COUNTER_INFO *pCounterInfo) {
	return pWrapped->CheckCounterInfo(pCounterInfo);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CheckCounter(const D3D11_COUNTER_DESC *pDesc, D3D11_COUNTER_TYPE *pType, UINT *pActiveCounters, LPSTR szName, UINT *pNameLength, LPSTR szUnits, UINT *pUnitsLength, LPSTR szDescription, UINT *pDescriptionLength) {
	return pWrapped->CheckCounter(pDesc, pType, pActiveCounters, szName, pNameLength, szUnits, pUnitsLength, szDescription, pDescriptionLength);
}

HRESULT APIENTRY ID3D11Device_Wrapper::CheckFeatureSupport(D3D11_FEATURE Feature, void *pFeatureSupportData, UINT FeatureSupportDataSize) {
	return pWrapped->CheckFeatureSupport(Feature, pFeatureSupportData, FeatureSupportDataSize);
}

HRESULT APIENTRY ID3D11Device_Wrapper::GetPrivateData(REFGUID guid, UINT *pDataSize, void *pData) {
	return pWrapped->GetPrivateData(guid, pDataSize, pData);
}

HRESULT APIENTRY ID3D11Device_Wrapper::SetPrivateData(REFGUID guid, UINT DataSize, const void *pData) {
	return pWrapped->SetPrivateData(guid, DataSize, pData);
}

HRESULT APIENTRY ID3D11Device_Wrapper::SetPrivateDataInterface(REFGUID guid, const IUnknown *pData) {
	return pWrapped->SetPrivateDataInterface(guid, pData);
}

D3D_FEATURE_LEVEL APIENTRY ID3D11Device_Wrapper::GetFeatureLevel() {
	return pWrapped->GetFeatureLevel();
}

UINT APIENTRY ID3D11Device_Wrapper::GetCreationFlags() {
	return pWrapped->GetCreationFlags();
}

HRESULT APIENTRY ID3D11Device_Wrapper::GetDeviceRemovedReason() {
	return pWrapped->GetDeviceRemovedReason();
}

void APIENTRY ID3D11Device_Wrapper::GetImmediateContext(ID3D11DeviceContext **ppImmediateContext) {
	return pWrapped->GetImmediateContext(ppImmediateContext);
}

HRESULT APIENTRY ID3D11Device_Wrapper::SetExceptionMode(UINT RaiseFlags) {
	return pWrapped->SetExceptionMode(RaiseFlags);
}

UINT APIENTRY ID3D11Device_Wrapper::GetExceptionMode() {
	return pWrapped->GetExceptionMode();
}