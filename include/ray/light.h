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
#ifndef _H_LIGHT_H_
#define _H_LIGHT_H_

#include <ray/render_object.h>

_NAME_BEGIN

class EXPORT Light final : public RenderObject, public RenderListener
{
	__DeclareSubClass(Light, RenderObject)
public:
	Light() noexcept;
	virtual ~Light() noexcept;

	void setLightRange(float range) noexcept;
	void setLightType(LightType type) noexcept;
	void setLightIntensity(float intensity) noexcept;
	void setLightColor(const float3& color) noexcept;
	void setLightAttenuation(const float3& attenuation) noexcept;

	void setSpotInnerCone(float value) noexcept;
	void setSpotOuterCone(float value) noexcept;

	void setShadowBias(float bias) noexcept;
	void setShadowFactor(float factor) noexcept;
	void setShadowMode(ShadowMode shadowType) noexcept;

	void setGlobalIllumination(bool enable) noexcept;
	bool getGlobalIllumination() const noexcept;

	float getLightRange() const noexcept;
	float getLightIntensity() const noexcept;
	LightType getLightType() const noexcept;

	float getShadowBias() const noexcept;
	float getShadowFactor() const noexcept;
	ShadowMode getShadowMode() const noexcept;

	const float2& getSpotInnerCone() const noexcept;
	const float2& getSpotOuterCone() const noexcept;

	const float3& getLightColor() const noexcept;
	const float3& getLightAttenuation() const noexcept;

	void setSkyBox(const GraphicsTexturePtr& texture) noexcept;
	const GraphicsTexturePtr& getSkyBox() const noexcept;

	void setSkyLightingDiffuse(const GraphicsTexturePtr& texture) noexcept;
	const GraphicsTexturePtr& getSkyLightingDiffuse() const noexcept;

	void setSkyLightingSpecular(const GraphicsTexturePtr& texture) noexcept;
	const GraphicsTexturePtr& getSkyLightingSpecular() const noexcept;

	const CameraPtr& getCamera() const noexcept;

	RenderObjectPtr clone() const noexcept;

private:
	bool setupShadowMap() noexcept;
	bool setupReflectiveShadowMap() noexcept;

	void destroyShadowMap() noexcept;
	void destroyReflectiveShadowMap() noexcept;

	void _updateTransform() noexcept;
	void _updateBoundingBox() noexcept;

private:
	void onSceneChangeBefore() noexcept;
	void onSceneChangeAfter() noexcept;

	bool onVisiableTest(const Camera& camera, const Frustum& fru) noexcept;

	void onAddRenderData(RenderDataManager& manager) noexcept;

	void onRenderObjectPre(const Camera& camera) noexcept;
	void onRenderObjectPost(const Camera& camera) noexcept;

	void onMoveAfter() noexcept;

private:
	Light(const Light&) noexcept = delete;
	Light& operator=(const Light&) noexcept = delete;

private:
	LightType _lightType;

	float _lightRange;
	float _lightIntensity;

	float3 _lightColor;
	float3 _lightAttenuation;

	float2 _spotInnerCone;
	float2 _spotOuterCone;

	bool _enableSoftShadow;
	bool _enableGlobalIllumination;

	float _shadowBias;
	float _shadowFactor;
	CameraPtr _shadowCamera;
	ShadowMode _shadowMode;

	GraphicsTexturePtr _skybox;
	GraphicsTexturePtr _skyDiffuseIBL;
	GraphicsTexturePtr _skySpecularIBL;

	RenderSceneWeakPtr _renderScene;
};

_NAME_END

#endif