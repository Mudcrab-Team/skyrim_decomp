// ArmorRatingVisitorBase::Visit (COMMUNITY name), RVA 0x73ae00, 172 bytes.
// Source exposure: mixed. Drafted by a model worker (claude-sonnet-5-5) from a local instruction
// listing and decompiler output of the pinned image, with types from the header beside this file.
// 0x73ad90 ArmorRatingVisitor::HaveNotVisitedArmor
// 0x73ae00 ArmorRatingVisitorBase::Visit
#include "ArmorRatingVisitor.h"

bool ArmorRatingVisitor::HaveNotVisitedArmor(TESObjectARMO* a_armor)
{
    std::int32_t idx = -1;
    for (std::uint32_t i = 0; i < armors.Size() && idx == -1; ++i) {
        if (armors[i] == a_armor) {
            idx = static_cast<std::int32_t>(i);
        }
    }
    return idx == -1;
}

std::uint32_t ArmorRatingVisitorBase::Visit(InventoryEntryData* a_entryData)
{
    TESBoundObject* object = a_entryData->object;
    if (object && object->formType == 0x1a) {
        auto* armor = static_cast<TESObjectARMO*>(object);
        if (armor->unk1BC != 2 && HaveNotVisitedArmor(armor)) {
            float skill = GetArmorKind(armor) == 0xc ? lightArmorRating : heavyArmorRating;
            float rating = GetArmorFinalRating(a_entryData, armorPerks, skill);
            HandleEntryPoint(0x55, actor, armor, &rating);
            armorSum += rating;
            VisitArmor(armor);
        }
    }
    return 1;
}

ArmorRatingVisitor::~ArmorRatingVisitor() {}

ArmorRatingVisitorBase::~ArmorRatingVisitorBase() {}
void ArmorRatingVisitorBase::Unk02() {}
void ArmorRatingVisitorBase::Unk03() {}
bool ArmorRatingVisitorBase::HaveNotVisitedArmor(TESObjectARMO*) { return true; }
void ArmorRatingVisitorBase::VisitArmor(TESObjectARMO*) {}
