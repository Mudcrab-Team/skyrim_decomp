// code-byte-mismatch; best attempt 2, size 84/84, 51 matching bytes.
// Remaining floating-point load, subtraction, store order and register choice differ.
// Exposure detail: (local binary analysis, community declarations, permitted sibling study).
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorMagicCaster, BSLight, NiLight, NiTransform, NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// light, world, translate, rotate, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AdjustLight: SIBLING(fo4-private@1b765c70, author-permission) SYMBOLS(tesv-2013-map); identification inferred from the position adjustment
// unaccessedPrefix: GUESS(low); unaccessed regions of reduced declarations

#pragma once
#include <cstddef>

struct NiPoint3 { float x, y, z; };
struct NiTransform { char rotate[0x24]; NiPoint3 translate; };
struct NiLight { char unaccessedPrefix[0x7C]; NiTransform world; };
struct BSLight { char unaccessedPrefix[0x48]; NiLight* light; };
class ActorMagicCaster
{
public:
    void AdjustLight(const NiPoint3& adjustment);
    char unaccessedPrefix[0xC8];
    BSLight* light;
};
static_assert(offsetof(ActorMagicCaster, light) == 0xC8, "light offset");
static_assert(offsetof(BSLight, light) == 0x48, "light object offset");
static_assert(offsetof(NiLight, world) + offsetof(NiTransform, translate) == 0xA0, "world translation offset");
