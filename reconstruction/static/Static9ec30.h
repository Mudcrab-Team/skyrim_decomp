// Source exposure: binary-analysis
// Static9ec30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ec30;
extern void construct(Static9ec30*, const Descriptor*);
extern void destroy(Static9ec30*);
struct Static9ec30 {
    void* value;
    Static9ec30() { construct(this, &descriptor); }
    ~Static9ec30() { destroy(this); }
};
