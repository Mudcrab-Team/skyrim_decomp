// Source exposure: binary-analysis. Drafted by v-macrev, assisted by claude-opus-5-5.
// Code origin: original implementation written by v-macrev, assisted by claude-opus-5-5, from a local
// listing of the contributor's own copy of the pinned image. No community or sibling body is adapted.
// ~BSFaceGenKeyframe was added from the same listing by Taylor Turner with Claude Sonnet 5.5 (first drafts by DeepSeek V4.1 Flash).
// 0x432510 BSFaceGenKeyframe::Unk_0C
// 0x432340 BSFaceGenKeyframe::~BSFaceGenKeyframe
#include "BSFaceGenKeyframe.h"

bool BSFaceGenKeyframe::Unk_0C()
{
    return false;
}

bool BSFaceGenKeyframe::Unk_0D()
{
    return false;
}

// RVA 0x432340, 43 bytes: the scalar deleting destructor stores its vftable, then frees this with
// the class size when the delete flag is set.
BSFaceGenKeyframe::~BSFaceGenKeyframe()
{
}
