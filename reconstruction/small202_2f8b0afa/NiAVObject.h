// Origin: adapted declarations from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT, include/RE/N/NiAVObject.h; body is original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiAVObject, PreAttachUpdate, UpdateControllers, PerformOp, AttachProperty, SetMaterialNeedsUpdate, SetDefaultMaterialNeedsUpdateFlag, GetObjectByName, SetSelectiveUpdateFlags, UpdateDownwardPass, parent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAVObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include "netimmerse/NiObjectNET.h"
class NiNode;
class NiUpdateData;
class PerformOpFunc;
class NiAlphaProperty;
class NiAVObject : public NiObjectNET {
public:
 virtual void UpdateControllers(NiUpdateData&);
 virtual void PerformOp(PerformOpFunc&);
 virtual void AttachProperty(NiAlphaProperty*);
 virtual void SetMaterialNeedsUpdate(bool);
 virtual void SetDefaultMaterialNeedsUpdateFlag();
 virtual NiAVObject* GetObjectByName(const BSFixedString&);
 virtual void SetSelectiveUpdateFlags(bool&, bool, bool&);
 virtual void UpdateDownwardPass(NiUpdateData&, std::uint32_t);
 void PreAttachUpdate(NiNode*, NiUpdateData&);
 NiNode* parent;
};
