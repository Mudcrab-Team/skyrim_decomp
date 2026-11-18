// Source exposure: binary-analysis
// Static10a280, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static10a280;
extern void construct(Static10a280*, const Descriptor*);
extern void destroy(Static10a280*);
struct Static10a280 {
    void* value;
    Static10a280() { construct(this, &descriptor); }
    ~Static10a280() { destroy(this); }
};
