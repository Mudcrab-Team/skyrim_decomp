// Source exposure: binary-analysis; no external implementation source reused.
// Static173c870, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c870;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c870*);
    virtual void release(Static173c870*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c870*);
struct Static173c870 {
    void* value;
    Static173c870();
    ~Static173c870() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
