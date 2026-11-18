// Source exposure: binary-analysis; no external implementation source reused.
// Static173c530, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c530;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c530*);
    virtual void release(Static173c530*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c530*);
struct Static173c530 {
    void* value;
    Static173c530();
    ~Static173c530() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
