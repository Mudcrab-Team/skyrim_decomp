// Source exposure: binary-analysis; no external implementation source reused.
// Static174d300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d300*);
    virtual void release(Static174d300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d300*);
struct Static174d300 {
    void* value;
    Static174d300();
    ~Static174d300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
