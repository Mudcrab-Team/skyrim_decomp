// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// TESObjectTREE::OnRemove3D: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESObjectTREE.cpp:215
// 0x288480 TESObjectTREE::OnRemove3D
#include "TESObjectTREE.h"
void TESObjectTREE::OnRemove3D(NiAVObject* object) { treeManager->RemoveTree(object); }
