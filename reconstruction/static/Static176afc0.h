// Source exposure: binary-analysis; no external implementation source reused.
// Static176afc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176afc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176afc0*);
    virtual void release(Static176afc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176afc0*);
struct Static176afc0 {
    void* value;
    Static176afc0();
    ~Static176afc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
