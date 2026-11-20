// Source exposure: binary-analysis
// Staticb4d10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4d10;
extern void construct(Staticb4d10*, const Descriptor*);
extern void destroy(Staticb4d10*);
struct Staticb4d10 {
    void* value;
    Staticb4d10() { construct(this, &descriptor); }
    ~Staticb4d10() { destroy(this); }
};
