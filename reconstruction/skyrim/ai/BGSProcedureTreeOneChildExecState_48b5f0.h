// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned procedure code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSProcedureTreeOneChildExecState: STANDIN EXE_RTTI
// BGSLoadGameBuffer, BGSLoadGameBuffer::LoadDataEndian, BGSSaveGameBuffer, BGSSaveGameBuffer::SaveDataEndian: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// child, SaveGame, LoadGame, Slot00..Slot08: GUESS(low)
#pragma once

#include <cstdint>

class BGSLoadGameBuffer
{
public:
    void LoadDataEndian(void* data, std::uint32_t size, std::uint32_t componentSize);
};

class BGSSaveGameBuffer
{
public:
    void SaveDataEndian(const void* data, std::uint32_t size, std::uint32_t componentSize, std::uint32_t version);
};

class BGSProcedureTreeOneChildExecState
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();

protected:
    void SaveGame(BGSSaveGameBuffer& buffer);
    void LoadGame(BGSLoadGameBuffer& buffer);

    BGSProcedureTreeOneChildExecState* child;
};
