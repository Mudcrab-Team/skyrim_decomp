// Source exposure: binary-analysis
// Staticb6590, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6590;
extern void construct(Staticb6590*, const Descriptor*);
extern void destroy(Staticb6590*);
struct Staticb6590 {
    void* value;
    Staticb6590() { construct(this, &descriptor); }
    ~Staticb6590() { destroy(this); }
};
