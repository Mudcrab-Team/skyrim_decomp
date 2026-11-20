// Source exposure: binary-analysis
// Staticb7690, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7690;
extern void construct(Staticb7690*, const Descriptor*);
extern void destroy(Staticb7690*);
struct Staticb7690 {
    void* value;
    Staticb7690() { construct(this, &descriptor); }
    ~Staticb7690() { destroy(this); }
};
