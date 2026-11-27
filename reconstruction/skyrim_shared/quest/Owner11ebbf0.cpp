// Source exposure: mixed (community declarations and the pinned image listing).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction with the labelled visitor interface. Stamped as a twin of matched 0x535900 (skyrim_shared/quest/BGSStoryManagerBranchNode): source copied, names replaced by placeholders.
// 0x11ebbf0 Owner11ebbf0::AcceptVisitor
#include "Owner11ebbf0.h"

// Dispatch the visitor to this story branch.
BGSStoryManagerTreeVisitor::VisitControl Owner11ebbf0::AcceptVisitor(BGSStoryManagerTreeVisitor& a_visitor)
{
    return a_visitor.VisitBranchNode(*reinterpret_cast<BGSStoryManagerBranchNode*>(this));
}
