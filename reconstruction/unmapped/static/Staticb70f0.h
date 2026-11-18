// Source exposure: binary-analysis
// Staticb70f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb70f0;
extern void construct(Staticb70f0*, const Descriptor*);
extern void destroy(Staticb70f0*);
struct Staticb70f0 {
    void* value;
    Staticb70f0() { construct(this, &descriptor); }
    ~Staticb70f0() { destroy(this); }
};
