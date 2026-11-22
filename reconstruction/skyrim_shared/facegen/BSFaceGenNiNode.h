// Source exposure: mixed (pinned image listing, sibling hint, community declarations).
// Code origin: existing sibling-adapted method plus original reconstruction of Function43d080.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFaceGenNiNode, NiNode, NiAVObject, NiObjectNET, NiObject, NiRefObject, NiTObjectArray, NiTransform, NiBound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function43d080, Helper43d930: GUESS(low)
#pragma once
struct NiPoint3 { float x,y,z; }; struct NiMatrix3 { float entry[3][3]; }; struct NiTransform { NiMatrix3 rotate; NiPoint3 translate; float scale; }; struct NiBound { NiPoint3 center; float radius; };
class NiTimeController; class NiExtraData; class NiCollisionObject; class TESObjectREFR; class NiUpdateData; class NiNode;
class NiRefObject { public: virtual ~NiRefObject(); unsigned refCount; };
class NiObject : public NiRefObject {};
class NiObjectNET : public NiObject { public: const char* name; NiTimeController* controllers; NiExtraData** extra; unsigned short extraDataSize, maxSize; unsigned pad; };
class NiAVObject : public NiObjectNET { public: NiNode* parent; unsigned parentIndex, unknown; NiCollisionObject* collision; NiTransform local, world, previousWorld; NiBound worldBound; unsigned flags; TESObjectREFR* userData; float fadeAmount; unsigned lastUpdatedFrameCounter; unsigned char unknown108, flags02; unsigned short unknown10A; unsigned pad10C; };
template<class T> class NiTObjectArray { public: virtual ~NiTObjectArray(); T* data; unsigned short capacity, freeIndex, size, growthSize; };
class NiNode : public NiAVObject { public: void UpdateDownwardPass(NiUpdateData&, unsigned); NiTObjectArray<NiAVObject*> children; };
class BSFaceGenNiNode : public NiNode { public: void UpdateMorphing(NiUpdateData&); void UpdateDownwardPass(NiUpdateData&, unsigned); void Helper43d930(bool*); void Function43d080(); };
