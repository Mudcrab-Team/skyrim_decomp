// Source exposure: binary-analysis
// Staticb8dc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb8dc0;
extern void construct(Staticb8dc0*, const Descriptor*);
extern void destroy(Staticb8dc0*);
struct Staticb8dc0 {
    void* value;
    Staticb8dc0() { construct(this, &descriptor); }
    ~Staticb8dc0() { destroy(this); }
};
