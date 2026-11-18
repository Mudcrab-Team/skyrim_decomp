// Source exposure: mixed (community declarations and local RTTI analysis).
// Declaration source: include/RE/I/ImageSpaceEffect.h
// Declaration source: include/RE/N/NiTArray.h
// ImageSpaceEffect, NiTArray: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ImageEffectLayout: GUESS(medium) STANDIN
// Original declarations derived from the pinned community sources. No implementation bodies copied. Omitted methods are not reconstructed.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
template<class T> class EffectArrayLayout {
public:
    virtual ~EffectArrayLayout();
    T* data;
    std::uint16_t capacity;
    std::uint16_t freeIndex;
    std::uint16_t size;
    std::uint16_t growthSize;
};
class ImageEffectLayout {
public:
    ImageEffectLayout();
    virtual ~ImageEffectLayout();
    bool active;
    bool unknown09;
    EffectArrayLayout<void*> effects;
    EffectArrayLayout<void*> effectParams;
    EffectArrayLayout<void*> effectTextures;
    EffectArrayLayout<void*> effectInputs;
    EffectArrayLayout<std::int32_t> unknown70;
    bool unknown88;
};
static_assert(sizeof(EffectArrayLayout<void*>) == 0x18, "array storage");
static_assert(sizeof(ImageEffectLayout) == 0x90, "image effect size");
static_assert(offsetof(ImageEffectLayout, effects) == 0x10, "effects offset");
static_assert(offsetof(ImageEffectLayout, unknown88) == 0x88, "effect flag offset");
}
