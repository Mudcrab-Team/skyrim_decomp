// Source exposure: binary-analysis; no external implementation source reused.
// Static173c260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c260*);
    virtual void release(Static173c260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c260*);
struct Static173c260 {
    void* value;
    Static173c260();
    ~Static173c260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
