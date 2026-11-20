// Source exposure: binary-analysis
// DeletingLeaf846e30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf846e30 {
public:
    virtual ~DeletingLeaf846e30() {}
};
static_assert(sizeof(DeletingLeaf846e30) == 8, "minimal virtual interface size");
