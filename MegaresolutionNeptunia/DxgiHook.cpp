#include "../subhook_static/subhook.h"
#include "DxgiHook.h"
#include "d3d11device_wrapper.h"
#include "d3d11devicecontext_wrapper.h"
#include "idxgiswapchain_wrapper.h"
#include "Log.h"

typedef HRESULT(__stdcall* D3D11CreateDeviceAndSwapChain_t) (IDXGIAdapter* pAdapter, D3D_DRIVER_TYPE driverType, HMODULE software, UINT flags,
	const D3D_FEATURE_LEVEL *pFeatureLevels, UINT featureLevels, UINT sdkVersion, const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc, IDXGISwapChain** ppSwapChain,
	ID3D11Device** ppDevice, D3D_FEATURE_LEVEL* pFeatureLevel, ID3D11DeviceContext** ppImmediateContext);

subhook_t deviceHook;
D3D11CreateDeviceAndSwapChain_t originalCreateDevice;
ID3D11Device_Wrapper* devWrapper;
ID3D11DeviceContext_Wrapper* devContextWrapper;
IDXGISwapChain_Wrapper* swapChainWrapper;

HRESULT __stdcall hooked_D3D11CreateDeviceAndSwapChain(
	IDXGIAdapter* pAdapter,
	D3D_DRIVER_TYPE driverType,
	HMODULE software,
	UINT flags,
	const D3D_FEATURE_LEVEL *pFeatureLevels,
	UINT featureLevels,
	UINT sdkVersion,
	const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
	IDXGISwapChain** ppSwapChain,
	ID3D11Device** ppDevice,
	D3D_FEATURE_LEVEL* pFeatureLevel,
	ID3D11DeviceContext** ppImmediateContext)
{
	//SICKNASTY D3D11CreateDeviceAndSwapChain HOOK WOOP WOOP
	Logger::Log("D3D11CreateDeviceAndSwapChain called!", Logger::Verbosity::Always);
	
	subhook_remove(deviceHook); //Remove hook for this function call
	HRESULT retVal = originalCreateDevice(pAdapter, driverType, software, flags, pFeatureLevels, featureLevels, sdkVersion, pSwapChainDesc, ppSwapChain, ppDevice, pFeatureLevel, ppImmediateContext);
	subhook_install(deviceHook); //Reinstall hook
	swapChainWrapper = new IDXGISwapChain_Wrapper(ppSwapChain); //Wrap the swapchain with our own
	devWrapper = new ID3D11Device_Wrapper(ppDevice, swapChainWrapper); //Wrap the ID3D11Device with our own
	devContextWrapper = new ID3D11DeviceContext_Wrapper(ppImmediateContext, devWrapper); //Wrap the DeviceContext with our own
	return retVal;
}

void HookDxgi()
{
	Logger::Log("Hooking d3d11 D3D11CreateDeviceAndSwapChain", Logger::Verbosity::Always);

	HMODULE d3d11Mod = GetModuleHandle(TEXT("d3d11")); //d3d11 dll
	originalCreateDevice = (D3D11CreateDeviceAndSwapChain_t)GetProcAddress(d3d11Mod, "D3D11CreateDeviceAndSwapChain");
	if (!originalCreateDevice)
	{
		Logger::Log("originalCreateDevice is null! aborting hook!", Logger::Verbosity::Always);
		return;
	}

	deviceHook = subhook_new((void*)originalCreateDevice, (void*)hooked_D3D11CreateDeviceAndSwapChain, (subhook_options_t)0);
	if (!deviceHook)
	{
		Logger::Log("deviceHook is null!", Logger::Verbosity::Always);
		return;
	}

	subhook_install(deviceHook);
	Logger::Log("D3d11CreateDeviceAndSwapChain hooked!", Logger::Verbosity::Always);
}