// Source exposure: binary-analysis
// Staticb3ec0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb3ec0;
extern void construct(Staticb3ec0*, const Descriptor*);
extern void destroy(Staticb3ec0*);
struct Staticb3ec0 {
    void* value;
    Staticb3ec0() { construct(this, &descriptor); }
    ~Staticb3ec0() { destroy(this); }
};
