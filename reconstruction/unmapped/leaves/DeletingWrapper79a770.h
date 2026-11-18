// Source exposure: binary-analysis
// DeletingWrapper79a770, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper79a770 {
public:
    virtual ~DeletingWrapper79a770();
};
static_assert(sizeof(DeletingWrapper79a770) == 8, "interface layout");
