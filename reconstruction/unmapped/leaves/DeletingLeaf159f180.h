// Source exposure: binary-analysis
// DeletingLeaf159f180, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf159f180 {
public:
    virtual ~DeletingLeaf159f180() {}
};
static_assert(sizeof(DeletingLeaf159f180) == 8, "minimal virtual interface size");
