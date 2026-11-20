// Source exposure: binary-analysis; no external implementation source reused.
// Static17b6d30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b6d30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b6d30*);
    virtual void release(Static17b6d30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b6d30*);
struct Static17b6d30 {
    void* value;
    Static17b6d30();
    ~Static17b6d30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
