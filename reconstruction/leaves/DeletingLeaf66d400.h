// Source exposure: binary-analysis
// DeletingLeaf66d400, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66d400 {
public:
    virtual ~DeletingLeaf66d400() {}
};
static_assert(sizeof(DeletingLeaf66d400) == 8, "minimal virtual interface size");
