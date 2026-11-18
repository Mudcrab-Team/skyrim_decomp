// Source exposure: binary-analysis
// Staticb5130, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5130;
extern void construct(Staticb5130*, const Descriptor*);
extern void destroy(Staticb5130*);
struct Staticb5130 {
    void* value;
    Staticb5130() { construct(this, &descriptor); }
    ~Staticb5130() { destroy(this); }
};
