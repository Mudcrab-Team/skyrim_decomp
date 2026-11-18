// Source exposure: binary-analysis
// Staticb6f10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6f10;
extern void construct(Staticb6f10*, const Descriptor*);
extern void destroy(Staticb6f10*);
struct Staticb6f10 {
    void* value;
    Staticb6f10() { construct(this, &descriptor); }
    ~Staticb6f10() { destroy(this); }
};
