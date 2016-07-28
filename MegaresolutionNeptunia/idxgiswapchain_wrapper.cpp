// wrapper for IDXGISwapChain in dxgi.h
// generated using wrapper_gen11.rb

#include "idxgiswapchain_wrapper.h"
#include "Log.h"
#include <string>
#include <sstream>
using namespace std;

IDXGISwapChain_Wrapper::IDXGISwapChain_Wrapper(IDXGISwapChain **ppIDXGISwapChain) {
	pWrapped = *ppIDXGISwapChain;
	*ppIDXGISwapChain = this;
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::QueryInterface(REFIID riid, void **ppvObject) {
	return pWrapped->QueryInterface(riid, ppvObject);
}

ULONG APIENTRY IDXGISwapChain_Wrapper::AddRef() {
	return pWrapped->AddRef();
}

ULONG APIENTRY IDXGISwapChain_Wrapper::Release() {
	return pWrapped->Release();
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::SetPrivateData(REFGUID Name, UINT DataSize, const void *pData) {
	return pWrapped->SetPrivateData(Name, DataSize, pData);
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::SetPrivateDataInterface(REFGUID Name, const IUnknown *pUnknown) {
	return pWrapped->SetPrivateDataInterface(Name, pUnknown);
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::GetPrivateData(REFGUID Name, UINT *pDataSize, void *pData) {
	return pWrapped->GetPrivateData(Name, pDataSize, pData);
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::GetParent(REFIID riid, void **ppParent) {
	return pWrapped->GetParent(riid, ppParent);
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::GetDevice(REFIID riid, void **ppDevice) {
	return pWrapped->GetDevice(riid, ppDevice);
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::Present(UINT SyncInterval, UINT Flags) {
	if (presentCallback) presentCallback();
	return pWrapped->Present(SyncInterval, Flags);
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::GetBuffer(UINT Buffer, REFIID riid, void **ppSurface) {
	if (Buffer == 0) //Backbuffer
	{
		HRESULT retVal = pWrapped->GetBuffer(Buffer, riid, ppSurface);
		pBackbufferTex = (ID3D11Texture2D*)(*ppSurface);
		if (Logger::CanLog(Logger::Verbosity::Normal))
		{
			stringstream sS;
			sS << "GetBuffer backBuffer, replacing currently stored surface pointer with " << (pBackbufferTex);
			Logger::Log(sS.str(), Logger::Verbosity::Normal);
		}
		return retVal;
	}
	return pWrapped->GetBuffer(Buffer, riid, ppSurface);
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::SetFullscreenState(BOOL Fullscreen, IDXGIOutput *pTarget) {
	return pWrapped->SetFullscreenState(Fullscreen, pTarget);
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::GetFullscreenState(BOOL *pFullscreen, IDXGIOutput **ppTarget) {
	return pWrapped->GetFullscreenState(pFullscreen, ppTarget);
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::GetDesc(DXGI_SWAP_CHAIN_DESC *pDesc) {
	return pWrapped->GetDesc(pDesc);
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::ResizeBuffers(UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags) {
	return pWrapped->ResizeBuffers(BufferCount, Width, Height, NewFormat, SwapChainFlags);
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::ResizeTarget(const DXGI_MODE_DESC *pNewTargetParameters) {
	return pWrapped->ResizeTarget(pNewTargetParameters);
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::GetContainingOutput(IDXGIOutput **ppOutput) {
	return pWrapped->GetContainingOutput(ppOutput);
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::GetFrameStatistics(DXGI_FRAME_STATISTICS *pStats) {
	return pWrapped->GetFrameStatistics(pStats);
}

HRESULT APIENTRY IDXGISwapChain_Wrapper::GetLastPresentCount(UINT *pLastPresentCount) {
	return pWrapped->GetLastPresentCount(pLastPresentCount);
}