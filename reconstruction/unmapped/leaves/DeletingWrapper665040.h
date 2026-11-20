// Source exposure: binary-analysis
// DeletingWrapper665040, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper665040 {
public:
    virtual ~DeletingWrapper665040();
};
static_assert(sizeof(DeletingWrapper665040) == 8, "interface layout");
