// Source exposure: binary-analysis; no external implementation source reused.
// Static17a1440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a1440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a1440*);
    virtual void release(Static17a1440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a1440*);
struct Static17a1440 {
    void* value;
    Static17a1440();
    ~Static17a1440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
