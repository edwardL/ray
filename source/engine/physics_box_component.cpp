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
#include <ray/physics_box_component.h>
#include <ray/physics_shape_box.h>

_NAME_BEGIN

__ImplementSubClass(PhysicsBoxComponent, PhysicsShapeComponent, "PhysicsBox")

PhysicsBoxComponent::PhysicsBoxComponent() noexcept
{
	_shape = std::make_shared<PhysicsShapeBox>();
}

PhysicsBoxComponent::PhysicsBoxComponent(const float3& size) noexcept
{
	_shape = std::make_shared<PhysicsShapeBox>();
	_shape->setSize(size);
}

PhysicsBoxComponent::~PhysicsBoxComponent() noexcept
{
}

void
PhysicsBoxComponent::setSize(const float3& size) noexcept
{
	_shape->setSize(size);
}

const float3&
PhysicsBoxComponent::getSize() const noexcept
{
	return _shape->getSize();
}

void 
PhysicsBoxComponent::load(iarchive& reader) noexcept
{
	GameComponent::load(reader);

	float3 size;
	reader >> make_archive(size, "size");

	_shape->setSize(size);
}

void 
PhysicsBoxComponent::save(oarchive& write) noexcept
{
}

PhysicsShapePtr
PhysicsBoxComponent::getCollisionShape() noexcept
{
	return _shape;
}

GameComponentPtr
PhysicsBoxComponent::clone() const noexcept
{
	auto component = std::make_shared<PhysicsBoxComponent>();
	component->setSize(this->getSize());
	return component;
}

void
PhysicsBoxComponent::onActivate() noexcept
{
	_shape->setup();
}

void
PhysicsBoxComponent::onDeactivate() noexcept
{
	_shape->close();
}

_NAME_END