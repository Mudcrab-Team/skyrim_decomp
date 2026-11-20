// Source exposure: binary-analysis
// Staticb1f50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb1f50;
extern void construct(Staticb1f50*, const Descriptor*);
extern void destroy(Staticb1f50*);
struct Staticb1f50 {
    void* value;
    Staticb1f50() { construct(this, &descriptor); }
    ~Staticb1f50() { destroy(this); }
};
