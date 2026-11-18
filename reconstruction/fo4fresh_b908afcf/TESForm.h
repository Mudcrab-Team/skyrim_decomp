// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESForm.cpp:766 (TESForm::RemoveChange)
// TESForm, RemoveChange: GUESS(low)
#pragma once
// SaveLoadGame, saveLoad, RemoveChange, flags: GUESS(low)
class TESForm;
class SaveLoadGame { public: void RemoveChange(TESForm*, int); };
extern SaveLoadGame* saveLoad;
class TESForm { public: void RemoveChange(int flags); };
