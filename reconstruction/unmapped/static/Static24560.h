// Source exposure: binary-analysis
// Static24560, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24560;
extern void construct(Static24560*, const Descriptor*);
extern void destroy(Static24560*);
struct Static24560 {
    void* value;
    Static24560() { construct(this, &descriptor); }
    ~Static24560() { destroy(this); }
};
