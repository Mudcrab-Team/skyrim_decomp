// Source exposure: binary-analysis; no external implementation source reused.
// Static17b4240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b4240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b4240*);
    virtual void release(Static17b4240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b4240*);
struct Static17b4240 {
    void* value;
    Static17b4240();
    ~Static17b4240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
