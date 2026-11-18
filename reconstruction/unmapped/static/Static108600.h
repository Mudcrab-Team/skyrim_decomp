// Source exposure: binary-analysis
// Static108600, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108600;
extern void construct(Static108600*, const Descriptor*);
extern void destroy(Static108600*);
struct Static108600 {
    void* value;
    Static108600() { construct(this, &descriptor); }
    ~Static108600() { destroy(this); }
};
