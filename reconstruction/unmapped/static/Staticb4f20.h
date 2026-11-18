// Source exposure: binary-analysis
// Staticb4f20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4f20;
extern void construct(Staticb4f20*, const Descriptor*);
extern void destroy(Staticb4f20*);
struct Staticb4f20 {
    void* value;
    Staticb4f20() { construct(this, &descriptor); }
    ~Staticb4f20() { destroy(this); }
};
