// Source exposure: binary-analysis
// Staticb57f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb57f0;
extern void construct(Staticb57f0*, const Descriptor*);
extern void destroy(Staticb57f0*);
struct Staticb57f0 {
    void* value;
    Staticb57f0() { construct(this, &descriptor); }
    ~Staticb57f0() { destroy(this); }
};
