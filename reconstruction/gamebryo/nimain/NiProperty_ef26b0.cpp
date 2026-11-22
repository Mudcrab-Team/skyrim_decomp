// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none; none
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0xef26b0 NiProperty::Update
#include "NiProperty_ef26b0.h"

// NiUpdateData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only passed through
class NiUpdateData
{
public:
    float time;                // 00
    std::uint32_t updateFlags;  // 04
};

// NiTimeControllerView: GUESS(low); file-local view of a time controller, the shared stand-in declares slot 0x27 without its argument
// Update, next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Slot00..Slot26: GUESS(low); placeholders so Update lands on slot 0x27
class NiTimeControllerView
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Update(NiUpdateData& a_data);  // 27

    std::uint8_t unk08[0x38];  // 08
    NiTimeControllerView* next;  // 40
};

void NiProperty::Update(NiUpdateData& a_data)
{
    NiTimeControllerView* first = reinterpret_cast<NiTimeControllerView*>(controllers.pointer);
    for (NiTimeControllerView* controller = first; controller; controller = controller->next) {
        controller->Update(a_data);
    }
}
