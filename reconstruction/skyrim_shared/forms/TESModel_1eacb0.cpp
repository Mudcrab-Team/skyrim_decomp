// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// TESModel::CopyComponent: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESModel.cpp:46
// 0x1eacb0 TESModel::CopyComponent
#include "TESModel_1eacb0.h"
void TESModel::CopyComponent(BaseFormComponent* other) { TESModel* model = dynamic_cast<TESModel*>(other); if (model) SetModel(model->GetModel()); }
