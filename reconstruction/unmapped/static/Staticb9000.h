// Source exposure: binary-analysis
// Staticb9000, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9000;
extern void construct(Staticb9000*, const Descriptor*);
extern void destroy(Staticb9000*);
struct Staticb9000 {
    void* value;
    Staticb9000() { construct(this, &descriptor); }
    ~Staticb9000() { destroy(this); }
};
