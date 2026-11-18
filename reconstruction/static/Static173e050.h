// Source exposure: binary-analysis; no external implementation source reused.
// Static173e050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e050*);
    virtual void release(Static173e050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e050*);
struct Static173e050 {
    void* value;
    Static173e050();
    ~Static173e050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
