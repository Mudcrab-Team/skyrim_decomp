// Source exposure: binary-analysis; no external implementation source reused.
// Static176aed0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176aed0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176aed0*);
    virtual void release(Static176aed0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176aed0*);
struct Static176aed0 {
    void* value;
    Static176aed0();
    ~Static176aed0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
