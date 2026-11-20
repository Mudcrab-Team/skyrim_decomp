// Source exposure: binary-analysis
// Static9f550, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f550;
extern void construct(Static9f550*, const Descriptor*);
extern void destroy(Static9f550*);
struct Static9f550 {
    void* value;
    Static9f550() { construct(this, &descriptor); }
    ~Static9f550() { destroy(this); }
};
