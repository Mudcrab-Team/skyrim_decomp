// Source exposure: binary-analysis
// Staticd090, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd090;
extern void construct(Staticd090*, const Descriptor*);
extern void destroy(Staticd090*);
struct Staticd090 {
    void* value;
    Staticd090() { construct(this, &descriptor); }
    ~Staticd090() { destroy(this); }
};
