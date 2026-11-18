// Source exposure: binary-analysis
// Static108420, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108420;
extern void construct(Static108420*, const Descriptor*);
extern void destroy(Static108420*);
struct Static108420 {
    void* value;
    Static108420() { construct(this, &descriptor); }
    ~Static108420() { destroy(this); }
};
