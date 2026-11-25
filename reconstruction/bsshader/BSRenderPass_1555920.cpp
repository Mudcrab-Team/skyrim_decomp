// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSRenderPass, ClearRenderPass, DrainRenderPassDeferredFreeQueue: CRASHLOGGER_PDB(59818@2026.10.24)
// RenderPassQueue, freeSlots, pendingSlots, readIndex, writeIndex, Acquire, Publish, queueCapacity: GUESS(low)
// 0x1555920 BSRenderPass::ClearRenderPass
#include "BSRenderPass_1555920.h"

// Queue a pass for deferred freeing, draining the queue if it has no free slots.
void BSRenderPass::ClearRenderPass(BSRenderPass* pass)
{
    if (pass) {
        constexpr unsigned int queueCapacity = 16384;
        const unsigned int write = writeIndex & (queueCapacity - 1);
        const unsigned int read = readIndex & (queueCapacity - 1);
        const unsigned int count = write >= read ? write - read : queueCapacity + write - read;
        if (!count) {
            DrainRenderPassDeferredFreeQueue();
        }
        BSRenderPass** slot = freeSlots.Acquire();
        *slot = pass;
        pendingSlots.Publish(slot);
    }
}
