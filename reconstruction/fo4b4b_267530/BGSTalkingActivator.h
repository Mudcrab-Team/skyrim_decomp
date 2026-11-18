// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// BGSTalkingActivator::Revert: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/BGSTalkingActivator.cpp:168
// BGSTalkingActivator, TESObjectACTI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESObjectACTI.h, include/RE/T/TESBoundObject.h, include/RE/T/TESForm.h and public component headers.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
class Component { public: virtual ~Component(); };
class TESForm : public Component { public: void* files; unsigned formFlags, id; unsigned short inGameFlags; unsigned char type, pad; unsigned pad2; void Revert(void*); };
struct ShortPoint { short x,y,z; };
class TESBoundObject : public TESForm { public: ShortPoint min, max; unsigned pad; };
class TESBoundAnimObject : public TESBoundObject {};
class TESFullName : public Component { public: const char* name; };
class TESModel : public Component { public: const char* model; void* textures; unsigned* addons; unsigned short numTextures, numAddons; unsigned pad; };
class TESModelTextureSwap : public TESModel { public: void* alternateTextures; unsigned count, pad; };
class TESMagicTargetForm {};
class BGSDestructibleObjectForm : public Component { public: void* data; };
class BGSOpenCloseForm { public: virtual ~BGSOpenCloseForm(); };
class BGSKeywordForm : public Component { public: void** keywords; unsigned count; };
class TESObjectACTI : public TESBoundAnimObject, public TESFullName, public TESModelTextureSwap, public TESMagicTargetForm, public BGSDestructibleObjectForm, public BGSOpenCloseForm, public BGSKeywordForm { public: void* soundLoop; void* soundActivate; void* waterForm; unsigned short flags, padc2; unsigned padc4; void ClearData(); };
template<class T> struct Array { T* data; unsigned capacity, allocatorPad, size, sizePad; void Deallocate(); void Clear() { if (data) Deallocate(); size = 0; } };
class BGSLoadGameBuffer { public: virtual ~BGSLoadGameBuffer(); void* buffer; unsigned long long unknown10; unsigned unknown18, unknown1c, unknown20, bufferPosition; }; struct BGSLoadFormData { unsigned formID, size, uncompressedSize, pad; TESForm* form; unsigned changeFlags, oldChangeFlags, flags; unsigned char pad22, version; }; class BGSLoadFormBuffer : public BGSLoadGameBuffer, public BGSLoadFormData {};
class BGSTalkingActivator : public TESObjectACTI { public: void* tempRef; void Revert(BGSLoadFormBuffer*); };
