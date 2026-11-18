// Source exposure: binary-analysis
// Static8fa90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8fa90;
extern void construct(Static8fa90*, const Descriptor*);
extern void destroy(Static8fa90*);
struct Static8fa90 {
    void* value;
    Static8fa90() { construct(this, &descriptor); }
    ~Static8fa90() { destroy(this); }
};
