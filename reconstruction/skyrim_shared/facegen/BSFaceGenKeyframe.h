// Source exposure: binary-analysis (a local listing of the contributor's own copy of the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original declarations written by v-macrev, assisted by claude-opus-5-5, from that
// listing; only the class and method names come from CommonLibSSE-NG (labels below). No community or sibling code is adapted.
// ~BSFaceGenKeyframe and the two members at 08 and 0C were added from the same listing by Taylor Turner with Claude Sonnet 5.5 (first drafts by DeepSeek V4.1 Flash).
// BSFaceGenKeyframe: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk_0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk_0D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSFaceGenKeyframe::~BSFaceGenKeyframe, type, unk0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class BSFaceGenKeyframe {
public:
    virtual ~BSFaceGenKeyframe();  // compared: 0x432340 (scalar deleting destructor)

    // The community header declares both void with "{ return 0; }" notes. The listing returns a cleared
    // AL, so the bool return types are inferred from the listing, not from a community source.
    bool Unk_0C();
    bool Unk_0D();

    std::uint32_t type;  // 08
    float unk0C;         // 0C
};
static_assert(sizeof(BSFaceGenKeyframe) == 0x10, "BSFaceGenKeyframe size");
