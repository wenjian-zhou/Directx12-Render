#pragma once
#include "Buffer.h"

class ReadbackBuffer final : public Buffer
{
private:
	ComPtr<ID3D12Resource> m_resource;
	UINT64 m_byteSize;

public:
	ID3D12Resource* GetResource() const override { return m_resource.Get(); }
	D3D12_GPU_VIRTUAL_ADDRESS GetAddress() const override { return m_resource->GetGPUVirtualAddress(); }
	UINT64 GetByteSize() const override { return m_byteSize; }
	ReadbackBuffer(Device* device, UINT64 byteSize);
	~ReadbackBuffer();
	void CopyData(UINT64 offset, std::span<vbyte> data) const;
	D3D12_RESOURCE_STATES GetInitState() const override {
		return D3D12_RESOURCE_STATE_COPY_DEST;
	}
	ReadbackBuffer(ReadbackBuffer&&) = default;
	ReadbackBuffer(ReadbackBuffer const&) = delete;
};