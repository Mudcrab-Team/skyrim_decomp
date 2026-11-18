// Source exposure: binary-analysis; no external implementation source reused.
// Static173de20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173de20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173de20*);
    virtual void release(Static173de20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173de20*);
struct Static173de20 {
    void* value;
    Static173de20();
    ~Static173de20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
