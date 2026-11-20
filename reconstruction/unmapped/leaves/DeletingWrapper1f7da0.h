// Source exposure: binary-analysis
// DeletingWrapper1f7da0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper1f7da0 {
public:
    virtual ~DeletingWrapper1f7da0();
};
static_assert(sizeof(DeletingWrapper1f7da0) == 8, "interface layout");
