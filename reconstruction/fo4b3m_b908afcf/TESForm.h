// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// AddCompileIndex: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/FormComponents/TESForm.cpp:997; adapted control flow.
// Types and method names: GUESS(low); signatures inferred from target calling convention and sibling.
#pragma once
class TESFile { public: TESFile* GetIndexFile(unsigned int); void AdjustFormIDFileIndex(unsigned int&); };
class TESForm { public: static void AddCompileIndex(unsigned int&, TESFile*); };
