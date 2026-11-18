// Source exposure: binary-analysis
// Staticb71e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb71e0;
extern void construct(Staticb71e0*, const Descriptor*);
extern void destroy(Staticb71e0*);
struct Staticb71e0 {
    void* value;
    Staticb71e0() { construct(this, &descriptor); }
    ~Staticb71e0() { destroy(this); }
};
