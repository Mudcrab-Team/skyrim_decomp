// Source exposure: binary-analysis; no external implementation source reused.
// Static17b8100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b8100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b8100*);
    virtual void release(Static17b8100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b8100*);
struct Static17b8100 {
    void* value;
    Static17b8100();
    ~Static17b8100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
