// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction using labelled declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3f2590 TESTopicInfo::CreateGroupData
// Adapted bodies: none.
#include "TESTopicInfo_3f2590.h"

void TESTopicInfo::CreateGroupData(FORM* form, FORM_GROUP* group)
{
    if (!form) {
        return;
    }
    form->form = 0;
    if (group && group->groupData.formID == 0 &&
        group->groupData.flags == DialogueSignature) {
        TESForm* topic = parentTopic;
        if (!topic) {
            return;
        }
        form->form = GroupSignature;
        form->formID = 7;
        form->flags = topic->formID;
        form->length = 0;
        form->versionControl = 0;
    }
}
