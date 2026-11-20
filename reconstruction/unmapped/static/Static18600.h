// Source exposure: binary-analysis
// Static18600, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static18600;
extern void construct(Static18600*, const Descriptor*);
extern void destroy(Static18600*);
struct Static18600 {
    void* value;
    Static18600() { construct(this, &descriptor); }
    ~Static18600() { destroy(this); }
};
