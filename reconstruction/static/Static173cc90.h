// Source exposure: binary-analysis; no external implementation source reused.
// Static173cc90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173cc90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173cc90*);
    virtual void release(Static173cc90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173cc90*);
struct Static173cc90 {
    void* value;
    Static173cc90();
    ~Static173cc90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
