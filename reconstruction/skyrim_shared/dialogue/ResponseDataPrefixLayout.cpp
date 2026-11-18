// Build: sse-steam-1-7-104.
// Drafted by GPT-6.1 Sol.
// Labels: v2
// Code origin: adapted public community storage declarations and original typed forwarding implementation.
// Evidence: findings/target-pin.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// PopulateResponseText: RVA 0x3ecb00, 9 bytes. Source exposure: mixed (target image and public community declarations).
// TESTopicInfo::ResponseData and PopulateResponseText: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// ResponseDataPrefixLayout, PopulateResponseTextMember: GUESS(low) STANDIN; helper name and signature reflect observed typed forwarding; behavior and original source identity are unclaimed.
// Partial storage view only: fields after responseText, full size, ownership and behavior are not represented.
// MIT License
// Copyright (c) 2018 Ryan-rsm-McKenzie
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#include "ResponseDataPrefixLayout.h"
namespace ResearchLayouts {
void ResponseDataPrefixLayout::PopulateResponseText(TESFile* file) { PopulateResponseTextMember(&responseText, file); }
}
