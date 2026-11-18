// Source exposure: binary-analysis
// Staticb7c40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7c40;
extern void construct(Staticb7c40*, const Descriptor*);
extern void destroy(Staticb7c40*);
struct Staticb7c40 {
    void* value;
    Staticb7c40() { construct(this, &descriptor); }
    ~Staticb7c40() { destroy(this); }
};
