/*
    This file is part of BlueFramework, a simple 3D engine.
    Copyright (c) 2018 Technical University of Munich
    Chair of Computational Modeling and Simulation.

    BlueFramework is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License Version 3
    as published by the Free Software Foundation.

    BlueFramework is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <BlueFramework/GLRenderSystem/EffectCore.h>
#include <BlueFramework/GLRenderSystem/namespace.h>
#include <BlueFramework/GLRenderSystem/RenderSystem.h>
#include <BlueFramework/GLRenderSystem/PipelineState.h>
#include <BlueFramework/GLRenderSystem/VertexBuffer.h>
#include <BlueFramework/GLRenderSystem/Sampler.h>
#include <BlueFramework/GLRenderSystem/Texture1D.h>
#include <BlueFramework/GLRenderSystem/Texture2D.h>

#include <BlueFramework/Core/memory.h>

BLUE_NAMESPACE_BLUEFRAMEWORK_GLRENDERSYSTEM_BEGIN

EffectCore::EffectCore(RenderSystem* rs)
	: buw::IEffectCore(rs)
	, _rs(rs)
{
}

EffectCore::~EffectCore()
{
}

buw::IRenderSystem* EffectCore::renderSystem()
{
	return _rs;
}

buw::ReferenceCounted<buw::IPipelineState> EffectCore::createPipelineState(buw::pipelineStateDescription const& psd)
{
	return buw::makeReferenceCounted<PipelineState>(_rs, psd);
}

void EffectCore::setPipelineState(buw::ReferenceCounted<buw::IPipelineState> ps)
{
	std::static_pointer_cast<PipelineState>(ps)->setActive();
}

void EffectCore::setVertexBuffer(buw::ReferenceCounted<buw::IVertexBuffer> vb) const
{
	std::static_pointer_cast<VertexBuffer>(vb)->setActive();
}

void EffectCore::setIndexBuffer(buw::ReferenceCounted<buw::IIndexBuffer> ib) const
{
	// FGI TODO
}

void EffectCore::setConstantBuffer(buw::ReferenceCounted<buw::IConstantBuffer> cb, std::string const& /*sstrName*/) const
{
	// FGI TODO
}

void EffectCore::setTexture(buw::ReferenceCounted<buw::ITexture1D> tex1d, std::string const& sstrName) const
{
	std::static_pointer_cast<Texture1D>(tex1d)->setActive(sstrName);
}

void EffectCore::setTexture(buw::ReferenceCounted<buw::ITexture2D> tex2d, std::string const& sstrName) const
{
	std::static_pointer_cast<Texture2D>(tex2d)->setActive(sstrName);
}

void EffectCore::setTexture(buw::ReferenceCounted<buw::ITextureCube> cubeTex, std::string const& /*sstrName*/) const
{
	// FGI TODO
}

void EffectCore::setSampler(buw::ReferenceCounted<buw::ISampler> sampler, std::string const& /*sstrName*/) const
{
	std::static_pointer_cast<Sampler>(sampler)->setActive();
}

void EffectCore::setViewport(buw::ReferenceCounted<buw::IViewport>) const
{
	// No use for this in OpenGL.
}

void EffectCore::setRenderTarget(buw::ReferenceCounted<buw::ITexture2D> renderTarget, buw::ReferenceCounted<buw::ITexture2D> depthStencil) const
{
	// FGI TODO
}

void EffectCore::setRenderTargets(std::vector<buw::ReferenceCounted<buw::ITexture2D>> renderTargets, buw::ReferenceCounted<buw::ITexture2D> depthStencil) const
{
	// FGI TODO
}

void EffectCore::draw(UINT vertices) const throw(...)
{
	buw::ReferenceCounted<VertexBuffer> vb = VertexBuffer::getActive();
	if (!vb) throw buw::Exception("There is no active vertex buffer. Use VertexBuffer::setActive() first.");
	vb->draw(vertices);
}

void EffectCore::drawIndexed(UINT /*indices*/) const
{
	// FGI TODO
}

void EffectCore::preInit()
{
}

void EffectCore::postInit()
{
}

void EffectCore::preRender()
{
}

void EffectCore::postRender()
{
}

BLUE_NAMESPACE_BLUEFRAMEWORK_GLRENDERSYSTEM_END
