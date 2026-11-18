// Source exposure: mixed; binary analysis, CommonLibSSE-NG declarations and permitted FNV string code inspected.
// Code origin: original reconstruction; no external implementation code copied.
// StringStaticbbe20, StringSlot, value, input, NullStringInput, text, object: GUESS(low) STANDIN
#pragma once
extern const char text[];
struct StringSlot {
    const char* value;
    StringSlot(const char*);
    ~StringSlot();
};
struct NullStringInput {};
struct StringStaticbbe20 {
    StringSlot value;
    // Require a non-null string argument. Member ownership covers failure of the input contract.
    explicit StringStaticbbe20(const char* input) : value(input) { if (!input) throw NullStringInput{}; }
    ~StringStaticbbe20() {}
};
