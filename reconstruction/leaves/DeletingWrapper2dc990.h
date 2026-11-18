// Source exposure: binary-analysis
// DeletingWrapper2dc990, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper2dc990 {
public:
    virtual ~DeletingWrapper2dc990();
};
static_assert(sizeof(DeletingWrapper2dc990) == 8, "interface layout");
