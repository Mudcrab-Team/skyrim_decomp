// Source exposure: binary-analysis
// Static8ad90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8ad90;
extern void construct(Static8ad90*, const Descriptor*);
extern void destroy(Static8ad90*);
struct Static8ad90 {
    void* value;
    Static8ad90() { construct(this, &descriptor); }
    ~Static8ad90() { destroy(this); }
};
