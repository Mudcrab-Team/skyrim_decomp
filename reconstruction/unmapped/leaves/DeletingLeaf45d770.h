// Source exposure: binary-analysis
// DeletingLeaf45d770, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf45d770 {
public:
    virtual ~DeletingLeaf45d770() {}
};
static_assert(sizeof(DeletingLeaf45d770) == 8, "minimal virtual interface size");
