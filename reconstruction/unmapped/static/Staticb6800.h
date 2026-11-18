// Source exposure: binary-analysis
// Staticb6800, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6800;
extern void construct(Staticb6800*, const Descriptor*);
extern void destroy(Staticb6800*);
struct Staticb6800 {
    void* value;
    Staticb6800() { construct(this, &descriptor); }
    ~Staticb6800() { destroy(this); }
};
