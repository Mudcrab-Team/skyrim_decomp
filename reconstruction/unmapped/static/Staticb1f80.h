// Source exposure: binary-analysis
// Staticb1f80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb1f80;
extern void construct(Staticb1f80*, const Descriptor*);
extern void destroy(Staticb1f80*);
struct Staticb1f80 {
    void* value;
    Staticb1f80() { construct(this, &descriptor); }
    ~Staticb1f80() { destroy(this); }
};
