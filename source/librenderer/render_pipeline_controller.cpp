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
#include <ray/render_pipeline_controller.h>

_NAME_BEGIN

RenderPipelineController::RenderPipelineController() noexcept
	: _active(false)
	, _renderPipeline(nullptr)
{
}

RenderPipelineController::~RenderPipelineController() noexcept
{
}

void
RenderPipelineController::setActive(bool active) except
{
	if (_active != active)
	{
		if (active)
			this->onActivate(*_renderPipeline);
		else
			this->onDeactivate(*_renderPipeline);

		_active = active;
	}
}

bool
RenderPipelineController::getActive() const noexcept
{
	return _active;
}

void
RenderPipelineController::onActivate(RenderPipeline&) except
{
}

void
RenderPipelineController::onDeactivate(RenderPipeline&) except
{
}

void
RenderPipelineController::onResolutionChangeBefore(RenderPipeline&) except
{
}

void
RenderPipelineController::onResolutionChangeAfter(RenderPipeline&) except
{
}

void
RenderPipelineController::onRenderPre(RenderPipeline& pipeline) except
{
}

void 
RenderPipelineController::onRenderPipeline(RenderPipeline& pipeline) except
{
}

void
RenderPipelineController::onRenderPost(RenderPipeline& pipeline) except
{
}

void
RenderPipelineController::_setRenderPipeline(RenderPipelinePtr pipeline) noexcept
{
	_renderPipeline = pipeline.get();
}

_NAME_END