// Source exposure: binary-analysis
// DeletingWrapper9f0800, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper9f0800 {
public:
    virtual ~DeletingWrapper9f0800();
};
static_assert(sizeof(DeletingWrapper9f0800) == 8, "interface layout");
