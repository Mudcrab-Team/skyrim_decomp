// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Stand-in declarations: ScriptCompileData, ScriptCompiler, SCRIPT_REFERENCED_OBJECT, BSString, BSSimpleList, TESForm.
// SCRIPT_REFERENCED_OBJECT, BSString, BSSimpleList, TESForm, ScriptCompileData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SCRIPT_REFERENCED_OBJECT::editorID, SCRIPT_REFERENCED_OBJECT::form, SCRIPT_REFERENCED_OBJECT::variableID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ScriptCompileData::VerifyReferencedObjectList, ScriptCompileData::listRefObjects, ScriptCompiler, ScriptCompiler::ScriptError: SIBLING(fo4-private@1b765c70, author-permission)
// BSString::data, BSSimpleList::Node, BSSimpleList::_listHead: GUESS(low); the string pointer, the list head and the node pair as observed
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptCompiler.cpp:231
#pragma once

#include <cstdint>

class TESForm;

struct BSString
{
    const char* data;        // 00
    std::uint8_t unk08[8];   // 08
};

struct SCRIPT_REFERENCED_OBJECT
{
    BSString editorID;        // 00
    TESForm* form;            // 10
    std::uint32_t variableID; // 18
    std::uint32_t pad1C;      // 1C
};

template <class T>
class BSSimpleList
{
public:
    struct Node
    {
        T item;      // 00
        Node* next;  // 08
    };

    Node _listHead;
};

class ScriptCompileData
{
public:
    bool VerifyReferencedObjectList();

    std::uint8_t unk00[0x60];                           // 00
    BSSimpleList<SCRIPT_REFERENCED_OBJECT*> listRefObjects;  // 60
};

class ScriptCompiler
{
public:
    static void ScriptError(ScriptCompileData* apData, const char* aText, ...);
};
