// Source exposure: binary-analysis; no external implementation source reused.
// Static173d240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173d240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173d240*);
    virtual void release(Static173d240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173d240*);
struct Static173d240 {
    void* value;
    Static173d240();
    ~Static173d240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
