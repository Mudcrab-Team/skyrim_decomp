// Source exposure: mixed (pinned community declarations and local target access/RTTI analysis).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; include/RE/C/ConcreteFormFactory.h; include/RE/I/IFormFactory.h; MIT.
// Code origin: adapted data declarations only; no external implementation bodies.
// ConcreteFormFactoryLayout: GUESS(medium) STANDIN; represented declaration aliases, not original type identities.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
#include "IFormFactoryLayout.h"
namespace ResearchLayouts {
// _name: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class ConcreteFormFactoryLayout : public IFormFactoryLayout {
public:
    ~ConcreteFormFactoryLayout() override;
    const char* _name;
};
static_assert(sizeof(ConcreteFormFactoryLayout) == 16, "community factory size");
static_assert(offsetof(ConcreteFormFactoryLayout, _name) == 8, "target getter and community field");
}
