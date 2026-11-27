// Near miss: 9.5 alignment distance | control-flow
// Exposure detail: (community declarations; permitted sibling game code; pinned-image observations).
// Source exposure: mixed
// Code origin: adapted sibling lookup with target-observed layout
// Adapted bodies: TESRace::GetDefaultHeadPart from fo4-private@1b765c70 (author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/TESRace.cpp:524
// TESRace::GetDefaultHeadPart body: SIBLING(fo4-private@1b765c70, author-permission)
// 0x3e6620 TESRace::GetDefaultHeadPart

#include "include/3e6620/TESRace_3e6620.h"

// SelectHeadPart: GUESS(low); preserves a prior match while inspecting a candidate
static inline BGSHeadPart* SelectHeadPart(BGSHeadPart* part, BGSHeadPart* previous,
                                        BGSHeadPart::HeadPartType type)
{
    return part->type != type ? previous : part;
}

BGSHeadPart* TESRace::GetDefaultHeadPart(std::int32_t sex, BGSHeadPart::HeadPartType type) const
{
    auto* face = faceRelatedData[sex];
    BGSHeadPart* result = nullptr;
    if (face) {
        auto* array = face->headParts;
        if (array) {
            auto count = array->count;
            std::uint64_t index = 0;
            do {
                if (index >= count)
                    break;
                result = SelectHeadPart(array->data[index], result, type);
                ++index;
            } while (!result);
        }
    }
    return result;
}
