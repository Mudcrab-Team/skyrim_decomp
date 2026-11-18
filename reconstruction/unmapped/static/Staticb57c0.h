// Source exposure: binary-analysis
// Staticb57c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb57c0;
extern void construct(Staticb57c0*, const Descriptor*);
extern void destroy(Staticb57c0*);
struct Staticb57c0 {
    void* value;
    Staticb57c0() { construct(this, &descriptor); }
    ~Staticb57c0() { destroy(this); }
};
