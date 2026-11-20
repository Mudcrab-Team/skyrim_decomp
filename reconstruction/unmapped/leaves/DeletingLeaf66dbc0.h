// Source exposure: binary-analysis
// DeletingLeaf66dbc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66dbc0 {
public:
    virtual ~DeletingLeaf66dbc0() {}
};
static_assert(sizeof(DeletingLeaf66dbc0) == 8, "minimal virtual interface size");
