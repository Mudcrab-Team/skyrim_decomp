// Source exposure: binary-analysis
// Staticb94e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb94e0;
extern void construct(Staticb94e0*, const Descriptor*);
extern void destroy(Staticb94e0*);
struct Staticb94e0 {
    void* value;
    Staticb94e0() { construct(this, &descriptor); }
    ~Staticb94e0() { destroy(this); }
};
