// Source exposure: binary-analysis; no external implementation source reused.
// Static17aaed0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aaed0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aaed0*);
    virtual void release(Static17aaed0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aaed0*);
struct Static17aaed0 {
    void* value;
    Static17aaed0();
    ~Static17aaed0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
