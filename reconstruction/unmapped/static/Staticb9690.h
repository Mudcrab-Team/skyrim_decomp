// Source exposure: binary-analysis
// Staticb9690, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9690;
extern void construct(Staticb9690*, const Descriptor*);
extern void destroy(Staticb9690*);
struct Staticb9690 {
    void* value;
    Staticb9690() { construct(this, &descriptor); }
    ~Staticb9690() { destroy(this); }
};
