// Source exposure: binary-analysis
// DeletingLeaf66dcf0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66dcf0 {
public:
    virtual ~DeletingLeaf66dcf0() {}
};
static_assert(sizeof(DeletingLeaf66dcf0) == 8, "minimal virtual interface size");
