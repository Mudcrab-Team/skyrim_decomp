// Source exposure: binary-analysis; no external implementation source reused.
// Static17aba10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aba10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aba10*);
    virtual void release(Static17aba10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aba10*);
struct Static17aba10 {
    void* value;
    Static17aba10();
    ~Static17aba10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
