// +----------------------------------------------------------------------
// | Project : ray.
// | All rights reserved.
// +----------------------------------------------------------------------
// | Copyright (c) 2013-2014.
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
#ifndef _H_GRAPHICS_TEXTURE_H_
#define _H_GRAPHICS_TEXTURE_H_

#include <ray/graphics_resource.h>

_NAME_BEGIN

class EXPORT GraphicsTextureDesc final
{
public:
	GraphicsTextureDesc() noexcept;
	~GraphicsTextureDesc() noexcept;

	void setWidth(std::uint32_t w) noexcept;
	void setHeight(std::uint32_t h) noexcept;
	void setDepth(std::uint32_t d) noexcept;
	void setSize(std::uint32_t w, std::uint32_t h, std::uint32_t depth = 0) noexcept;

	void setMipNums(std::uint32_t nums) noexcept;
	void setMipBase(std::uint32_t minLevel) noexcept;

	void setLayerNums(std::uint32_t layer) noexcept;
	void setLayerBase(std::uint32_t minLayer) noexcept;

	void setStream(const void* data) noexcept;
	void setStreamSize(std::size_t size) noexcept;

	void setTexFormat(GraphicsFormat format) noexcept;
	void setTexDim(GraphicsTextureDim mapping) noexcept;
	void setTexTiling(GraphicsImageTiling tiling) noexcept;
	void setTexUsage(GraphicsViewUsageFlags flags) noexcept;

	void setSamplerWrap(GraphicsSamplerWrap wrap) noexcept;
	void setSamplerMinFilter(GraphicsSamplerFilter filter) noexcept;
	void setSamplerMagFilter(GraphicsSamplerFilter filter) noexcept;
	void setSamplerFilter(GraphicsSamplerFilter minFilter, GraphicsSamplerFilter magFilter) noexcept;
	void setSamplerAnis(GraphicsSamplerAnis anis) noexcept;

	void setMultisample(bool enable) noexcept;

	GraphicsFormat getTexFormat()  const noexcept;
	GraphicsTextureDim getTexDim() const noexcept;
	GraphicsImageTiling getTexTiling() const noexcept;
	GraphicsViewUsageFlags getTexUsage() const noexcept;

	GraphicsSamplerWrap getSamplerWrap() const noexcept;
	GraphicsSamplerFilter getSamplerMinFilter() const noexcept;
	GraphicsSamplerFilter getSamplerMagFilter() const noexcept;
	GraphicsSamplerAnis getSamplerAnis() const noexcept;

	std::uint32_t getWidth() const noexcept;
	std::uint32_t getHeight() const noexcept;
	std::uint32_t getDepth()  const noexcept;

	std::uint32_t getMipBase() const noexcept;
	std::uint32_t getMipNums() const noexcept;

	std::uint32_t getLayerBase() const noexcept;
	std::uint32_t getLayerNums() const noexcept;

	bool isMultiSample() const noexcept;

	const void* getStream() const noexcept;
	std::size_t getStreamSize() const noexcept;

private:
	std::string _name;

	bool _multisample;

	uint3 _size;

	std::uint32_t _layerBase;
	std::uint32_t _layer;

	std::uint32_t _mipLevel;
	std::uint32_t _mipBase;

	GraphicsFormat _format;
	GraphicsTextureDim _dim;
	GraphicsSamplerFilter _filterMin;
	GraphicsSamplerFilter _filterMag;
	GraphicsSamplerWrap _wrap;
	GraphicsSamplerAnis _anis;
	GraphicsImageTiling _tiling;
	GraphicsViewUsageFlags _textureUsage;

	const void* _data;
	std::size_t _dataSize;
};

class EXPORT GraphicsTexture : public GraphicsResource
{
	__DeclareSubInterface(GraphicsTexture, GraphicsResource)
public:
	GraphicsTexture() noexcept;
	virtual ~GraphicsTexture() noexcept;

	virtual bool map(std::uint32_t x, std::uint32_t y, std::uint32_t w, std::uint32_t h, std::uint32_t mipLevel, void** data) noexcept = 0;
	virtual void unmap() noexcept = 0;

	virtual const GraphicsTextureDesc& getGraphicsTextureDesc() const noexcept = 0;

private:
	GraphicsTexture(const GraphicsTexture&) noexcept = delete;
	GraphicsTexture& operator=(const GraphicsTexture&) noexcept = delete;
};

_NAME_END

#endif