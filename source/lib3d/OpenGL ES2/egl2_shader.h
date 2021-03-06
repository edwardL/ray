// +----------------------------------------------------------------------
// | Project : ray.
// | All rights reserved.
// +----------------------------------------------------------------------
// | Copyright (c) 2013-2016.
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
#ifndef _H_EGL2_SHADER_H_
#define _H_EGL2_SHADER_H_

#include "egl2_types.h"

_NAME_BEGIN

class EGL2GraphicsAttribute final : public GraphicsAttribute
{
	__DeclareSubClass(EGL2GraphicsAttribute, GraphicsAttribute)
public:
	EGL2GraphicsAttribute() noexcept;
	~EGL2GraphicsAttribute() noexcept;

	void setSemantic(const std::string& semantic) noexcept;
	const std::string& getSemantic() const noexcept;

	void setSemanticIndex(std::uint32_t index) noexcept;
	std::uint32_t getSemanticIndex() const noexcept;

	void setType(GraphicsFormat type) noexcept;
	GraphicsFormat getType() const noexcept;

	void setBindingPoint(std::uint32_t bindingPoint) noexcept;
	std::uint32_t getBindingPoint() const noexcept;

private:
	EGL2GraphicsAttribute(const EGL2GraphicsAttribute&) noexcept = delete;
	EGL2GraphicsAttribute& operator=(const EGL2GraphicsAttribute&) noexcept = delete;

private:
	std::string _semantic;
	std::uint8_t _semanticIndex;
	std::uint32_t _bindingPoint;
	GraphicsFormat _type;
};

class EGL2GraphicsUniform final : public GraphicsUniform
{
	__DeclareSubClass(EGL2GraphicsUniform, GraphicsUniform)
public:
	EGL2GraphicsUniform() noexcept;
	~EGL2GraphicsUniform() noexcept;

	void setName(const std::string& name) noexcept;
	const std::string& getName() const noexcept;

	void setSamplerName(const std::string& name) noexcept;
	const std::string& getSamplerName() const noexcept;

	void setType(GraphicsUniformType type) noexcept;
	GraphicsUniformType getType() const noexcept;

	void setOffset(std::uint32_t offset) noexcept;
	std::uint32_t getOffset() const noexcept;

	void setBindingPoint(GLuint bindingPoint) noexcept;
	GLuint getBindingPoint() const noexcept;

	void setShaderStageFlags(GraphicsShaderStageFlags flags) noexcept;
	GraphicsShaderStageFlags getShaderStageFlags() const noexcept;

private:
	EGL2GraphicsUniform(const EGL2GraphicsUniform&) noexcept = delete;
	EGL2GraphicsUniform& operator=(const EGL2GraphicsUniform&) noexcept = delete;

private:
	std::string _name;
	std::string _samplerName;
	std::uint32_t _offset;
	GLuint _bindingPoint;
	GraphicsUniformType _type;
	GraphicsShaderStageFlags _stageFlags;
};

class EGL2Shader final : public GraphicsShader
{
	__DeclareSubClass(EGL2Shader, GraphicsShader)
public:
	EGL2Shader() noexcept;
	~EGL2Shader() noexcept;

	bool setup(const GraphicsShaderDesc& desc) noexcept;
	void close() noexcept;

	GLuint getInstanceID() const noexcept;

	const GraphicsShaderDesc& getGraphicsShaderDesc() const noexcept;

private:
	static bool HlslCodes2GLSL(GraphicsShaderStageFlags stage, const std::string& codes, std::string& out);
	static bool HlslByteCodes2GLSL(GraphicsShaderStageFlags stage, const char* codes, std::string& out);

private:
	friend class EGL2Device;
	void setDevice(GraphicsDevicePtr device) noexcept;
	GraphicsDevicePtr getDevice() noexcept;

private:
	EGL2Shader(const EGL2Shader&) noexcept = delete;
	EGL2Shader& operator=(const EGL2Shader&) noexcept = delete;

private:
	GLuint _instance;
	GraphicsDeviceWeakPtr _device;
	GraphicsShaderDesc _shaderDesc;
};

class EGL2Program final : public GraphicsProgram
{
	__DeclareSubClass(EGL2Program, GraphicsProgram)
public:
	EGL2Program() noexcept;
	~EGL2Program() noexcept;

	bool setup(const GraphicsProgramDesc& desc) noexcept;
	void close() noexcept;

	void apply() noexcept;

	GLuint getInstanceID() const noexcept;

	const GraphicsParams& getActiveParams() const noexcept;
	const GraphicsAttributes& getActiveAttributes() const noexcept;

	const GraphicsProgramDesc& getGraphicsProgramDesc() const noexcept;

private:
	void _initActiveAttribute() noexcept;
	void _initActiveUniform() noexcept;

private:
	static GraphicsFormat toGraphicsFormat(GLenum type) noexcept;
	static GraphicsUniformType toGraphicsUniformType(const std::string& name, GLenum type) noexcept;

private:
	friend class EGL2Device;
	void setDevice(GraphicsDevicePtr device) noexcept;
	GraphicsDevicePtr getDevice() noexcept;

private:
	EGL2Program(const EGL2Program&) noexcept = delete;
	EGL2Program& operator=(const EGL2Program&) noexcept = delete;

private:

	GLuint _program;

	GraphicsParams _activeParams;
	GraphicsAttributes  _activeAttributes;

	GraphicsDeviceWeakPtr _device;
	GraphicsProgramDesc _programDesc;
};

_NAME_END

#endif