// Source exposure: mixed; binary analysis, CommonLibSSE-NG declarations and permitted FNV string code inspected.
// Code origin: original reconstruction; no external implementation code copied.
// StringStaticff000, StringSlot, value, input, NullStringInput, text, object: GUESS(low) STANDIN
#pragma once
extern const char text[];
struct StringSlot {
    const char* value;
    StringSlot(const char*);
    ~StringSlot();
};
struct NullStringInput {};
struct StringStaticff000 {
    StringSlot value;
    // Require a non-null string argument. Member ownership covers failure of the input contract.
    explicit StringStaticff000(const char* input) : value(input) { if (!input) throw NullStringInput{}; }
    ~StringStaticff000() {}
};
