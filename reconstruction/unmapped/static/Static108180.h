// Source exposure: binary-analysis
// Static108180, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108180;
extern void construct(Static108180*, const Descriptor*);
extern void destroy(Static108180*);
struct Static108180 {
    void* value;
    Static108180() { construct(this, &descriptor); }
    ~Static108180() { destroy(this); }
};
