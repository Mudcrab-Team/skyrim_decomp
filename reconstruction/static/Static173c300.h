// Source exposure: binary-analysis; no external implementation source reused.
// Static173c300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c300*);
    virtual void release(Static173c300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c300*);
struct Static173c300 {
    void* value;
    Static173c300();
    ~Static173c300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
