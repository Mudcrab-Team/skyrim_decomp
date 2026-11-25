// Source exposure: mixed (pinned image and community PDB names and layouts).
// Code origin: original reconstruction using the compiler-generated deleting destructor.
// Adapted bodies: none
// BSNavmeshSearch: EXE_RTTI
// ~BSNavmeshSearch: CRASHLOGGER_PDB(59818@2026.10.24)
// BSNavmeshSearch size: CRASHLOGGER_PDB(59818@2026.10.24)
// ReleaseSearchState: GUESS(low); out-of-line cleanup on the search object.
#pragma once

class BSNavmeshSearch
{
public:
    BSNavmeshSearch();
    virtual ~BSNavmeshSearch() { ReleaseSearchState(); }

private:
    void ReleaseSearchState() noexcept;
    unsigned char searchState[424];
};

static_assert(sizeof(BSNavmeshSearch) == 432, "search size");
