// Source exposure: binary-analysis
// DeletingWrapperce90a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapperce90a0 {
public:
    virtual ~DeletingWrapperce90a0();
};
static_assert(sizeof(DeletingWrapperce90a0) == 8, "interface layout");
