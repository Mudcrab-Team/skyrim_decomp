// Source exposure: binary-analysis
// Staticb79a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb79a0;
extern void construct(Staticb79a0*, const Descriptor*);
extern void destroy(Staticb79a0*);
struct Staticb79a0 {
    void* value;
    Staticb79a0() { construct(this, &descriptor); }
    ~Staticb79a0() { destroy(this); }
};
