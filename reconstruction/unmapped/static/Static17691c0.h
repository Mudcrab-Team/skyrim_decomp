// Source exposure: binary-analysis; no external implementation source reused.
// Static17691c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17691c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17691c0*);
    virtual void release(Static17691c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17691c0*);
struct Static17691c0 {
    void* value;
    Static17691c0();
    ~Static17691c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
