#pragma once
#include "stdafx.h"

using Microsoft::WRL::ComPtr;
class Device
{
	ComPtr<IDXGIAdapter1> m_adapter;
	ComPtr<ID3D12Device5> m_dxDevice;
	ComPtr<IDXGIFactory4> m_dxgiFactory;

public:
	IDXGIAdapter1* Adapter() const { return m_adapter.Get(); }
	ID3D12Device5* DxDevice() const { return m_dxDevice.Get(); }
	IDXGIFactory4* DxgiFactory() const { return m_dxgiFactory.Get(); }
	Device();
	~Device();
};