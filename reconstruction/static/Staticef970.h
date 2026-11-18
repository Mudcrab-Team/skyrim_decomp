// Source exposure: binary-analysis
// Staticef970, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef970;
extern void construct(Staticef970*, const Descriptor*);
extern void destroy(Staticef970*);
struct Staticef970 {
    void* value;
    Staticef970() { construct(this, &descriptor); }
    ~Staticef970() { destroy(this); }
};
