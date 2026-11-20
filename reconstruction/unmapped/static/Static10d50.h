// Source exposure: binary-analysis
// Static10d50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static10d50;
extern void construct(Static10d50*, const Descriptor*);
extern void destroy(Static10d50*);
struct Static10d50 {
    void* value;
    Static10d50() { construct(this, &descriptor); }
    ~Static10d50() { destroy(this); }
};
