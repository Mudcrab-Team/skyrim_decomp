// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// TESObjectTREE, BSTreeManager, RemoveTree, treeManager: GUESS(low); global and call sites corroborated by target.
#pragma once
class NiAVObject; class BSTreeManager { public: void RemoveTree(NiAVObject*); }; extern BSTreeManager* treeManager; class TESObjectTREE { public: void OnRemove3D(NiAVObject*); };
