// Source exposure: binary-analysis; no external implementation source reused.
// Static173fb60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173fb60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173fb60*);
    virtual void release(Static173fb60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173fb60*);
struct Static173fb60 {
    void* value;
    Static173fb60();
    ~Static173fb60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
