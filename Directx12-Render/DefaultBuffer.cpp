#include "DefaultBuffer.h"
#include "DXSampleHelper.h"

DefaultBuffer::DefaultBuffer(
	Device* device,
	UINT64 byteSize,
	D3D12_RESOURCE_STATES initState) :
	Buffer(device),
	m_initState(initState),
	m_byteSize(byteSize)
{
	auto prop = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT);
	auto buffer = CD3DX12_RESOURCE_DESC::Buffer(byteSize, D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS);
	ThrowIfFailed(device->DxDevice()->CreateCommittedResource(
		&prop,
		D3D12_HEAP_FLAG_NONE,
		&buffer,
		initState,
		nullptr,
		IID_PPV_ARGS(&m_resource)));
}

DefaultBuffer::~DefaultBuffer()
{
}