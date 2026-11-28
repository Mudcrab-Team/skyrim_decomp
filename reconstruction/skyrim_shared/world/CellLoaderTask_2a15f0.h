// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// CellLoaderTask, CellLoaderTask::GetDescription: CRASHLOGGER_PDB(59818@2026.10.24)
// CellForm, FormatDescription, gCellFormFormat, gCellCoordFormat, formID, cell, coordX, coordY, hasCell, unknown00, unknown08: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

void FormatDescription(char* a_buf, std::size_t a_size, const char* a_fmt, ...);
extern const char gCellFormFormat[];
extern const char gCellCoordFormat[];

class CellForm
{
public:
    virtual ~CellForm();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void Slot2F();
    virtual void Slot30();
    virtual void Slot31();
    virtual const char* GetEditorID() const;  // slot 32 (+0x190)

    std::uint8_t unknown08[0xC];
    std::uint32_t formID;  // 14
};
static_assert(offsetof(CellForm, formID) == 0x14, "formID offset");

class CellLoaderTask
{
public:
    bool GetDescription(char* a_buf, std::uint32_t a_size);  // compared: 0x2a15f0

    std::uint8_t unknown00[0x28];
    CellForm* cell;        // 28
    std::int32_t coordX;   // 30
    std::int32_t coordY;   // 34
    std::uint32_t unknown38;
    bool hasCell;          // 3C
};
static_assert(offsetof(CellLoaderTask, cell) == 0x28, "cell offset");
static_assert(offsetof(CellLoaderTask, hasCell) == 0x3C, "hasCell offset");
