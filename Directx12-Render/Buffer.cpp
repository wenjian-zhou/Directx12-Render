#include "Buffer.h"

BufferView::BufferView(Buffer const* buffer) :
	m_buffer(buffer),
	m_byteSize(buffer ? buffer->GetByteSize() : 0),
	m_offset(0) {
}

BufferView::BufferView(
	Buffer const* buffer,
	UINT64 offset,
	UINT64 byteSize) :
	m_buffer(buffer),
	m_byteSize(byteSize),
	m_offset(offset) {
}

Buffer::Buffer(Device* device) :
	Resource(device) {
}

Buffer::~Buffer() {
}