// Source exposure: binary-analysis
// Staticef880, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef880;
extern void construct(Staticef880*, const Descriptor*);
extern void destroy(Staticef880*);
struct Staticef880 {
    void* value;
    Staticef880() { construct(this, &descriptor); }
    ~Staticef880() { destroy(this); }
};
