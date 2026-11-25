// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSRenderPass, ClearRenderPass, DrainRenderPassDeferredFreeQueue: CRASHLOGGER_PDB(59818@2026.10.24)
// RenderPassQueue, freeSlots, pendingSlots, readIndex, writeIndex, Acquire, Publish, queueCapacity: GUESS(low)
#pragma once

struct BSRenderPass
{
    static void ClearRenderPass(BSRenderPass* pass);
};

struct RenderPassQueue
{
    BSRenderPass** Acquire();
    void Publish(BSRenderPass** slot);
};
extern RenderPassQueue freeSlots;
extern RenderPassQueue pendingSlots;
extern unsigned int readIndex;
extern unsigned int writeIndex;
void DrainRenderPassDeferredFreeQueue();
