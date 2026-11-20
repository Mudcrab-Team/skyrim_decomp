// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image and community declarations.
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// BGSPackageDataBool: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// GetDataAsString, Unk_07, LoadBuffer, LoadPackage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IPackageData, BGSNamedPackageData_VIPackageData: STANDIN EXE_RTTI
// BSString, BGSLoadFormBuffer, BGSSaveGameBuffer, TESFile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the members the compared code calls are declared
// TESFile::GetCurrentSubRecordType, TESFile::ReadData, TESFile::SeekNextSubrecord, BGSLoadGameBuffer::LoadDataEndian, BGSSaveGameBuffer::SaveDataEndian: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// flags08: GUESS(low); bit one holds the boolean value, the image reads and writes it as a qword at 0x08
// BGSNamedPackageData_VIPackageData::LoadPackage: GUESS(low); the base load the image calls first, the name is invented
// SetStringLiteral: GUESS(low); the image calls it with the destination, a text and a zero flag
// IPackageData::~IPackageData, unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSString;
class BGSLoadFormBuffer;
class BGSSaveGameBuffer;
class IPackageData;
class TESFile;

// BGSLoadFormBuffer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only LoadDataEndian is declared
class BGSLoadFormBuffer
{
public:
    void LoadDataEndian(void* a_data, std::uint32_t a_offset, std::uint32_t a_size);  // 0x637e70
};

// BGSSaveGameBuffer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only SaveDataEndian is declared
class BGSSaveGameBuffer
{
public:
    void SaveDataEndian(const void* a_data, std::uint32_t a_size, std::uint32_t a_count, std::uint32_t a_arg4);  // 0x639f00
};

// TESFile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the three methods the compared code calls are declared
class TESFile
{
public:
    std::uint32_t GetCurrentSubRecordType();  // 0x1cdc10
    bool          ReadData(void* a_buf, std::uint32_t a_size);  // 0x1cdd10
    bool          SeekNextSubrecord();  // 0x1cdc60
};

// BSString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque here
class BSString;

// SetStringLiteral: GUESS(low); the image calls it with the destination, the text and a zero flag, and returns its result
bool SetStringLiteral(BSString* a_dst, const char* a_text, std::uint32_t a_flag);

// ReleaseFlags08Slot: GUESS(low); the image calls it with the address of flags08 from the destructor, after clearing its low two bits
void ReleaseFlags08Slot(std::uint64_t* a_slot) noexcept;

class IPackageData
{
public:
    virtual ~IPackageData() {}
};
static_assert(sizeof(IPackageData) == 0x8, "IPackageData size");

class BGSNamedPackageData_VIPackageData : public IPackageData
{
public:
    // LoadPackage: GUESS(low); the base load that BGSPackageDataBool calls first, declared without a body
    void LoadPackage(TESFile* a_mod);

    // PackedName, bits: GUESS(low)
    struct PackedName
    {
        // PackedName::~PackedName, PackedName::operator std::uint64_t, PackedName::operator=: GUESS(low)
        ~PackedName() { ReleaseFlags08Slot(&bits); }
        operator std::uint64_t() const { return bits; }
        PackedName& operator=(std::uint64_t a_bits)
        {
            bits = a_bits;
            return *this;
        }

        std::uint64_t bits;
    };
    // flags08: GUESS(low); bit one holds the boolean value, read and written as a qword by the compared code
    PackedName flags08;  // 08
};
static_assert(sizeof(BGSNamedPackageData_VIPackageData) == 0x10, "BGSNamedPackageData_VIPackageData size");

class BGSPackageDataBool : public BGSNamedPackageData_VIPackageData
{
public:
    virtual std::uint8_t Unk_05() const;
    BGSPackageDataBool();
    virtual bool GetDataAsString(BSString* a_dst) const;  // compared: 0x44d7b0
    virtual void Unk_07(BGSSaveGameBuffer* a_buf);  // compared: 0x44d980
    virtual ~BGSPackageDataBool();  // compared: 0x44e660 (scalar deleting destructor)
    virtual void LoadBuffer(BGSLoadFormBuffer* a_buf);  // compared: 0x44d9c0
    virtual void Assign(IPackageData* a_other);  // compared: 0x44d7e0
    virtual void LoadPackage(TESFile* a_mod);  // compared: 0x44d8e0
    virtual bool IsNotEqual(IPackageData* a_other) const;  // compared: 0x44d840
};
static_assert(sizeof(BGSPackageDataBool) == 0x10, "BGSPackageDataBool size");
