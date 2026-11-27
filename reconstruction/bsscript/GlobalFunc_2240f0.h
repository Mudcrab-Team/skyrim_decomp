// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Stand-in declarations: NiAVObject.
// NiAVObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetObjectIndexInSceneGraph, RecurseAndGetObjectIndexInSceneGraph: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/GlobalFunc.cpp:791
#pragma once

// Owner tag for this unit: the compared functions are free functions of one source file.
struct GlobalFunc
{
};

class NiAVObject;

bool RecurseAndGetObjectIndexInSceneGraph(NiAVObject* apRoot, NiAVObject* apObject, int& aiIndex,
                                          bool abIgnoreDecals, bool abIgnoreSkinnedDecals);
int GetObjectIndexInSceneGraph(NiAVObject* apRoot, NiAVObject* apObject, bool abIgnoreDecals, bool abIgnoreSkinnedDecals);
