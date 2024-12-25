#include "Device.h"
#include "DXSampleHelper.h"

Device::~Device()
{
}

Device::Device()
{
	UINT dxgiFactoryFlags = 0;
#if defined(_DEBUG)
	// Enable the debug layer (requires the Graphics Tools "optional feature").
	// NOTE: Enabling the debug layer after device creation will invalidate the active device.
	{
		ComPtr<ID3D12Debug> debugController;
		if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController))))
		{
			debugController->EnableDebugLayer();

			// Enable additional debug layers.
			dxgiFactoryFlags |= DXGI_CREATE_FACTORY_DEBUG;
		}
	}
#endif

	ThrowIfFailed(CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&m_dxgiFactory)));
	UINT adapterIndex = 0;
	bool adapterFound = false;
	while (m_dxgiFactory->EnumAdapters1(adapterIndex, &m_adapter) != DXGI_ERROR_NOT_FOUND)
	{
		DXGI_ADAPTER_DESC1 desc;
		m_adapter->GetDesc1(&desc);
		if ((desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) == 0)
		{
			HRESULT hr = D3D12CreateDevice(m_adapter.Get(), D3D_FEATURE_LEVEL_12_1,
											IID_PPV_ARGS(&m_dxDevice));

			if (SUCCEEDED(hr))
			{
				adapterFound = true;
				break;
			}
		}
		m_adapter = nullptr;
		adapterIndex++;
	}
}