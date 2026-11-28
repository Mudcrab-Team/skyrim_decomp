// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BGSStoryManagerTreeVisitor: CRASHLOGGER_PDB(59818@2026.10.24); listed ctor name disagrees with destructor behavior
// 0x5351a0 BGSStoryManagerTreeVisitor::~BGSStoryManagerTreeVisitor
// CI hash: 0x5351a0 ??1BGSStoryManagerTreeVisitor@@UEAA@XZ
#include "BGSStoryManagerTreeVisitor_5351a0.h"

// Destroys the visitor and releases its internal array storage.
// The CrashLogger name ctor does not fit this body, which is written as what it does (a guess).
BGSStoryManagerTreeVisitor::~BGSStoryManagerTreeVisitor()
{
}
