// Source exposure: binary-analysis
// Staticd690, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd690;
extern void construct(Staticd690*, const Descriptor*);
extern void destroy(Staticd690*);
struct Staticd690 {
    void* value;
    Staticd690() { construct(this, &descriptor); }
    ~Staticd690() { destroy(this); }
};
