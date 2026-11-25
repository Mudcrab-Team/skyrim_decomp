// Source exposure: mixed (pinned image and community PDB names and layouts).
// Code origin: original reconstruction using the compiler-generated deleting destructor.
// Adapted bodies: none
// BSNavmeshInfoSearch: EXE_RTTI
// ~BSNavmeshInfoSearch: CRASHLOGGER_PDB(59818@2026.10.24)
// BSNavmeshInfoSearch size: CRASHLOGGER_PDB(59818@2026.10.24)
// ReleaseSearchState: GUESS(low); out-of-line cleanup on the search object.
#pragma once

class BSNavmeshInfoSearch
{
public:
    BSNavmeshInfoSearch();
    virtual ~BSNavmeshInfoSearch() { ReleaseSearchState(); }

private:
    void ReleaseSearchState() noexcept;
    unsigned char searchState[560];
};

static_assert(sizeof(BSNavmeshInfoSearch) == 568, "search size");
