// Source exposure: binary-analysis
// Staticb4ce0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4ce0;
extern void construct(Staticb4ce0*, const Descriptor*);
extern void destroy(Staticb4ce0*);
struct Staticb4ce0 {
    void* value;
    Staticb4ce0() { construct(this, &descriptor); }
    ~Staticb4ce0() { destroy(this); }
};
