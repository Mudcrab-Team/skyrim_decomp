// Source exposure: mixed (pinned community data storage and independent target field-operation/subobject analysis).
// Code origin: adapted community storage declarations, existing original represented-field template bodies and a defaulted owner constructor. No external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{T/TESObjectREFR.h,B/BGSBodyPartData.h,B/BGSBodyPartDefs.h,H/hkpCharacterProxy.h,H/hkArray.h,H/hkVector4.h,N/NonActorMagicTarget.h,B/BSExtraData.h,M/MagicTarget.h,B/BSTList.h}; MIT.
// TESObjectREFR, OBJ_REFR, BGSBodyPartData, hkpCharacterProxy, hkArray, hkVector4, NonActorMagicTarget, BSExtraData, MagicTarget, BSSimpleList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts names ending Layout, PrefixLayout or StorageLayout, storage-only member names and physical views: GUESS(medium) STANDIN
// Explosion ownership hint: GUESS(low) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x69dcd0 represented typed field operation
// 0x7e5160 represented typed field operation
// 0x38b6a0 represented typed field operation
// 0xb9dd70 represented typed field operation
// 0xb9ddd0 represented typed field operation
// 0x17ee20 represented typed field operation
// 0x5d98f0 represented typed field operation
// 0x155350 represented typed field operation
// 0x17bf28 NonActorMagicTarget secondary destructor adjustor
#include "FieldRecoveryStorageLayout.h"
namespace ResearchLayouts {
NonActorMagicTargetRecoveredLayout::NonActorMagicTargetRecoveredLayout() = default;
}
// Build: sse-steam-1-7-104; RVA 0x69dcd0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf69dcd0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf69dcd0.h"
const void* FieldLeaf69dcd0::Read() { return baseObject; }
// Build: sse-steam-1-7-104; RVA 0x7e5160; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf7e5160, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf7e5160.h"
const void* FieldLeaf7e5160::Read() { return baseObject; }
// Build: sse-steam-1-7-104; RVA 0x38b6a0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf38b6a0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf38b6a0.h"
const void* FieldLeaf38b6a0::Read() { return &parts; }
// Build: sse-steam-1-7-104; RVA 0xb9dd70; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeafb9dd70, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeafb9dd70.h"
const void* FieldLeafb9dd70::Read() { return &manifold; }
// Build: sse-steam-1-7-104; RVA 0xb9ddd0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeafb9ddd0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeafb9ddd0.h"
const void* FieldLeafb9ddd0::Read() { return &velocity; }
// Build: sse-steam-1-7-104; RVA 0x17ee20; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf17ee20, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf17ee20.h"
const void* FieldLeaf17ee20::Read() { return targetObject; }
// Build: sse-steam-1-7-104; RVA 0x5d98f0; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf5d98f0, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf5d98f0.h"
const void* FieldLeaf5d98f0::Read() { return &activeEffects; }
// Build: sse-steam-1-7-104; RVA 0x155350; 5 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented declarations and local binary analysis).
// Drafted by tools/represented_field_template_v3.py (GPT-6.1 Sol).
// Labels: v2
// FieldLeaf155350, Read: GUESS(low) STANDIN
// Code origin: original trivial field operation using an included represented layout.
// No external implementation body reused; included declarations retain their own provenance.
// The derived source container adds no fields; original signature and ownership remain unknown.
// Only Read is compared; a pass proves code under the recipe, not names or runtime behavior.
// Origin: {"family": "represented-field-leaf", "template_digest": "28aa4df5d3f8b471a558c1295ab2401ad2e177e85cf3db4c37623395be440057", "version": "3-labels2"}
#include "FieldLeaf155350.h"
const void* FieldLeaf155350::Read() { return menuDispObject; }
// RVA 0x17bf28; 9 bytes
