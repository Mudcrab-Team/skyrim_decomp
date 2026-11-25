// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x18b200 (skyrim_shared/extradata/ExtraFlags): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x44db10 Owner44db10::Function44db10
#include "Owner44db10.h"

// guess: same compiled code as matched 0x18b200 apart from relocated fields; its role here is not established.
void Owner44db10::Function44db10(BGSLoadGameBuffer* a_buf)
{
    a_buf->LoadDataEndian(&flags, 4, 4);
}
