// Source exposure: binary-analysis
// Staticb98a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb98a0;
extern void construct(Staticb98a0*, const Descriptor*);
extern void destroy(Staticb98a0*);
struct Staticb98a0 {
    void* value;
    Staticb98a0() { construct(this, &descriptor); }
    ~Staticb98a0() { destroy(this); }
};
