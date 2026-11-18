// Source exposure: binary-analysis
// DeletingWrapper1d1880, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper1d1880 {
public:
    virtual ~DeletingWrapper1d1880();
};
static_assert(sizeof(DeletingWrapper1d1880) == 8, "interface layout");
