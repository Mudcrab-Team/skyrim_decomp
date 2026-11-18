// Source exposure: binary-analysis; no external implementation source reused.
// Static173cd80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173cd80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173cd80*);
    virtual void release(Static173cd80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173cd80*);
struct Static173cd80 {
    void* value;
    Static173cd80();
    ~Static173cd80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
