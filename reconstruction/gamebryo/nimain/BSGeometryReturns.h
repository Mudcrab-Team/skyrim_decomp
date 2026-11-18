// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GPL declaration source: powerof3/CommonLibSSE; full pin 654e55f7979c1733033d5dbef176e43827bac944.
// Source exposure: mixed; binary-analysis and community declarations.
// ResearchReturns, BSGeometryReturns: GUESS(low) STANDIN
// Adapted bodies: none. Community declarations inform signatures only.
// AsSkinnedDecalTriShape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetVisibleGroupsTriangleCount: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Original reconstruction; no external implementation copied. A pass proves code only.
#pragma once
#include <cstdint>
class BSMultiIndexTriShape;
class BSSkinnedDecalTriShape;
namespace ResearchReturns {
class BSGeometryReturns {
public:
    virtual std::uint32_t GetVisibleGroupsTriangleCount();
    virtual BSMultiIndexTriShape* AsMultiIndexTriShape();
    virtual BSSkinnedDecalTriShape* AsSkinnedDecalTriShape();
};
}
