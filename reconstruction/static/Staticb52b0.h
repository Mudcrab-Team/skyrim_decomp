// Source exposure: binary-analysis
// Staticb52b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb52b0;
extern void construct(Staticb52b0*, const Descriptor*);
extern void destroy(Staticb52b0*);
struct Staticb52b0 {
    void* value;
    Staticb52b0() { construct(this, &descriptor); }
    ~Staticb52b0() { destroy(this); }
};
