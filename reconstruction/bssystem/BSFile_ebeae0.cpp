// BSFile, sub: GUESS(low)
// _absoluteCurrentPos, _pad0C, _readFn, _writeFn, bufferAllocSize, bufferReadSize, pos, pad2C, buffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Inferred names: GUESS(low)
// Origin: original body; declarations adapted from CommonLibSSE-NG, MIT.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xebeae0 BSFile::sub

#include "BSFile_ebeae0.h"

void BSFile::sub() { if (buffer) { delete buffer; buffer = nullptr; } }
