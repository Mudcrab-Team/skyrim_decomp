// Source exposure: binary-analysis
// Static108270, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108270;
extern void construct(Static108270*, const Descriptor*);
extern void destroy(Static108270*);
struct Static108270 {
    void* value;
    Static108270() { construct(this, &descriptor); }
    ~Static108270() { destroy(this); }
};
