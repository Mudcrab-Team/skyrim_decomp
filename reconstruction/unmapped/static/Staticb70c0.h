// Source exposure: binary-analysis
// Staticb70c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb70c0;
extern void construct(Staticb70c0*, const Descriptor*);
extern void destroy(Staticb70c0*);
struct Staticb70c0 {
    void* value;
    Staticb70c0() { construct(this, &descriptor); }
    ~Staticb70c0() { destroy(this); }
};
