// Source exposure: binary-analysis
// Static21550, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21550;
extern void construct(Static21550*, const Descriptor*);
extern void destroy(Static21550*);
struct Static21550 {
    void* value;
    Static21550() { construct(this, &descriptor); }
    ~Static21550() { destroy(this); }
};
