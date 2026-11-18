// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// NiNode::RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); include/RE/N/NiNode.h.
// NiNode declarations adapted from CommonLibSSE-NG b93280e832f263dbef44e44cbe2936622a02f91a, include/RE/N/NiNode.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); derived class identification is unverified.
#pragma once
class NiStream;
class NiNode { public: bool RegisterStreamables(NiStream&); };
class BSLeafAnimNode : public NiNode { public: bool RegisterStreamables(NiStream&); };
