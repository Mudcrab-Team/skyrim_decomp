// Source exposure: binary-analysis; no external implementation source reused.
// Static174e610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174e610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174e610*);
    virtual void release(Static174e610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174e610*);
struct Static174e610 {
    void* value;
    Static174e610();
    ~Static174e610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
