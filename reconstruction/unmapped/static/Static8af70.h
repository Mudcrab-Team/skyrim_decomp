// Source exposure: binary-analysis
// Static8af70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8af70;
extern void construct(Static8af70*, const Descriptor*);
extern void destroy(Static8af70*);
struct Static8af70 {
    void* value;
    Static8af70() { construct(this, &descriptor); }
    ~Static8af70() { destroy(this); }
};
