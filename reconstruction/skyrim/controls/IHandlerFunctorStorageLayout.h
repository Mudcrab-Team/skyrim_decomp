// Source exposure: mixed (community declarations and independently bound target RTTI).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/IHandlerFunctor.h; MIT.
// IHandlerFunctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IHandlerFunctorStorageLayout: GUESS(medium) STANDIN; represented base-object layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include "../../bscore/BSIntrusiveRefCountedStorageLayout.h"
namespace ResearchLayouts {
class IHandlerFunctorStorageLayout : public BSIntrusiveRefCountedStorageLayout {
public:
    virtual ~IHandlerFunctorStorageLayout();
};
static_assert(sizeof(IHandlerFunctorStorageLayout) == 16, "published represented base size");
static_assert(offsetof(IHandlerFunctorStorageLayout, _refCount) == 8, "represented reference count offset");
}
