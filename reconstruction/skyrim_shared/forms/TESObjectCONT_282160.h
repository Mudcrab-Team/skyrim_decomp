// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// TESObjectCONT, TESObjectCONT::HandleClose, TESObjectCONT::openSound, TESObjectCONT::closeSound: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSOpenCloseForm, BGSOpenCloseForm::HandleOpen, ::HandleClose, ::Unk_03: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the secondary base at 0xB0
// TESObjectCONTPrefix, unknownB8, ContainerFunction282480: GUESS(low); the image passes the secondary base, so the owner is this - 0xB0, and calls 0x282480 with the close sound
#pragma once

#include <cstdint>

class BGSSoundDescriptorForm;
class TESObjectCONT;
class TESObjectREFR;

class TESObjectCONTPrefix
{
public:
	virtual ~TESObjectCONTPrefix();

	std::uint8_t unknown08[0xA8];  // 08
};

class BGSOpenCloseForm
{
public:
	virtual ~BGSOpenCloseForm();                                                     // 00
	virtual void HandleOpen(TESObjectREFR* a_target, TESObjectREFR* a_activator);   // 01
	virtual void HandleClose(TESObjectREFR* a_target, TESObjectREFR* a_activator);  // 02
	virtual void Unk_03();                                                           // 03
};
static_assert(sizeof(BGSOpenCloseForm) == 0x8, "BGSOpenCloseForm size");

class TESObjectCONT : public TESObjectCONTPrefix, public BGSOpenCloseForm
{
public:
	void HandleClose(TESObjectREFR* a_target, TESObjectREFR* a_activator) override;  // B0 slot 02, compared: 0x282160

	std::uint8_t            unknownB8[0x8];  // B8
	BGSSoundDescriptorForm* openSound;       // C0
	BGSSoundDescriptorForm* closeSound;      // C8
};

void ContainerFunction282480(BGSSoundDescriptorForm* a_sound, TESObjectREFR* a_target, TESObjectCONT* a_owner);
