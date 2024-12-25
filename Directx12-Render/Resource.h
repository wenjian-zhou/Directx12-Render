#pragma once
#include "stdafx.h"
#include "Device.h"

using Microsoft::WRL::ComPtr;

class Resource
{
protected:
	Device* m_device;

public:
	Device* GetDevice() const { return m_device; };
	Resource(Device* device) : m_device(device) {}
	Resource(Resource&&) = default;
	Resource(Resource const&) = delete;
	virtual ~Resource() = default;
	virtual ID3D12Resource* GetResource() const { return nullptr; }
	virtual D3D12_RESOURCE_STATES GetInitState() const { return D3D12_RESOURCE_STATE_COMMON; }
};