// Source exposure: binary-analysis
// Statica36b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica36b0;
extern void construct(Statica36b0*, const Descriptor*);
extern void destroy(Statica36b0*);
struct Statica36b0 {
    void* value;
    Statica36b0() { construct(this, &descriptor); }
    ~Statica36b0() { destroy(this); }
};
