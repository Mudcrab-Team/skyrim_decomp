// Source exposure: binary-analysis; no external implementation source reused.
// Static1740310, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740310;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740310*);
    virtual void release(Static1740310*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740310*);
struct Static1740310 {
    void* value;
    Static1740310();
    ~Static1740310() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
