// Source exposure: binary-analysis; no external implementation source reused.
// Static17b6600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b6600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b6600*);
    virtual void release(Static17b6600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b6600*);
struct Static17b6600 {
    void* value;
    Static17b6600();
    ~Static17b6600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
