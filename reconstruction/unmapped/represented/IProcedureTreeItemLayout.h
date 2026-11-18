// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/IProcedureTreeItem.h; MIT.
// IProcedureTreeItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IProcedureTreeItemLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class IProcedureTreeItemLayout {
public:
    virtual ~IProcedureTreeItemLayout();
};
static_assert(sizeof(IProcedureTreeItemLayout) == 8, "community represented size");
}
