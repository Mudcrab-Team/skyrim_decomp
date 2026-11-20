// Source exposure: binary-analysis
// Staticb7000, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7000;
extern void construct(Staticb7000*, const Descriptor*);
extern void destroy(Staticb7000*);
struct Staticb7000 {
    void* value;
    Staticb7000() { construct(this, &descriptor); }
    ~Staticb7000() { destroy(this); }
};
