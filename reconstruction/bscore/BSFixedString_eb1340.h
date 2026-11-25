// Source exposure: mixed (pinned-image observations and community declarations).
// Code origin: original body; declarations adapted from CommonLibSSE-NG, no copied bodies.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFixedString, data, operator!=: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Declaration source: include/RE/B/BSFixedString.h; char specialization and global friend overload, reduced to accessed state.
// CompareText: GUESS(low) STANDIN; for the observed imported two-string comparator; precise identity unknown.
// Target: sse-steam-1-7-104, RVA 0xeb1340; image hash is pinned in builds/target.json.
// AI assistance: gpt-6.1-sol; 2026-11-25. Confidence: medium; independent acceptance pending.
// CI hash: 0xeb1340 ??9@YA_NPEBDAEBVBSFixedString@@@Z
// 0xeb1340 operator!=
#pragma once

class BSFixedString
{
public:
    friend bool operator!=(const char* a_lhs, const BSFixedString& a_rhs);
    const char* data;
};
static_assert(sizeof(BSFixedString) == 8, "string pointer size");
