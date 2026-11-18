// Source exposure: binary-analysis; no external implementation source reused.
// Static173ee20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ee20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ee20*);
    virtual void release(Static173ee20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ee20*);
struct Static173ee20 {
    void* value;
    Static173ee20();
    ~Static173ee20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
