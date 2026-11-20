// Source exposure: binary-analysis
// DeletingLeafb36530, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafb36530 {
public:
    virtual ~DeletingLeafb36530() {}
};
static_assert(sizeof(DeletingLeafb36530) == 8, "minimal virtual interface size");
