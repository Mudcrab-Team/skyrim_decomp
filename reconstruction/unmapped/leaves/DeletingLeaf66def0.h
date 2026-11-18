// Source exposure: binary-analysis
// DeletingLeaf66def0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66def0 {
public:
    virtual ~DeletingLeaf66def0() {}
};
static_assert(sizeof(DeletingLeaf66def0) == 8, "minimal virtual interface size");
