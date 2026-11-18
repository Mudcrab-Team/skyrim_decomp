// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// Bodies adapted from community sources: none; tools/check_origin.py reports none above its threshold.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x535c10 BGSStoryManagerEventNode::InitializeData
// 0x535d60 BGSStoryManagerEventNode::GetFormEditorID
#include "BGSStoryManagerEventNode.h"

void BGSStoryManagerEventNode::InitializeData()
{
    BGSStoryManagerNodeBase::InitializeData();
    event = nullptr;
}

const char* BGSStoryManagerEventNode::GetFormEditorID() const
{
    if (TestBit(formFlags, 3)) {
        if (event) {
            return event->GetName();
        }
        return "(No event)";
    }
    return "(Uninitialized event node)";
}
