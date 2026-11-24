// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00aa1a40: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct NiFile;

class NiFile
{
  public:
    enum OpenMode
    {
        READ_ONLY,
        WRITE_ONLY,
        APPEND_ONLY
    };
    static NiFile* GetFile(const char*, OpenMode, unsigned int);
    static unsigned int RequestFileAccess(const char*, unsigned int, unsigned int);
};


struct FileAccessObject : NiFile
{
    FileAccessObject(const char*, NiFile::OpenMode, unsigned int);
    virtual ~FileAccessObject();
    unsigned int absolutePosition;
    void* readFunction;
    void* writeFunction;
    unsigned int bufferCapacity;
    unsigned int bufferedBytes;
    unsigned int bufferPosition;
    unsigned int diskPosition;
    char* buffer;
    void* fileHandle;
    NiFile::OpenMode mode;
    bool good;
};

struct Globals
{
};
