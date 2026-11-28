// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Main, Main::PostRenderCleanup: CRASHLOGGER_PDB(59818@2026.10.24)
// RenderCleanupTarget, PostRenderWorker, gRenderCleanupTarget, gPostRenderWorker, gPostRenderFlag, gPostRenderReady, gPostRenderNotify, gPostRenderCount, ResetRenderState, NotifyRenderDone: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct RenderCleanupTarget
{
    void Cleanup();
};

struct PostRenderWorker
{
    void Run();
};

extern RenderCleanupTarget* gRenderCleanupTarget;
extern PostRenderWorker* gPostRenderWorker;
extern bool gPostRenderFlag;
extern bool gPostRenderReady;
extern bool gPostRenderNotify;
extern std::int32_t gPostRenderCount;

void ResetRenderState();
void NotifyRenderDone(std::uint32_t a_arg);

class Main
{
public:
    static void PostRenderCleanup();  // compared: 0x153a5b0
};
