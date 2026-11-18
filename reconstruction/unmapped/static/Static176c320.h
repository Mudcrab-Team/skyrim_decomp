// Source exposure: binary-analysis; no external implementation source reused.
// Static176c320, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c320;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c320*);
    virtual void release(Static176c320*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c320*);
struct Static176c320 {
    void* value;
    Static176c320();
    ~Static176c320() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
