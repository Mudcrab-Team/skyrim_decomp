// Source exposure: binary-analysis; no external implementation source reused.
// Static1774610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774610*);
    virtual void release(Static1774610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774610*);
struct Static1774610 {
    void* value;
    Static1774610();
    ~Static1774610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
