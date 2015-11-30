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
#include <ray/mygui_scrollview.h>

_NAME_BEGIN

MyGuiScrollViewImpl::MyGuiScrollViewImpl() noexcept
	: _parent(nullptr)
	, _scrollView(nullptr)
{
}

MyGuiScrollViewImpl::~MyGuiScrollViewImpl() noexcept
{
}

bool
MyGuiScrollViewImpl::create() except
{
	assert(!_scrollView);
	if (_parent)
		_scrollView = _parent->createWidget<MyGUI::ScrollView>("", 0, 0, 0, 0, MyGUI::Align::Default, "");
	else
		_scrollView = MyGUI::Gui::getInstance().createWidget<MyGUI::ScrollView>("", 0, 0, 0, 0, MyGUI::Align::Default, "Main", "");

	this->setWidget(_scrollView);

	return _scrollView ? true : false;
}

void
MyGuiScrollViewImpl::setPosition(int left, int top)
{
	_scrollView->setPosition(left, top);
}

void
MyGuiScrollViewImpl::setSize(int width, int height)
{
	_scrollView->setSize(width, height);
}

void
MyGuiScrollViewImpl::setCoord(int left, int top, int width, int height)
{
	_scrollView->setCoord(left, top, width, height);
}

void
MyGuiScrollViewImpl::setVisibleVScroll(bool value)
{
	_scrollView->setVisibleVScroll(value);
}

bool
MyGuiScrollViewImpl::isVisibleVScroll() const
{
	return _scrollView->isVisibleVScroll();
}

void
MyGuiScrollViewImpl::setVisibleHScroll(bool value)
{
	_scrollView->setVisibleHScroll(value);
}

bool
MyGuiScrollViewImpl::isVisibleHScroll() const
{
	return _scrollView->isVisibleHScroll();
}

void
MyGuiScrollViewImpl::setCanvasAlign(GuiWidgetAlign value)
{
	_scrollView->setCanvasAlign(GuiAlignToMyGui(value));
}

GuiWidgetAlign
MyGuiScrollViewImpl::getCanvasAlign() const
{
	return MyGuiToGuiAlign(_scrollView->getCanvasAlign());
}

void
MyGuiScrollViewImpl::setCanvasSize(const Size& value)
{
	this->setCanvasSize(value.x, value.y);
}

void
MyGuiScrollViewImpl::setCanvasSize(int width, int height)
{
	_scrollView->setCanvasSize(width, height);
}

Size
MyGuiScrollViewImpl::getCanvasSize()
{
	return convert(_scrollView->getSize());
}

Rect
MyGuiScrollViewImpl::getViewCoord() const
{
	return convert(_scrollView->getViewCoord());
}

void
MyGuiScrollViewImpl::setViewOffset(const Point& value)
{
	_scrollView->setViewOffset(convert(value));
}

Point
MyGuiScrollViewImpl::getViewOffset() const
{
	return convert(_scrollView->getViewOffset());
}

MyGuiScrollView::MyGuiScrollView() noexcept
	: GuiScrollView(_impl)
{
}

MyGuiScrollView::~MyGuiScrollView() noexcept
{
}

void
MyGuiScrollView::setPosition(const Point& value)
{
	_impl.setPosition(value.x, value.y);
}

void
MyGuiScrollView::setSize(const Size& value)
{
	_impl.setSize(value.x, value.y);
}

void
MyGuiScrollView::setCoord(const Rect& value)
{
	_impl.setCoord(value.x, value.y, value.w, value.h);
}

void
MyGuiScrollView::setPosition(int left, int top)
{
	_impl.setPosition(left, top);
}

void
MyGuiScrollView::setSize(int width, int height)
{
	_impl.setSize(width, height);
}

void
MyGuiScrollView::setCoord(int left, int top, int width, int height)
{
	_impl.setCoord(left, top, width, height);
}

void
MyGuiScrollView::setVisibleVScroll(bool value)
{
	_impl.setVisibleVScroll(value);
}

bool
MyGuiScrollView::isVisibleVScroll() const
{
	return _impl.isVisibleVScroll();
}

void
MyGuiScrollView::setVisibleHScroll(bool value)
{
	_impl.setVisibleHScroll(value);
}

bool
MyGuiScrollView::isVisibleHScroll() const
{
	return _impl.isVisibleHScroll();
}

void
MyGuiScrollView::setCanvasAlign(GuiWidgetAlign value)
{
	_impl.setCanvasAlign(value);
}

GuiWidgetAlign
MyGuiScrollView::getCanvasAlign() const
{
	return _impl.getCanvasAlign();
}

void
MyGuiScrollView::setCanvasSize(const Size& value)
{
	this->setCanvasSize(value.x, value.y);
}

void
MyGuiScrollView::setCanvasSize(int width, int height)
{
	_impl.setCanvasSize(width, height);
}

Size
MyGuiScrollView::getCanvasSize()
{
	return _impl.getCanvasSize();
}

Rect
MyGuiScrollView::getViewCoord() const
{
	return _impl.getViewCoord();
}

void
MyGuiScrollView::setViewOffset(const Point& value)
{
	_impl.setViewOffset(value);
}

Point
MyGuiScrollView::getViewOffset() const
{
	return _impl.getViewOffset();
}

_NAME_END