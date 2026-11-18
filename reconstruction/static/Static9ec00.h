// Source exposure: binary-analysis
// Static9ec00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ec00;
extern void construct(Static9ec00*, const Descriptor*);
extern void destroy(Static9ec00*);
struct Static9ec00 {
    void* value;
    Static9ec00() { construct(this, &descriptor); }
    ~Static9ec00() { destroy(this); }
};
