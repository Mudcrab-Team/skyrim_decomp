// Source exposure: binary-analysis; no external implementation source reused.
// Static176bf60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176bf60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176bf60*);
    virtual void release(Static176bf60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176bf60*);
struct Static176bf60 {
    void* value;
    Static176bf60();
    ~Static176bf60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
