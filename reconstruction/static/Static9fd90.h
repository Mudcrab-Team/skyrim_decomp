// Source exposure: binary-analysis
// Static9fd90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9fd90;
extern void construct(Static9fd90*, const Descriptor*);
extern void destroy(Static9fd90*);
struct Static9fd90 {
    void* value;
    Static9fd90() { construct(this, &descriptor); }
    ~Static9fd90() { destroy(this); }
};
