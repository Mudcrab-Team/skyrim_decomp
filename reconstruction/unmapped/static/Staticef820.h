// Source exposure: binary-analysis
// Staticef820, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef820;
extern void construct(Staticef820*, const Descriptor*);
extern void destroy(Staticef820*);
struct Staticef820 {
    void* value;
    Staticef820() { construct(this, &descriptor); }
    ~Staticef820() { destroy(this); }
};
