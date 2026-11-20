// Source exposure: binary-analysis; no external implementation source reused.
// Static173c490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c490*);
    virtual void release(Static173c490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c490*);
struct Static173c490 {
    void* value;
    Static173c490();
    ~Static173c490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
