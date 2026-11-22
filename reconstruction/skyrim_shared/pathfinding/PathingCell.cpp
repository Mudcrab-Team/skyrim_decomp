// Source exposure: mixed (pinned listing, labelled community declarations and sibling source).
// Code origin: original reconstruction and the cited sibling adaptation.
// Adapted bodies: GetType from fo4-private@1b765c70 (author-permission).
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Pathing/PathingCell.cpp:62 (PathingCell::GetType)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyHover.cpp:45 (PathingRequestFlyHover::GetType; CRC initialization pattern)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// PathingCell::GetWorldSpace, PathingCell::GetInteriorCell, PathingCell::GetParentSpace: CRASHLOGGER_PDB(59818@2026.10.24)
// kCellForm, kWorldSpaceForm: OBSERVED
// PathingFormIndex, g_pathingForms, LookupByID: GUESS(low) STANDIN
// PathingCell::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x4e0020 PathingCell::GetType
// 0x4e0270 PathingCell::GetWorldSpace
// 0x4e02b0 PathingCell::GetInteriorCell
// 0x4e0230 PathingCell::GetParentSpace
#include "PathingCell.h"
unsigned int PathingCell::GetType() const
{
    unsigned int result = typeId;
    if (!result) {
        BSCRC32::GenerateCRC(typeId, "PathingCell", 0);
        return typeId;
    }
    return result;
}

namespace {
constexpr FormType kCellForm = static_cast<FormType>(0x3C);
constexpr FormType kWorldSpaceForm = static_cast<FormType>(0x47);
}

// Resolve the world-space form recorded by this pathing cell.
TESForm* PathingCell::GetWorldSpace() const
{
    TESForm* form = g_pathingForms->LookupByID(pathingCellInfo.worldSpaceID);
    if (form) {
        return form->formType == kWorldSpaceForm ? form : nullptr;
    }
    return form;
}

// Resolve the cell form for an interior pathing cell.
TESForm* PathingCell::GetInteriorCell() const
{
    TESForm* cell = nullptr;
    if (pathingCellInfo.worldSpaceID == 0) {
        TESForm* form = g_pathingForms->LookupByID(pathingCellInfo.cellID);
        if (form && form->formType == kCellForm) {
            cell = form;
        }
    }
    return cell;
}

// Resolve the interior cell or world space that owns this pathing cell.
TESForm* PathingCell::GetParentSpace() const
{
    FormID id = pathingCellInfo.worldSpaceID;
    if (!id) {
        id = pathingCellInfo.cellID;
    }
    TESForm* form = g_pathingForms->LookupByID(id);
    if (form) {
        const FormType type = form->formType;
        if (type != kCellForm && type != kWorldSpaceForm) {
            form = nullptr;
        }
    }
    return form;
}
