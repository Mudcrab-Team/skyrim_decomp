// Source exposure: binary-analysis
// DeletingWrapper1e77c0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper1e77c0 {
public:
    virtual ~DeletingWrapper1e77c0();
};
static_assert(sizeof(DeletingWrapper1e77c0) == 8, "interface layout");
