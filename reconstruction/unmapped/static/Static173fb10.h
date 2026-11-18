// Source exposure: binary-analysis; no external implementation source reused.
// Static173fb10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173fb10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173fb10*);
    virtual void release(Static173fb10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173fb10*);
struct Static173fb10 {
    void* value;
    Static173fb10();
    ~Static173fb10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
