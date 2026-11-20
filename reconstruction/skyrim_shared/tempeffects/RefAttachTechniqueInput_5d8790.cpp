// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5d8790 RefAttachTechniqueInput::sub
#include "RefAttachTechniqueInput_5d8790.h"
void RefAttachTechniqueInput::Cleanup() { nodeName.ReleaseString(); BSAttachTechniques::AttachTechniqueInput::CleanupBase(); }
