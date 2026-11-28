// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x8b4780 Function8b4780
// Cookbook: 0x8b4780 21
// Adapted bodies: none
#include "FreeFunction_8b4780.h"

// Notifies ctx->first, passes the thread-local payload to ctx->second, and clears bits 0x140 on ctx->third.
void Function8b4780(Context8b4780* ctx)
{
    NotifyFirst8b4780(ctx->first, 0);
    ctx->second->ApplyContext(g_tlsContext_tls_0x6a0->inner->payload);
    if (ctx->third != nullptr) {
        ctx->third->flags &= ~0x140u;
    }
}
