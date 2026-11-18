// Source exposure: binary-analysis
// Staticb7be0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7be0;
extern void construct(Staticb7be0*, const Descriptor*);
extern void destroy(Staticb7be0*);
struct Staticb7be0 {
    void* value;
    Staticb7be0() { construct(this, &descriptor); }
    ~Staticb7be0() { destroy(this); }
};
