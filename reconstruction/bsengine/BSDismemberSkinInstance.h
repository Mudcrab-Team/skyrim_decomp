// Code origin: original reconstruction from binary analysis by Taylor Turner, assisted by claude-sonnet-5-5; class and member names come from CommonLibSSE-NG (MIT), and no external implementation body or layout is copied.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: binary-analysis (a local listing of the contributor's own copy of the pinned image).
// BSDismemberSkinInstance, BSDismemberSkinInstance::RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiSkinInstance, NiSkinInstance::RegisterStreamables, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the base step is called out of line
#pragma once

class NiStream;

// Stand-in: the base skin instance; only the registration step and its slot are declared.
class NiSkinInstance {
public:
    virtual ~NiSkinInstance();
    virtual bool RegisterStreamables(NiStream& a_stream);
};

class BSDismemberSkinInstance : public NiSkinInstance {
public:
    // The virtual slot order is not compared here; only the body below is.
    bool RegisterStreamables(NiStream& a_stream) override;  // compared: 0xef6180
};
