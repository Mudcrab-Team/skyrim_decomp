// Source exposure: binary-analysis
// Staticb6f40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6f40;
extern void construct(Staticb6f40*, const Descriptor*);
extern void destroy(Staticb6f40*);
struct Staticb6f40 {
    void* value;
    Staticb6f40() { construct(this, &descriptor); }
    ~Staticb6f40() { destroy(this); }
};
