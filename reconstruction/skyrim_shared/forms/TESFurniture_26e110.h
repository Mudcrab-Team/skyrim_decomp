// Code origin: declarations extended by hand from the local listings; names follow the community headers.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// TESFurniture, TESObjectACTI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESObjectACTI.h, include/RE/T/TESBoundObject.h, include/RE/T/TESForm.h and public component headers.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESFurniture::InitializeData, TESFurniture::Clone3D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); names only, the bodies are written from the target listing
// g_furnitureCloneFlag: GUESS(low); global byte at address 0x20b6130 that gates the extra step in Clone3D
// TESFurniture::Unk26f900: GUESS(low); address 0x26f900, called with the cloned node when the flag is set
// workBenchData, padE2, furnFlags, associatedForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); names and offsets E0 to E8 from include/RE/T/TESFurniture.h; types simplified, the compared InitializeData clears furnFlags and associatedForm
#pragma once
class Component { public: virtual ~Component(); };
class TESForm : public Component { public: void* files; unsigned formFlags, id; unsigned short inGameFlags; unsigned char type, pad; unsigned pad2; void Revert(void*); };
struct ShortPoint { short x,y,z; };
class NiAVObject; class TESObjectREFR;
class TESBoundObject : public TESForm { public: virtual NiAVObject* Clone3D(TESObjectREFR* a_ref); ShortPoint min, max; unsigned pad; };
class TESBoundAnimObject : public TESBoundObject {};
class TESFullName : public Component { public: const char* name; };
class TESModel : public Component { public: const char* model; void* textures; unsigned* addons; unsigned short numTextures, numAddons; unsigned pad; };
class TESModelTextureSwap : public TESModel { public: void* alternateTextures; unsigned count, pad; };
class TESMagicTargetForm {};
class BGSDestructibleObjectForm : public Component { public: void* data; };
class BGSOpenCloseForm { public: virtual ~BGSOpenCloseForm(); };
class BGSKeywordForm : public Component { public: void** keywords; unsigned count; };
class TESObjectACTI : public TESBoundAnimObject, public TESFullName, public TESModelTextureSwap, public TESMagicTargetForm, public BGSDestructibleObjectForm, public BGSOpenCloseForm, public BGSKeywordForm { public: void* soundLoop; void* soundActivate; void* waterForm; unsigned short flags, padc2; unsigned padc4; void ClearData(); virtual void InitializeData(); };
template<class T> struct Array { T* data; unsigned capacity, allocatorPad, size, sizePad; void Deallocate(); void Clear() { if (data) { Deallocate(); size = 0; } } };
class TESFurniture : public TESObjectACTI { public: struct EntryPointData; Array<EntryPointData> entryPointDataArray; unsigned short workBenchData, padE2; unsigned furnFlags; void* associatedForm; void ClearData(); void InitializeData() override; NiAVObject* Clone3D(TESObjectREFR* a_ref) override; void Unk26f900(NiAVObject* a_node); };
static_assert(sizeof(TESObjectACTI) == 0xC8, "layout");
static_assert(sizeof(TESFurniture) == 0xF0, "layout");
extern bool g_furnitureCloneFlag;
