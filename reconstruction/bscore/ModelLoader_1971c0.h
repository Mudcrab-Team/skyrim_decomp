// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/ModelLoader.cpp:244
// ModelLoader, ModelLoader::BuildNIFFileList: SIBLING(fo4-private@1b765c70, author-permission)
// FileFinder: CRASHLOGGER_PDB(59818@2026.10.24) STANDIN
// FileFinder::BuildFileList, FileFinder::HARDDRIVE: GUESS(medium); names from the sibling call site
// BSSimpleList: GUESS(low); stand-in, only used by pointer
#pragma once

#include <cstdint>
#include <cstddef>

template <class T>
class BSSimpleList;

class FileFinder
{
public:
    enum
    {
        HARDDRIVE = 1
    };

    static BSSimpleList<const char*>* BuildFileList(const char* a_searchName, const char* a_baseFilename, unsigned int a_source, BSSimpleList<const char*>* a_fileList);
};

class ModelLoader
{
public:
    BSSimpleList<const char*>* BuildNIFFileList(const char* a_baseFilename);
};
