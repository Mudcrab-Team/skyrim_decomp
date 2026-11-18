// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// TESBipedModelForm::InitializeDataComponent: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// TESBipedModelForm::ClearDataComponent: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESBipedModelForm.cpp:38
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESBipedModelForm.cpp:48
// 0x1df3e0 TESBipedModelForm::InitializeDataComponent
// 0x1df430 TESBipedModelForm::ClearDataComponent
#include "TESBipedModelForm.h"
void TESBipedModelForm::InitializeDataComponent() { worldModels[0].InitializeDataComponent(); worldModels[1].InitializeDataComponent(); inventoryIcons[0].InitializeDataComponent(); inventoryIcons[1].InitializeDataComponent(); constraintTemplate.InitializeDataComponent(); }
void TESBipedModelForm::ClearDataComponent() { worldModels[0].ClearDataComponent(); worldModels[1].ClearDataComponent(); inventoryIcons[0].ClearDataComponent(); inventoryIcons[1].ClearDataComponent(); constraintTemplate.ClearDataComponent(); }
