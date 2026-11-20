// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image, with names and the GetFormEditorID shape from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// Bodies adapted from community sources: none; tools/check_origin.py reports none above its threshold.
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
