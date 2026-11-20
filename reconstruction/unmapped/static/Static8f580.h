// Source exposure: binary-analysis
// Static8f580, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f580;
extern void construct(Static8f580*, const Descriptor*);
extern void destroy(Static8f580*);
struct Static8f580 {
    void* value;
    Static8f580() { construct(this, &descriptor); }
    ~Static8f580() { destroy(this); }
};
