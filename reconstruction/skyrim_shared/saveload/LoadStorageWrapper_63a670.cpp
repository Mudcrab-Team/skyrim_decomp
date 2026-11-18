// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// LoadStorageWrapper::Read: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSSaveLoadStorageWrappers.cpp:125
// LoadStorageWrapper, BSFile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/L/LoadStorageWrapper.h, include/RE/B/BSMemStorage.h, include/RE/B/BSStorage.h, include/RE/B/BSFile.h, include/RE/N/NiFile.h and include/RE/N/NiBinaryStream.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x63a670 LoadStorageWrapper::Read
#include "LoadStorageWrapper_63a670.h"
unsigned LoadStorageWrapper::Read(unsigned long long count, unsigned char* bytes) const { BSFile* f = file; unsigned elementSize = 1; f->absolutePosition += f->readFn(f, bytes, (unsigned)count, &elementSize, 1); return 0; }
