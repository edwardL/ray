// +----------------------------------------------------------------------
// | Project : ray.
// | All rights reserved.
// +----------------------------------------------------------------------
// | Copyright (c) 2013-2017.
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
#ifndef _H_WGL_SWAPCHAIN_H_
#define _H_WGL_SWAPCHAIN_H_

#include "ogl_types.h"

_NAME_BEGIN

class WGLSwapchain : public GraphicsSwapchain
{
	__DeclareSubClass(WGLSwapchain, GraphicsSwapchain)
public:
	WGLSwapchain() noexcept;
	WGLSwapchain(GLuint major, GLuint minor) noexcept;
	virtual ~WGLSwapchain() noexcept;

	bool setup(const GraphicsSwapchainDesc& swapchainDesc) noexcept;
	void close() noexcept;

	void setActive(bool active) noexcept;
	bool getActive() const noexcept;

	void setWindowResolution(std::uint32_t w, std::uint32_t h) noexcept;
	void getWindowResolution(std::uint32_t& w, std::uint32_t& h) const noexcept;

	void setDevice(const GraphicsDevicePtr& device) noexcept;
	GraphicsDevicePtr getDevice() noexcept;

	void setSwapInterval(GraphicsSwapInterval interval) noexcept;
	GraphicsSwapInterval getSwapInterval() const noexcept;

	void present() noexcept;

	const GraphicsSwapchainDesc& getGraphicsSwapchainDesc() const noexcept;

private:
	bool initSurface(const GraphicsSwapchainDesc& swapchainDesc);
	bool initPixelFormat(const GraphicsSwapchainDesc& swapchainDesc) noexcept;
	bool initSwapchain(const GraphicsSwapchainDesc& swapchainDesc) noexcept;

private:
	WGLSwapchain(const WGLSwapchain&) noexcept = delete;
	WGLSwapchain& operator=(const WGLSwapchain&) noexcept = delete;

private:
	bool _isActive;

	HDC _hdc;
	HGLRC _context;
	HWND _hwnd;
	HINSTANCE _hinstance;

	GLuint _major;
	GLuint _minor;

	GraphicsSwapchainDesc _swapchainDesc;
	GraphicsDeviceWeakPtr _device;
};

_NAME_END

#endif