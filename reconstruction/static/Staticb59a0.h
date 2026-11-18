// Source exposure: binary-analysis
// Staticb59a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb59a0;
extern void construct(Staticb59a0*, const Descriptor*);
extern void destroy(Staticb59a0*);
struct Staticb59a0 {
    void* value;
    Staticb59a0() { construct(this, &descriptor); }
    ~Staticb59a0() { destroy(this); }
};
