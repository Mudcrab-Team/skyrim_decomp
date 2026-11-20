// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GHeapID
#pragma once
enum class GHeapID : int {
    kReserved = 0,
    kGlobal = 1,
    kMovieDef = 2,
    kMovieView = 3,
    kMovieData = 4,
    kMeshCache = 5,
    kFontCache = 6,
    kImages = 7,
    kOtherHeaps = 8,
    kHUDHeaps = 9,
};
