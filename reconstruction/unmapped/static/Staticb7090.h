// Source exposure: binary-analysis
// Staticb7090, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7090;
extern void construct(Staticb7090*, const Descriptor*);
extern void destroy(Staticb7090*);
struct Staticb7090 {
    void* value;
    Staticb7090() { construct(this, &descriptor); }
    ~Staticb7090() { destroy(this); }
};
