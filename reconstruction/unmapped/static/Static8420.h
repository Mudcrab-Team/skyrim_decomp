// Source exposure: binary-analysis
// Static8420, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8420;
extern void construct(Static8420*, const Descriptor*);
extern void destroy(Static8420*);
struct Static8420 {
    void* value;
    Static8420() { construct(this, &descriptor); }
    ~Static8420() { destroy(this); }
};
