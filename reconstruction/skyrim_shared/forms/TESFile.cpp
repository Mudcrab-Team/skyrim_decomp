// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: brown-room reconstruction from disassembly (ReadFormHeader); original otherwise; no sibling code reused
// 0x1cf0f0 TESFile::ReadFormHeader
// Adapted bodies: none
// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image, with the class layout from the header beside this file. SeekNextSubrecord, Duplicate and Seek were finished by claude-opus-5-5 from the Drafter's near-misses.
// GetCurrentThreadId, GetLastError, FormatMessageA, LocalFree: STANDIN OBSERVED; Win32 imports of the image, declared locally
// 0x1ca460 TESFile::OpenTES
// 0x1cdc10 TESFile::GetCurrentSubRecordType
// 0x1cd7d0 TESFile::GetFormType
// 0x1cdc60 TESFile::SeekNextSubrecord
// 0x1ce7e0 TESFile::Duplicate
// 0x1cd860 TESFile::Seek
#include "TESFile.h"

#include <cstddef>
#include <cstring>
#include <intrin.h>

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
extern "C" __declspec(dllimport) unsigned long __stdcall FormatMessageA(unsigned long a_flags,
    const void* a_source, unsigned long a_messageId, unsigned long a_languageId, char* a_buffer,
    unsigned long a_size, void* a_arguments);
extern "C" __declspec(dllimport) void* __stdcall LocalFree(void* a_mem);

extern bool                 g_threadSafeFiles;
extern std::uint32_t        g_tes4RecordType;
extern std::uint32_t        g_secondRecordType;
bool                        IsReservedFormID(std::uint32_t a_formID);
void                        CopyBytes(void* a_dest, std::size_t a_destSize, const void* a_src, std::size_t a_count);
extern const std::uint32_t  g_seekOrigin;
FormType                    ConvertFormType(std::uint32_t a_recordType);
Main*                       Main::singleton;

// IsReservedFormID, CopyBytes, g_secondRecordType: GUESS(low); callees at RVAs 0x1e6600 and 0x10c240 and a global at 0x2078a30, no community name
// CopyBytes: GUESS(low); its two sizes are taken as pointer-width counts (the caller widens them)
namespace {
    // TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
    inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
    {
        return ((a_flags >> a_bit) & 1) != 0;
    }

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

bool TESFile::ReadFormHeader()
{
    if (!IsOpen()) {
        return false;
    }
    FORM*         header = &currentform;
    std::uint32_t count  = 0;
    if (g_threadSafeFiles && unk029) {
        void* handle = unk018;
        if (handle) {
            if (unk024 < unk020) {
                count = (unk024 + 0x18 > unk020) ? unk020 - unk024 : 0x18;
                CopyBytes(header, count, static_cast<char*>(handle) + unk024, count);
                unk024 += count;
            }
        }
    } else if (file) {
        count = file->Read(header, 0x18);
    }
    if (count == 0x18) {
        if (bigEndian) {
            // byte-swap intrinsics: the image swaps each header field of a big-endian file
            std::uint32_t* words = reinterpret_cast<std::uint32_t*>(header);
            for (std::uint32_t i = 0; i < 5; ++i) {
                // byte-swap intrinsic: swaps one 32-bit header field
                words[i] = _byteswap_ulong(words[i]);
            }
            // byte-swap intrinsics: the two 16-bit fields at the end of the header
            // byte-swap intrinsic: swaps the 16-bit version field
            header->formVersion = _byteswap_ushort(header->formVersion);
            // byte-swap intrinsic: swaps the 16-bit control version field
            header->vcVersion   = _byteswap_ushort(header->vcVersion);
        }
        if (currentform.form == g_tes4RecordType || currentform.form == g_secondRecordType) {
            return true;
        }
        TESFile* owner = FindMaster(reinterpret_cast<std::uint8_t*>(&currentform.formID)[3]);
        if (!owner) {
            owner = this;
        }
        if (IsReservedFormID(currentform.formID)) {
            return true;
        }
        reinterpret_cast<std::uint8_t*>(&currentform.formID)[3] = 0;
        if (TestBit(owner->flags, 9)) {
            const std::uint32_t low = (currentform.formID & 0xFFF) | 0xFE000000;
            currentform.formID = low;
            currentform.formID = (static_cast<std::uint32_t>(owner->smallFileCompileIndex) << 12) | low;
            return true;
        }
        currentform.formID |= static_cast<std::uint32_t>(owner->compileIndex) << 24;
        return true;
    }
    std::memset(header, 0, sizeof(FORM));
    return false;
}

bool TESFile::IsOpen() const
{
    if (!g_threadSafeFiles || !unk029) {
        if (file) {
            return true;
        }
    } else if (unk018) {
        return true;
    }
    return false;
}

TESFile* TESFile::FindMaster(std::uint8_t a_index) const
{
    TESFile* owner = nullptr;
    if (TESFile** masters = masterPtrs) {
        const std::uint32_t index = static_cast<std::uint32_t>(a_index) + 1;
        if (index > masterCount) {
            return nullptr;
        }
        owner = masters[index - 1];
    }
    return owner;
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
