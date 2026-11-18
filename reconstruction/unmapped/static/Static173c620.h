// Source exposure: binary-analysis; no external implementation source reused.
// Static173c620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c620*);
    virtual void release(Static173c620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c620*);
struct Static173c620 {
    void* value;
    Static173c620();
    ~Static173c620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
