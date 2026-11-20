// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/I/Inventory3DManager.h, include/RE/I/InventoryEntryData.h and include/RE/B/BSTList.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); target callees and signatures are inferred independently from the target call sequence.
#pragma once
class TESBoundObject; class ExtraDataList;
template<class T> struct BSSimpleList { T item; BSSimpleList* next; };
class InventoryEntryData { public: TESBoundObject* object; BSSimpleList<ExtraDataList*>* extraLists; int countDelta; };
class Inventory3DManager { public: void LoadInventoryItem(InventoryEntryData*); void LoadInventoryItem(TESBoundObject*, ExtraDataList*); };
