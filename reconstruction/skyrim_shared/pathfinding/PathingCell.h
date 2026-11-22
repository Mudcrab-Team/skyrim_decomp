// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Code origin: original declarations from the labelled community types and sibling source.
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Pathing/PathingCell.cpp:62 (PathingCell::GetType)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyHover.cpp:45 (PathingRequestFlyHover::GetType; CRC initialization pattern)
// PathingCell, GetType, typeId, result, BSCRC32, GenerateCRC: GUESS(low)
// PathingCellInfo, BSPathingCell, PathingCell layout and lookup method names: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include "skyrim_shared/forms/TESForm.h"
#include "generated/crashlogger_pdb/types/BSPathingCell.h"
class BSCRC32 { public: static void GenerateCRC(unsigned int& value, const char* name, int mode); };
struct PathingCellInfo {
    FormID worldSpaceID;
    FormID cellID;
};

class PathingFormIndex {
public:
    TESForm* LookupByID(FormID a_id) const;
};

extern PathingFormIndex* g_pathingForms;

class PathingCell {
public:
    static unsigned int typeId;
    unsigned int GetType() const;
    TESForm* GetWorldSpace() const;
    TESForm* GetInteriorCell() const;
    TESForm* GetParentSpace() const;

    BSPathingCell base;
    PathingCellInfo pathingCellInfo;
};
