// Source exposure: binary-analysis
// Staticc7090, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc7090;
extern void construct(Staticc7090*, const Descriptor*);
extern void destroy(Staticc7090*);
struct Staticc7090 {
    void* value;
    Staticc7090() { construct(this, &descriptor); }
    ~Staticc7090() { destroy(this); }
};
