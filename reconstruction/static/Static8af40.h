// Source exposure: binary-analysis
// Static8af40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8af40;
extern void construct(Static8af40*, const Descriptor*);
extern void destroy(Static8af40*);
struct Static8af40 {
    void* value;
    Static8af40() { construct(this, &descriptor); }
    ~Static8af40() { destroy(this); }
};
