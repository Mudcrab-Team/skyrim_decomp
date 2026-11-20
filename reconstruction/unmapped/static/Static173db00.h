// Source exposure: binary-analysis; no external implementation source reused.
// Static173db00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173db00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173db00*);
    virtual void release(Static173db00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173db00*);
struct Static173db00 {
    void* value;
    Static173db00();
    ~Static173db00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
