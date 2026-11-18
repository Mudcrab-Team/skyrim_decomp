// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// CombatInventoryItem, CombatInventoryItemMelee, CombatInventoryItemShield, maxRange, scale, equipRange: GUESS(low); range field inferred from target.
/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#pragma once
class TESForm; class BGSEquipSlot; class BGSSaveGameBuffer; class BGSLoadGameBuffer;
class NiRefObject { public: virtual ~NiRefObject(); virtual void DeleteThis(); volatile unsigned int refCount; }; class CombatObject: public NiRefObject { public: virtual unsigned int GetObjectType()=0; virtual void SaveGame(BGSSaveGameBuffer*); virtual void LoadGame(BGSLoadGameBuffer*); }; struct CombatInventoryItemSlot { BGSEquipSlot* equipSlot; unsigned int slot; }; class CombatInventoryItem: public CombatObject { public: virtual float GetMinRange(); virtual float GetMaxRange(); virtual float GetOptimalRange(); virtual float GetEquipRange(); TESForm* item; float itemScore; CombatInventoryItemSlot itemSlot; };
class CombatInventoryItemShield: public CombatInventoryItem { public: float GetMaxRange() override; float GetOptimalRange() override; float GetEquipRange() override; float maxRange; };
extern float optimalRangeScale; extern float equipRange;
