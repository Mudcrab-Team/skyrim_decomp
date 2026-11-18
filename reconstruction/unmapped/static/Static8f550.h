// Source exposure: binary-analysis
// Static8f550, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f550;
extern void construct(Static8f550*, const Descriptor*);
extern void destroy(Static8f550*);
struct Static8f550 {
    void* value;
    Static8f550() { construct(this, &descriptor); }
    ~Static8f550() { destroy(this); }
};
