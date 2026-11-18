// Source exposure: binary-analysis
// DeletingLeaf843880, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf843880 {
public:
    virtual ~DeletingLeaf843880() {}
};
static_assert(sizeof(DeletingLeaf843880) == 8, "minimal virtual interface size");
