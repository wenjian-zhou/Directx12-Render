#pragma once
#include "Buffer.h"

class DefaultBuffer : public Buffer
{
private:
	UINT64 m_byteSize;
	D3D12_RESOURCE_STATES m_initState;
	ComPtr<ID3D12Resource> m_resource;

public:
	ID3D12Resource* GetResource() const override { return m_resource.Get(); }
	D3D12_GPU_VIRTUAL_ADDRESS GetAddress() const override { return m_resource->GetGPUVirtualAddress(); }
	UINT64 GetByteSize() const override { return m_byteSize; }
	DefaultBuffer(
		Device* device,
		UINT64 byteSize,
		D3D12_RESOURCE_STATES initState = D3D12_RESOURCE_STATE_COMMON);
	~DefaultBuffer();
	D3D12_RESOURCE_STATES GetInitState() const override { return m_initState; }

	DefaultBuffer(DefaultBuffer&&) = default;
	DefaultBuffer(DefaultBuffer const&) = delete;
};