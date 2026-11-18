// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// BGSEquipType::CopyComponent: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/BGSEquipType.cpp:65
// 0x1d72b0 BGSEquipType::CopyComponent
#include "BGSEquipType.h"
void BGSEquipType::CopyComponent(BaseFormComponent* other) { BGSEquipType* type = dynamic_cast<BGSEquipType*>(other); if (type) SetEquipSlot(type->GetEquipSlot()); }
