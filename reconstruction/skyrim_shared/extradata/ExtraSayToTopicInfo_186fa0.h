// New function names and signatures, unknown global names, and newly split unknown regions: GUESS(low); declarations follow the observed operations.
// Source exposure: mixed (community declarations and the pinned image listing).
// Code origin: partial declarations adapted from CommonLibSSE-NG; the new reset body is original.
// ExtraSayToTopicInfo, BSExtraData, BSSoundHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>

namespace ReconstructedExtraSayToTopicInfo {

#include <cstdint>
class TESTopic; class BGSDialogueBranch; class DialogueItem;
class BSExtraData { public: virtual ~BSExtraData(); virtual std::uint32_t GetType() const; virtual bool IsNotEqual(const BSExtraData*) const; BSExtraData* next; };
struct BSSoundHandle { std::uint32_t soundID; bool assumeSuccess; std::uint32_t state; };
class ExtraSayToTopicInfo : public BSExtraData {
public:
    void Function186fa0();
 public: TESTopic* topic; bool voicePaused; float subtitleSpeechDelay; BGSDialogueBranch* exclusiveBranch; BSSoundHandle sound; DialogueItem* item; };


}
