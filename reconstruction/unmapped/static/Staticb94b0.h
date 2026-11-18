// Source exposure: binary-analysis
// Staticb94b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb94b0;
extern void construct(Staticb94b0*, const Descriptor*);
extern void destroy(Staticb94b0*);
struct Staticb94b0 {
    void* value;
    Staticb94b0() { construct(this, &descriptor); }
    ~Staticb94b0() { destroy(this); }
};
