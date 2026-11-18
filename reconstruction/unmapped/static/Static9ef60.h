// Source exposure: binary-analysis
// Static9ef60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ef60;
extern void construct(Static9ef60*, const Descriptor*);
extern void destroy(Static9ef60*);
struct Static9ef60 {
    void* value;
    Static9ef60() { construct(this, &descriptor); }
    ~Static9ef60() { destroy(this); }
};
