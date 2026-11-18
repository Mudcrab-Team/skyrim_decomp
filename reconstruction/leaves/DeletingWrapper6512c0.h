// Source exposure: binary-analysis
// DeletingWrapper6512c0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper6512c0 {
public:
    virtual ~DeletingWrapper6512c0();
};
static_assert(sizeof(DeletingWrapper6512c0) == 8, "interface layout");
