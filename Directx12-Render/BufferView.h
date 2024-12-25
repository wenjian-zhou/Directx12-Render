#pragma once
#include "stdafx.h"

class Buffer;

struct BufferView
{
	Buffer const* m_buffer = nullptr;
	UINT64 m_offset = 0;
	UINT64 m_byteSize = 0;
	BufferView() {}
	BufferView(Buffer const* buffer);
	BufferView(Buffer const* buffer, UINT64 offset, UINT64 byteSize);
	bool operator==(BufferView const& a) const
	{
		return memcmp(this, &a, sizeof(BufferView)) == 0;
	}
	bool operator!=(BufferView const& a) const
	{
		return !operator==(a);
	}
};