// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// AddCompileIndex: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/FormComponents/TESForm.cpp:997; adapted control flow.
// Types and method names: GUESS(low); signatures inferred from target calling convention and sibling.
// 0x1e6d00 TESForm::AddCompileIndex
#include "TESForm.h"
void TESForm::AddCompileIndex(unsigned int& id, TESFile* file) {
    if (id - 1 > 0x7fe && file) {
        TESFile* indexFile = file->GetIndexFile((id >> 24) + 1);
        if (!indexFile) indexFile = file;
        indexFile->AdjustFormIDFileIndex(id);
    }
}
