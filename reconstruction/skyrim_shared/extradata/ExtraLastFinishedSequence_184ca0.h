// New function names and signatures, unknown global names, and newly split unknown regions: GUESS(low); declarations follow the observed operations.
// Source exposure: mixed (community declarations and the pinned image listing).
// Code origin: original wrapper with partial declarations adapted from CommonLibSSE-NG.
// ExtraLastFinishedSequence, BSExtraData, BSFixedString, lastSequenceName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>

namespace ReconstructedExtraLastFinishedSequence {

#include <cstdint>
class BSExtraData { public: virtual ~BSExtraData(); virtual std::uint32_t GetType() const; virtual bool IsNotEqual(const BSExtraData*) const; BSExtraData* next; };
class BSFixedString { public: BSFixedString& operator=(const char*); const char* data; };
class ExtraLastFinishedSequence : public BSExtraData {
public:
    BSFixedString& Function184ca0(const char* a_name);
 public: BSFixedString lastSequenceName; };


}
