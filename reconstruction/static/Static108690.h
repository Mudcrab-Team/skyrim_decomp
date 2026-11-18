// Source exposure: binary-analysis
// Static108690, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108690;
extern void construct(Static108690*, const Descriptor*);
extern void destroy(Static108690*);
struct Static108690 {
    void* value;
    Static108690() { construct(this, &descriptor); }
    ~Static108690() { destroy(this); }
};
