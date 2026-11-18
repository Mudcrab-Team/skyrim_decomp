// Source exposure: binary-analysis
// DeletingWrapper1f7de0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper1f7de0 {
public:
    virtual ~DeletingWrapper1f7de0();
};
static_assert(sizeof(DeletingWrapper1f7de0) == 8, "interface layout");
