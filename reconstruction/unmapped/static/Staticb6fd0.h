// Source exposure: binary-analysis
// Staticb6fd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6fd0;
extern void construct(Staticb6fd0*, const Descriptor*);
extern void destroy(Staticb6fd0*);
struct Staticb6fd0 {
    void* value;
    Staticb6fd0() { construct(this, &descriptor); }
    ~Staticb6fd0() { destroy(this); }
};
