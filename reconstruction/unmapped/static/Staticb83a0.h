// Source exposure: binary-analysis
// Staticb83a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb83a0;
extern void construct(Staticb83a0*, const Descriptor*);
extern void destroy(Staticb83a0*);
struct Staticb83a0 {
    void* value;
    Staticb83a0() { construct(this, &descriptor); }
    ~Staticb83a0() { destroy(this); }
};
