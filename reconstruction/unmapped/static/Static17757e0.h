// Source exposure: binary-analysis; no external implementation source reused.
// Static17757e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17757e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17757e0*);
    virtual void release(Static17757e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17757e0*);
struct Static17757e0 {
    void* value;
    Static17757e0();
    ~Static17757e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
