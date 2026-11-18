// Source exposure: mixed (community declarations and independently bound target RTTI).
// Code origin: declarations adapted from the pinned community headers; no implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/IHandlerFunctor.h; MIT.
// IHandlerFunctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IHandlerFunctorRepresentedLayout: GUESS(medium) STANDIN; represented base-object layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: declarations adapted from the pinned represented community header; no implementation bodies reused.
// IHandlerFunctorBulkLayout, BSIntrusiveRefCountedBulkLayout: GUESS(medium) STANDIN; represented layout aliases.
#pragma once
#include <cstddef>
#include "BSIntrusiveRefCountedBulkLayout.h"
namespace ResearchLayouts {
class IHandlerFunctorBulkLayout : public BSIntrusiveRefCountedBulkLayout {
public:
    virtual ~IHandlerFunctorBulkLayout();
};
static_assert(sizeof(IHandlerFunctorBulkLayout) == 16, "published represented base size");
static_assert(offsetof(IHandlerFunctorBulkLayout, _refCount) == 8, "represented reference count offset");
}
