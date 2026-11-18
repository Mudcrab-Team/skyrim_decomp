// Source exposure: binary-analysis; no external implementation source reused.
// Static176e490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e490*);
    virtual void release(Static176e490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e490*);
struct Static176e490 {
    void* value;
    Static176e490();
    ~Static176e490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
