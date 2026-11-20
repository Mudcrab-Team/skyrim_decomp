// Source exposure: binary-analysis; no external implementation source reused.
// Static174d440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d440*);
    virtual void release(Static174d440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d440*);
struct Static174d440 {
    void* value;
    Static174d440();
    ~Static174d440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
