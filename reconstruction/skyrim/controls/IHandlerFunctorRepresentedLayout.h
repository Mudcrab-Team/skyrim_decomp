// Source exposure: mixed (community declarations and independently bound target RTTI).
// Code origin: declarations adapted from the pinned community headers; no implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/IHandlerFunctor.h; MIT.
// IHandlerFunctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IHandlerFunctorRepresentedLayout: GUESS(medium) STANDIN; represented base-object layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include "../../bscore/BSIntrusiveRefCountedStorageLayout.h"
namespace ResearchLayouts {
class IHandlerFunctorRepresentedLayout : public BSIntrusiveRefCountedStorageLayout {
public:
    virtual ~IHandlerFunctorRepresentedLayout();
};
static_assert(sizeof(IHandlerFunctorRepresentedLayout) == 16, "published represented base size");
static_assert(offsetof(IHandlerFunctorRepresentedLayout, _refCount) == 8, "represented reference count offset");
}
