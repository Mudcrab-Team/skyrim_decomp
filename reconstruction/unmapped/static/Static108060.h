// Source exposure: binary-analysis
// Static108060, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108060;
extern void construct(Static108060*, const Descriptor*);
extern void destroy(Static108060*);
struct Static108060 {
    void* value;
    Static108060() { construct(this, &descriptor); }
    ~Static108060() { destroy(this); }
};
