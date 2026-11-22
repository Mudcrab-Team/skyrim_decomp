// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image, with names from the community header; a byte match does not verify names.
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ApplyCollisionLayer, ApplyCollisionLayerAndGroup, FindCollisionObject: GUESS; unnamed callees, see the header
// EnableRigidConstraints, DisableRigidConstraints: GUESS; unnamed callees, see the header
// IsInvalid, FindBone, FindFlattenedBone: GUESS; unnamed callees, see the header
// NiAVObject::GetCollisionObject (non-const): COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares it const, the const overload above is the already compared one
// Adapted bodies: none
// NiUpdateData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); time and the flag byte the compared code tests
// NiTimeController: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 0x27 and the next link at 0x40
// UpdateTransformAndBounds, UpdateControllers: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// Start, Stop, Update, next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PerformOpFunc: GUESS(low); the visitor the image forwards the object to, slot 1 is its call operator
// PostAttachParent: GUESS(low); file-local standin for the parent's vtable padding up to byte offset 0x1E8
// 0xee0e50 NiAVObject::UpdateTransformAndBounds
// 0xee09b0 NiAVObject::UpdateControllers
#include "NiAVObject_ee09b0.h"

class NiUpdateData
{
public:
    float time;                // 00
    std::uint8_t updateFlags;  // 04
    std::uint8_t unk05[3];     // 05
};

class NiTimeController : public NiObject
{
public:
    virtual void Start(float a_time);          // 25
    virtual void Stop();                       // 26
    virtual void Update(NiUpdateData& a_data);  // 27

    std::uint8_t unk10[0x30];  // 10
    NiTimeController* next;    // 40
};

// PostAttachParent: GUESS(low); a file-local standin for the parent object. It carries the padding
// virtuals up to the slot at byte offset 0x1E8 that PostAttachUpdate calls. These must not live on
// the shared NiNode stand-in, or every class deriving from it would have its vtable shifted.
class PostAttachParent : public NiAVObject
{
public:
    virtual void Unk_158();  // 158
    virtual void Unk_160();  // 160
    virtual void Unk_168();  // 168
    virtual void Unk_170();  // 170
    virtual void Unk_178();  // 178
    virtual void Unk_180(NiUpdateData* a_data);  // 180
    virtual void Unk_188();  // 188
    virtual void Unk_190();  // 190
    virtual void Unk_198();  // 198
    virtual void Unk_1A0();  // 1A0
    virtual void Unk_1A8();  // 1A8
    virtual void Unk_1B0();  // 1B0
    virtual void Unk_1B8();  // 1B8
    virtual void Unk_1C0();  // 1C0
    virtual void Unk_1C8();  // 1C8
    virtual void Unk_1D0();  // 1D0
    virtual void Unk_1D8();  // 1D8
    virtual void Unk_1E0();  // 1E0
    virtual void Unk_1E8();  // 1E8
};

void NiAVObject::UpdateTransformAndBounds(NiUpdateData& a_data)
{
    if (TestBit(flags, 2)) {
        // slots 0x30 and 0x2F are stand-ins here; the image calls them in this order
        PostAttachParent* self = static_cast<PostAttachParent*>(this);
        self->Unk_180(&a_data);
        self->Unk_178();
    }
}

void NiAVObject::UpdateControllers(NiUpdateData& a_data)
{
    if (a_data.updateFlags & 1) {
        for (NiTimeController* controller = controllers; controller; controller = controller->next) {
            controller->Update(a_data);
        }
    }
}
