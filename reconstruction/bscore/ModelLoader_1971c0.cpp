// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x1971c0 ModelLoader::BuildNIFFileList
// Adapted bodies: ModelLoader::BuildNIFFileList from fo4-private@1b765c70 src/Shared/FileIO/ModelLoader.cpp:244 (see the header)
#include "ModelLoader_1971c0.h"

#include <string.h>

BSSimpleList<const char*>* ModelLoader::BuildNIFFileList(const char* a_baseFilename)
{
    char searchName[260];

    strcpy_s(searchName, 0x104u, "Data\\Meshes\\");
    strcat_s(searchName, 0x104u, a_baseFilename);
    char* result = strrchr(searchName, '\\');
    if (!result)
        return nullptr;

    strcpy_s(result, searchName + sizeof(searchName) - result, "\\*.NIF");
    return FileFinder::BuildFileList(searchName, a_baseFilename, FileFinder::HARDDRIVE, nullptr);
}
