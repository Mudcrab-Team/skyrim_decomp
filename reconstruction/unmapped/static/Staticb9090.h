// Source exposure: binary-analysis
// Staticb9090, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9090;
extern void construct(Staticb9090*, const Descriptor*);
extern void destroy(Staticb9090*);
struct Staticb9090 {
    void* value;
    Staticb9090() { construct(this, &descriptor); }
    ~Staticb9090() { destroy(this); }
};
