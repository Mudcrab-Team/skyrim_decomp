// Source exposure: mixed (pinned listing, community names and the labelled sibling sources).
// Code origin: original reconstruction and the sibling adaptations cited below. Stamped as a twin of matched 0x1a4670 (bsmain/TES): source copied, names replaced by placeholders.
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:158 (TES::GetLandMaterialType)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:702 (TES::ResumeMasterFileLoads)
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TES.cpp:695 (TES::CancelMasterFileLoads)
// 0x6e5280 Owner6e5280::Function6e5280
#include "Owner6e5280.h"

// guess: same compiled code as matched 0x1a4670 apart from relocated fields; its role here is not established.
void Owner6e5280::Function6e5280() { loader->CancelAllCellLoads(); BGSDynamicPersistenceManager::instance->Pause(); }
