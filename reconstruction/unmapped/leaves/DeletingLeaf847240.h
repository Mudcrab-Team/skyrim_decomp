// Source exposure: binary-analysis
// DeletingLeaf847240, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf847240 {
public:
    virtual ~DeletingLeaf847240() {}
};
static_assert(sizeof(DeletingLeaf847240) == 8, "minimal virtual interface size");
