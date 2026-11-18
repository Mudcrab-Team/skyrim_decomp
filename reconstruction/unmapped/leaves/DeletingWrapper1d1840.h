// Source exposure: binary-analysis
// DeletingWrapper1d1840, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper1d1840 {
public:
    virtual ~DeletingWrapper1d1840();
};
static_assert(sizeof(DeletingWrapper1d1840) == 8, "interface layout");
