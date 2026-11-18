// Source exposure: binary-analysis
// Staticb7af0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7af0;
extern void construct(Staticb7af0*, const Descriptor*);
extern void destroy(Staticb7af0*);
struct Staticb7af0 {
    void* value;
    Staticb7af0() { construct(this, &descriptor); }
    ~Staticb7af0() { destroy(this); }
};
