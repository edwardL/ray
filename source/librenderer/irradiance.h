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
#ifndef _H_IRRADIANCE_H_
#define _H_IRRADIANCE_H_

#include <ray/render_pipeline.h>

_NAME_BEGIN

class EnvironmentIrradiance
{
public:
	EnvironmentIrradiance() noexcept;
	~EnvironmentIrradiance() noexcept;

	bool setup(RenderPipeline& pipeline) noexcept;
	void close() noexcept;

	void renderParaboloidEnvMap(RenderPipeline& pipeline, GraphicsTexturePtr cubemap) noexcept;
	void renderProjectParaboloidToSH(RenderPipeline& pipeline, GraphicsFramebufferPtr evalSHFunction, GraphicsFramebufferPtr dest) noexcept;
	void renderEvaluateConvolvedSH(RenderPipeline& pipeline, GraphicsFramebufferPtr evalSHFunction, GraphicsFramebufferPtr dest) noexcept;

private:
	bool _buildDualParaboloidWeightTextures(RenderPipeline& pipeline, GraphicsTexturePtr textures[2], std::uint32_t order, std::uint32_t size) noexcept;
	bool _paraboloidCoord(double3& vec, int face, const double2& uv) noexcept;

private:
	MaterialPtr _irradiance;
	MaterialTechPtr _irradianceParaboloid;
	MaterialTechPtr _irradianceProjectDualParaboloidToSH;

	MaterialParamPtr _paraboloidSamplesInverse;
	MaterialParamPtr _paraboloidCubeMapSampler;

	MaterialParamPtr _sphericalHarmonicConvolveDE0;
	MaterialParamPtr _sphericalHarmonicConvolveDE1;
	MaterialParamPtr _sphericalHarmonicConvolveYlmDW0;
	MaterialParamPtr _sphericalHarmonicConvolveYlmDW1;

	GraphicsTexturePtr _paraboloidFrontMap;
	GraphicsTexturePtr _paraboloidBackMap;
	GraphicsTexturePtr _paraboloidDualMaps;
	GraphicsTexturePtr _paraboloidSHWeights[2];
	GraphicsTexturePtr _paraboloidSphericalHarmonicMap;
	GraphicsTexturePtr _irradianceSHCoefficientsMap;

	GraphicsFramebufferPtr _paraboloidDualViews;
	GraphicsFramebufferPtr _irradianceSHCoefficientsView;
};

_NAME_END

#endif