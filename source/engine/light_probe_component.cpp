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
#if defined(_BUILD_RENDERER)
#include <ray/light_probe_component.h>
#include <ray/game_server.h>
#include <ray/render_feature.h>

_NAME_BEGIN

__ImplementSubClass(LightProbeComponent, RenderComponent, "LightProbe")

LightProbeComponent::LightProbeComponent() noexcept
{
	_lightProbe = std::make_shared<LightProbe>();
	_lightProbe->setOwnerListener(this);
}

LightProbeComponent::LightProbeComponent(const archivebuf& reader) noexcept
	: LightProbeComponent()
{
	this->load(reader);
}

LightProbeComponent::~LightProbeComponent() noexcept
{
	_lightProbe->setRenderScene(nullptr);
}

void
LightProbeComponent::setVisible(bool visible) noexcept
{
	_lightProbe->setVisible(visible);
}

bool
LightProbeComponent::getVisible() const noexcept
{
	return _lightProbe->getVisible();
}

void
LightProbeComponent::setSH9(const SH9& sh) noexcept
{
	_lightProbe->setSH9(sh);
}

const SH9&
LightProbeComponent::getSH9() const noexcept
{
	return _lightProbe->getSH9();
}

const CameraPtr&
LightProbeComponent::getCamera() const noexcept
{
	return _lightProbe->getCamera();
}

void
LightProbeComponent::load(const archivebuf& reader) noexcept
{
	GameComponent::load(reader);
}

void
LightProbeComponent::save(archivebuf& write) noexcept
{
	RenderComponent::save(write);
}

GameComponentPtr
LightProbeComponent::clone() const noexcept
{
	auto result = std::make_shared<LightProbeComponent>();
	result->setName(this->getName());
	result->setActive(this->getActive());
	return result;
}

void
LightProbeComponent::onActivate() noexcept
{
	this->addComponentDispatch(GameDispatchType::GameDispatchTypeMoveAfter, this);

	_lightProbe->setRenderScene(GameServer::instance()->getFeature<RenderFeature>()->getRenderScene());
	_lightProbe->setTransform(this->getGameObject()->getWorldTransform(), this->getGameObject()->getWorldTransformInverse());
}

void
LightProbeComponent::onDeactivate() noexcept
{
	this->removeComponentDispatch(GameDispatchType::GameDispatchTypeMoveAfter, this);

	_lightProbe->setRenderScene(nullptr);
}

void
LightProbeComponent::onMoveAfter() noexcept
{
	_lightProbe->setTransform(this->getGameObject()->getWorldTransform(), this->getGameObject()->getWorldTransformInverse());
}

_NAME_END

#endif