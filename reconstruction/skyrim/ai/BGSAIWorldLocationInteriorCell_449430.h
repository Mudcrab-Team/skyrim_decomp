// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSAIWorldLocationCell.cpp:102
// BGSAIWorldLocationInteriorCell, BGSAIWorldLocationInteriorCell::LoadGame, BGSLoadFormBuffer: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESForm, TESObjectCELL: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// TESForm::LookupByID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSLoadFormBuffer::LoadFormID, BGSLoadFormBuffer::LoadDataEndian: GUESS(low); the names are the ones the sibling body calls
// BGSAIWorldLocationInteriorCell::cell, BGSAIWorldLocationInteriorCell::point, AIWorldPoint: GUESS(low)
#pragma once

class TESForm
{
public:
    virtual ~TESForm();

    static TESForm* LookupByID(unsigned int a_formID);
};

class TESObjectCELL : public TESForm
{
};

class BGSLoadFormBuffer
{
public:
    void LoadFormID(unsigned int& a_formID);

    template <class T>
    void LoadFormID(T*& a_form)
    {
        unsigned int formID = 0;
        LoadFormID(formID);
        a_form = dynamic_cast<T*>(TESForm::LookupByID(formID));
    }

    void LoadDataEndian(void* a_data, unsigned int a_size, unsigned int a_width);
};

struct AIWorldPoint
{
    float x;  // 00
    float y;  // 04
    float z;  // 08
};

class BGSAIWorldLocationInteriorCell
{
public:
    virtual ~BGSAIWorldLocationInteriorCell();
    virtual void LoadGame(BGSLoadFormBuffer* a_buffer);

    TESObjectCELL* cell;  // 08
    AIWorldPoint point;   // 10
};
