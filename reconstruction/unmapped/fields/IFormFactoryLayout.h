// Source exposure: mixed (pinned community declarations and local target access/RTTI analysis).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; include/RE/I/IFormFactory.h; MIT.
// Code origin: adapted data declarations only; no external implementation bodies.
// IFormFactoryLayout: GUESS(medium) STANDIN; represented declaration aliases, not original type identities.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: represented declaration from reconstruction/forms/IFormFactoryLayout.h; only include spelling changed.
#pragma once
#include <cstddef>
#include <cstdint>
namespace ResearchLayouts {
class IFormFactoryLayout {
public:
    virtual ~IFormFactoryLayout();
};
static_assert(sizeof(IFormFactoryLayout) == 8, "community interface size");
}
