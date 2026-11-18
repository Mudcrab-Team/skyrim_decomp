// Source exposure: binary-analysis; no external implementation source reused.
// Static176aac0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176aac0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176aac0*);
    virtual void release(Static176aac0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176aac0*);
struct Static176aac0 {
    void* value;
    Static176aac0();
    ~Static176aac0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
