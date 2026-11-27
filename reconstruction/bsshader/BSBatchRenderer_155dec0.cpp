// Source exposure: mixed (pinned image and community-generated names and declarations).
// Code origin: original typed reconstruction from local observations. Adapted bodies: none.
// BSBatchRenderer, GeometryGroup, ComputeAlphaGroupDepth: CRASHLOGGER_PDB(59818@2026.10.24)
// FindActivePass, FindNextActivePass, ClearGeometryGroupPasses, MemoryContextGuard, renderMemoryContext, g_memoryContext, alphaGroupCount, alphaGroups: GUESS(low) STANDIN
// CI hash: 0x155dec0 ?ClearGeometryGroupPasses@GeometryGroup@BSBatchRenderer@@QEAAXXZ
// 0x155dec0 BSBatchRenderer::GeometryGroup::ClearGeometryGroupPasses
/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "BSBatchRenderer_155dec0.h"
#include "BSLightingShaderMaterialBase_1528000.h"

// PDB note: the first entry operates on a GeometryGroup; the second consumes three cursor pointers.
// Their community owner/prototype annotations do not describe those observed receiver and argument uses.
void BSBatchRenderer::GeometryGroup::ClearGeometryGroupPasses()
{
    enum { renderMemoryContext = 32 };
    MemoryContextGuard context(renderMemoryContext);
    head = nullptr;
    tail = nullptr;
    if (batchRenderer) {
        batchRenderer->ClearAllRenderPasses(0);
    }
    count = 0;
}
