// Source exposure: mixed (pinned community declarations and local target access/RTTI analysis).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; include/RE/C/ConcreteObjectFormFactory.h; include/RE/C/ConcreteFormFactory.h; MIT.
// Code origin: adapted data declarations only; no external implementation bodies.
// ConcreteObjectFormFactoryLayout: GUESS(medium) STANDIN; represented declaration aliases, not original type identities.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
#include "ConcreteFormFactoryLayout.h"
namespace ResearchLayouts {
class ConcreteObjectFormFactoryLayout : public ConcreteFormFactoryLayout {
public:
    ~ConcreteObjectFormFactoryLayout() override;
};
static_assert(sizeof(ConcreteObjectFormFactoryLayout) == 16, "community object factory adds no fields");
static_assert(offsetof(ConcreteObjectFormFactoryLayout, _name) == 8, "inherited name field");
}
