// Source exposure: binary-analysis
// Static108240, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108240;
extern void construct(Static108240*, const Descriptor*);
extern void destroy(Static108240*);
struct Static108240 {
    void* value;
    Static108240() { construct(this, &descriptor); }
    ~Static108240() { destroy(this); }
};
