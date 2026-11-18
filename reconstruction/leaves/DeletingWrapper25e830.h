// Source exposure: binary-analysis
// DeletingWrapper25e830, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper25e830 {
public:
    virtual ~DeletingWrapper25e830();
};
static_assert(sizeof(DeletingWrapper25e830) == 8, "interface layout");
