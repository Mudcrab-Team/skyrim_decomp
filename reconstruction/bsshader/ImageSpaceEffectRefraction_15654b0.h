// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ImageSpaceEffectRefraction, ImageSpaceEffectRefraction::ctor: CRASHLOGGER_PDB(59818@2026.10.24); names only
// ImageSpaceEffect: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); size 0x90 and the vtable slot order, bodies not compared here
// unk90, unk98, RefractionState, state, RefractionState::unk00, RefractionState::unk04, RefractionState::unk08, RefractionState::unk0C: GUESS(low); offsets from the listing; RefractionState groups the members that start out zeroed
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceEffectParam;

class ImageSpaceEffect
{
public:
    ImageSpaceEffect();  // callee at 0x1553950, not compared here
    virtual ~ImageSpaceEffect();
    virtual void Render(void* a_shape, ImageSpaceEffectParam* a_param);
    virtual void Setup(void* a_manager, ImageSpaceEffectParam* a_param);
    virtual void ShutDown();
    virtual void BorrowTextures(ImageSpaceEffectParam* a_param);
    virtual void ReturnTextures();
    virtual bool IsActive();
    virtual bool UpdateParams(ImageSpaceEffectParam* a_param);
    virtual bool SetRenderStates(ImageSpaceEffectParam* a_param);
    virtual bool RestoreRenderStates(ImageSpaceEffectParam* a_param);

    std::uint8_t unk08[0x88];
};
static_assert(sizeof(ImageSpaceEffect) == 0x90, "ImageSpaceEffect size");

class ImageSpaceEffectRefraction : public ImageSpaceEffect
{
public:
    ImageSpaceEffectRefraction();  // compared: 0x15654b0
    ~ImageSpaceEffectRefraction() override;

    // Cleared as one block by its own constructor.
    struct RefractionState
    {
        RefractionState()
            : unk00(0)
            , unk04(0)
            , unk08(0)
            , unk0C(false)
        {
        }

        std::int32_t unk00;  // 9C
        std::int32_t unk04;  // A0
        std::int32_t unk08;  // A4
        bool unk0C;          // A8
    };

    void* unk90;          // 90
    std::int32_t unk98;   // 98
    RefractionState state;          // 9C
};
static_assert(offsetof(ImageSpaceEffectRefraction, state) == 0x9c, "layout");
