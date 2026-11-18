// Source exposure: binary-analysis
// Static8fd00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8fd00;
extern void construct(Static8fd00*, const Descriptor*);
extern void destroy(Static8fd00*);
struct Static8fd00 {
    void* value;
    Static8fd00() { construct(this, &descriptor); }
    ~Static8fd00() { destroy(this); }
};
