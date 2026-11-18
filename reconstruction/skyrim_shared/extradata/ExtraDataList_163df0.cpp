// Inferred names: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Origin: original reconstruction informed by CommonLibSSE-NG declarations (MIT).
// Source exposure: mixed (local binary analysis and pinned public declarations).
// ExtraDataList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x163df0 ExtraDataList::Function163df0
// 0x172ec0 ExtraDataList::Function172ec0
// 0x172ef0 ExtraDataList::Function172ef0

// MIT License
// 
// Copyright (c) 2018 Ryan-rsm-McKenzie
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "ExtraDataList_163df0.h"
void* ExtraDataList::Function163df0() { auto* x = static_cast<ExtraFriendHits*>(GetByType(0x44)); return x ? x->Query() : nullptr; }
void* ExtraDataList::Function172ec0() { auto* x = static_cast<ExtraAliasInstanceArray*>(GetByType(0x88)); return x ? x->QueryA() : nullptr; }
void* ExtraDataList::Function172ef0() { auto* x = static_cast<ExtraAliasInstanceArray*>(GetByType(0x88)); return x ? x->QueryB() : nullptr; }
