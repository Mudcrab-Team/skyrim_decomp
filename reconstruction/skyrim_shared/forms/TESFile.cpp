// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction; other bodies drafted as noted in the header.
// SPDX-License-Identifier: CC0-1.0
// 0x1cdf30 TESFile::Function1cdf30
// Function1cdf30, Function1cdd10Stub: GUESS(low)
// Adapted bodies: none
// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image, with the class layout from the header beside this file. SeekNextSubrecord, Duplicate and Seek were finished by claude-opus-5-5 from the Drafter's near-misses.
// GetCurrentThreadId, GetLastError, FormatMessageA, LocalFree: STANDIN OBSERVED; Win32 imports of the image, declared locally
#include "TESFile.h"

#include <cstring>

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
extern "C" __declspec(dllimport) unsigned long __stdcall FormatMessageA(unsigned long a_flags,
    const void* a_source, unsigned long a_messageId, unsigned long a_languageId, char* a_buffer,
    unsigned long a_size, void* a_arguments);
extern "C" __declspec(dllimport) void* __stdcall LocalFree(void* a_mem);

extern bool                 g_threadSafeFiles;
extern std::uint32_t        g_tes4RecordType;
extern const std::uint32_t  g_seekOrigin;
FormType                    ConvertFormType(std::uint32_t a_recordType);
void                        Function1cdd10Stub(TESFile* a_self, std::uint32_t a_arg, std::uint32_t a_zero);
Main*                       Main::singleton;

namespace {
    const std::uint32_t kCompressedFlag = 0x00040000;
}

void TESFile::EnsureOpen()
{
    if (!g_threadSafeFiles || !unk029) {
        if (file) {
            return;
        }
    } else if (unk018) {
        return;
    }
    OpenTES(NiFile::OpenMode::kReadOnly, false);
}

bool TESFile::OpenTES(NiFile::OpenMode a_accessMode, bool a_lock)
{
    return OpenInternal(path, fileName, a_accessMode, a_lock);
}

std::uint32_t TESFile::GetCurrentSubRecordType()
{
    if (currentchunkID == 0 && !ReadChunkHeader()) {
        return 0;
    }
    return currentchunkID;
}

FormType TESFile::GetFormType()
{
    if (currentform.form == 0) {
        if (!ReadFormHeader()) {
            return FormType::None;
        }
        currentchunkID = 0;
        actualChunkSize = 0;
        ReadChunkHeader();
    }
    return ConvertFormType(currentform.form);
}

bool TESFile::IsCompressed() const
{
    return currentform.form != g_tes4RecordType && (currentform.flags & kCompressedFlag) != 0;
}

bool TESFile::SeekNextSubrecord()
{
    std::uint32_t limit = currentform.length;
    if (IsCompressed()) {
        limit = decompressedFormBufferSize;
    }
    formoffset += actualChunkSize + 6;
    if (formoffset >= limit) {
        currentchunkID  = 0;
        actualChunkSize = 0;
        return false;
    }
    // a compressed record is read from the decompressed buffer, so only plain records seek the file
    const std::uint32_t position = fileOffset + formoffset + sizeof(FORM);
    if (!IsCompressed()) {
        SeekRaw(position, g_seekOrigin);
    }
    chunkoffset     = 0;
    currentchunkID  = 0;
    actualChunkSize = 0;
    ReadChunkHeader();
    return true;
}

TESFile* TESFile::GetRootFile(TESFile* a_file)
{
    while (a_file && a_file->threadSafeParent) {
        a_file = a_file->threadSafeParent;
    }
    return a_file;
}

TESFile* TESFile::Duplicate(std::uint32_t a_cacheSize)
{
    EnsureOpen();
    TESFile* root = this;
    while (GetRootFile(root->threadSafeParent)) {
        root = GetRootFile(root->threadSafeParent);
    }
    if (GetCurrentThreadId() == Main::singleton->threadID) {
        return root;
    }
    return root->DuplicateForThread(GetCurrentThreadId(), a_cacheSize);
}

std::uint32_t TESFile::QueryFilePosition()
{
    if (g_threadSafeFiles && unk029) {
        if (!unk018) {
            return 0;
        }
        return unk024;
    }
    if (!file) {
        return 0;
    }
    std::uint32_t position = file->auxTrueFilePos;
    if (position == 0xFFFFFFFF) {
        position = file->trueFilePos;
    }
    return position;
}

void TESFile::Function1cdf30(std::uint32_t a_arg)
{
    return Function1cdd10Stub(this, a_arg, 0);
}

bool TESFile::Seek(std::uint32_t a_offset)
{
    EnsureOpen();
    if (decompressedFormBuffer) {
        decompressedFormBuffer     = nullptr;
        decompressedFormBufferSize = 0;
    }
    fileOffset = a_offset;
    if (a_offset >= filesize) {
        std::memset(&currentform, 0, sizeof(currentform));
        return false;
    }
    SeekRaw(a_offset, g_seekOrigin);
    fileOffset = QueryFilePosition();
    if (fileOffset == 0xFFFFFFFF) {
        // the failure text is formatted and released but never kept
        char* message;
        FormatMessageA(0x1300, nullptr, GetLastError(), 0x400, reinterpret_cast<char*>(&message), 0, nullptr);
        LocalFree(message);
        return false;
    }
    formoffset = 0;
    chunkoffset = 0;
    std::memset(&currentform, 0, sizeof(currentform));
    GetFormType();
    return true;
}
