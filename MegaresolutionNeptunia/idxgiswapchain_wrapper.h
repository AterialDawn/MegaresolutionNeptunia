// wrapper for IDXGISwapChain in dxgi.h
// generated using wrapper_gen11.rb

//Borrowed from https://raw.githubusercontent.com/PeterTh/gedosato/d2157ae0f0ecab3af4bb1caf597b287c8a393db8/include/dxgi/dxgiswapchain.h 07/24/2016
//SLIGHT MODIFICATIONS TO NAMING

#pragma once

#include "dxgi.h"
#include <d3d11.h>
#include <functional>

class RSManagerDX11;

interface IDXGISwapChain_Wrapper : public IDXGISwapChain {
	IDXGISwapChain *pWrapped = NULL;
	ID3D11Texture2D* pBackbufferTex = nullptr;
	std::function<void()> presentCallback = nullptr;

public:
	IDXGISwapChain_Wrapper(IDXGISwapChain **ppIDXGISwapChain);

	// original interface

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject);
	virtual ULONG STDMETHODCALLTYPE AddRef(void);
	virtual ULONG STDMETHODCALLTYPE Release(void);

	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID Name, UINT DataSize, const void *pData);
	virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(REFGUID Name, const IUnknown *pUnknown);
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID Name, UINT *pDataSize, void *pData);
	virtual HRESULT STDMETHODCALLTYPE GetParent(REFIID riid, void **ppParent);

	virtual HRESULT STDMETHODCALLTYPE GetDevice(REFIID riid, void **ppDevice);

	virtual HRESULT STDMETHODCALLTYPE Present(UINT SyncInterval, UINT Flags);
	virtual HRESULT STDMETHODCALLTYPE GetBuffer(UINT Buffer, REFIID riid, void **ppSurface);
	virtual HRESULT STDMETHODCALLTYPE SetFullscreenState(BOOL Fullscreen, IDXGIOutput *pTarget);
	virtual HRESULT STDMETHODCALLTYPE GetFullscreenState(BOOL *pFullscreen, IDXGIOutput **ppTarget);
	virtual HRESULT STDMETHODCALLTYPE GetDesc(DXGI_SWAP_CHAIN_DESC *pDesc);
	virtual HRESULT STDMETHODCALLTYPE ResizeBuffers(UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);
	virtual HRESULT STDMETHODCALLTYPE ResizeTarget(const DXGI_MODE_DESC *pNewTargetParameters);
	virtual HRESULT STDMETHODCALLTYPE GetContainingOutput(IDXGIOutput **ppOutput);
	virtual HRESULT STDMETHODCALLTYPE GetFrameStatistics(DXGI_FRAME_STATISTICS *pStats);
	virtual HRESULT STDMETHODCALLTYPE GetLastPresentCount(UINT *pLastPresentCount);

};
