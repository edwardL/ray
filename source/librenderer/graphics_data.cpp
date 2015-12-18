// +----------------------------------------------------------------------
// | Project : ray.
// | All rights reserved.
// +----------------------------------------------------------------------
// | Copyright (c) 2013-2015.
// +----------------------------------------------------------------------
// | * Redistribution and use of this software in source and binary forms,
// |   with or without modification, are permitted provided that the following
// |   conditions are met:
// |
// | * Redistributions of source code must retain the above
// |   copyright notice, this list of conditions and the
// |   following disclaimer.
// |
// | * Redistributions in binary form must reproduce the above
// |   copyright notice, this list of conditions and the
// |   following disclaimer in the documentation and/or other
// |   materials provided with the distribution.
// |
// | * Neither the name of the ray team, nor the names of its
// |   contributors may be used to endorse or promote products
// |   derived from this software without specific prior
// |   written permission of the ray team.
// |
// | THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// | "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// | LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// | A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// | OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// | SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// | LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// | DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// | THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// | (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// | OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// +----------------------------------------------------------------------
#include <ray/graphics_data.h>

_NAME_BEGIN

__ImplementSubInterface(GraphicsData, GraphicsResource, "GraphicsData")

GraphicsDataDesc::GraphicsDataDesc() noexcept
	: _data(nullptr)
	, _dataSize(0)
	, _usage(UsageFlags::MAP_READ_BIT | UsageFlags::IMMUTABLE_STORAGE)
	, _type(GraphicsStream::VBO)
{
}

GraphicsDataDesc::~GraphicsDataDesc() noexcept
{
}

void 
GraphicsDataDesc::setUsage(std::uint32_t usage) noexcept
{
	_usage = usage;
}

std::uint32_t 
GraphicsDataDesc::getUsage() const noexcept
{
	return _usage;
}

void
GraphicsDataDesc::setType(GraphicsStream type) noexcept
{
	_type = type;
}

GraphicsStream 
GraphicsDataDesc::getType() const noexcept
{
	return _type;
}

void 
GraphicsDataDesc::setStream(std::uint8_t* data) noexcept
{
	_data = data;
}

std::uint8_t* 
GraphicsDataDesc::getStream() const noexcept
{
	return _data;
}

void 
GraphicsDataDesc::setStreamSize(std::uint32_t size) noexcept
{
	_dataSize = size;
}

std::uint32_t 
GraphicsDataDesc::getStreamSize() const noexcept
{
	return _dataSize;
}

GraphicsData::GraphicsData() noexcept
{
}

GraphicsData::~GraphicsData() noexcept
{
}

_NAME_END