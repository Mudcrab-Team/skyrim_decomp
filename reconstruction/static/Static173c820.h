// Source exposure: binary-analysis; no external implementation source reused.
// Static173c820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c820*);
    virtual void release(Static173c820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c820*);
struct Static173c820 {
    void* value;
    Static173c820();
    ~Static173c820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
