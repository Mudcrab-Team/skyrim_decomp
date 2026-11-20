// Source exposure: binary-analysis; no external implementation source reused.
// Static17b3f70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b3f70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b3f70*);
    virtual void release(Static17b3f70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b3f70*);
struct Static17b3f70 {
    void* value;
    Static17b3f70();
    ~Static17b3f70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
