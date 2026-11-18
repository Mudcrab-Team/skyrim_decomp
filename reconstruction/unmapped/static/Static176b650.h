// Source exposure: binary-analysis; no external implementation source reused.
// Static176b650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b650*);
    virtual void release(Static176b650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b650*);
struct Static176b650 {
    void* value;
    Static176b650();
    ~Static176b650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
