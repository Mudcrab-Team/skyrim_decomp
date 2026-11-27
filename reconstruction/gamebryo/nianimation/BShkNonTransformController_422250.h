// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BShkNonTransformController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BShkNonTransformController::Func1_1403C2120: CRASHLOGGER_PDB(59818@2026.10.24)
// NonTransformInitData, NonTransformInitData::unk00, NonTransformInitData::context, NonTransformInitData::id, NonTransformInitData::unk14, NonTransformInitData::payload, BShkNonTransformController::Unk_00, BShkNonTransformController::Unk_01, BShkNonTransformController::Unk_02, BShkNonTransformController::InitFromPayload, BShkNonTransformController::id, BShkNonTransformController::unk0C: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct NonTransformInitData
{
    std::uint64_t unk00;
    void* context;
    std::uint32_t id;
    std::uint8_t unk14[0x40];
    std::uint8_t payload[0x04];
};
static_assert(offsetof(NonTransformInitData, context) == 0x08, "context offset");
static_assert(offsetof(NonTransformInitData, id) == 0x10, "id offset");
static_assert(offsetof(NonTransformInitData, payload) == 0x54, "payload offset");

class BShkNonTransformController
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void InitFromPayload(void* a_payload, void* a_context);

    bool Func1_1403C2120(NonTransformInitData* a_data);

    std::uint32_t id;
    std::uint8_t unk0C[0x0C];
};
static_assert(offsetof(BShkNonTransformController, id) == 0x08, "id offset");
static_assert(sizeof(BShkNonTransformController) == 0x18, "BShkNonTransformController size");
