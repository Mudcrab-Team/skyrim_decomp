// Source exposure: binary-analysis; no external implementation source reused.
// Static17b6ce0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b6ce0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b6ce0*);
    virtual void release(Static17b6ce0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b6ce0*);
struct Static17b6ce0 {
    void* value;
    Static17b6ce0();
    ~Static17b6ce0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
