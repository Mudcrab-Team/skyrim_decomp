// Source exposure: binary-analysis
// Staticde520, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticde520;
extern void construct(Staticde520*, const Descriptor*);
extern void destroy(Staticde520*);
struct Staticde520 {
    void* value;
    Staticde520() { construct(this, &descriptor); }
    ~Staticde520() { destroy(this); }
};
