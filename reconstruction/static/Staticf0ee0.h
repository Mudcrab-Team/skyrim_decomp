// Source exposure: binary-analysis
// Staticf0ee0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf0ee0;
extern void construct(Staticf0ee0*, const Descriptor*);
extern void destroy(Staticf0ee0*);
struct Staticf0ee0 {
    void* value;
    Staticf0ee0() { construct(this, &descriptor); }
    ~Staticf0ee0() { destroy(this); }
};
