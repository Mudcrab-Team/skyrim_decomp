// Source exposure: binary-analysis
// Staticb300, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb300;
extern void construct(Staticb300*, const Descriptor*);
extern void destroy(Staticb300*);
struct Staticb300 {
    void* value;
    Staticb300() { construct(this, &descriptor); }
    ~Staticb300() { destroy(this); }
};
