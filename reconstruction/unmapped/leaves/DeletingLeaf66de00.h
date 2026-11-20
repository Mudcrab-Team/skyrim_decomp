// Source exposure: binary-analysis
// DeletingLeaf66de00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66de00 {
public:
    virtual ~DeletingLeaf66de00() {}
};
static_assert(sizeof(DeletingLeaf66de00) == 8, "minimal virtual interface size");
