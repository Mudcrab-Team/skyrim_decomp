// Source exposure: binary-analysis
// DeletingWrapper1f7e20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper1f7e20 {
public:
    virtual ~DeletingWrapper1f7e20();
};
static_assert(sizeof(DeletingWrapper1f7e20) == 8, "interface layout");
