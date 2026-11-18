// Source exposure: binary-analysis; no external implementation source reused.
// Static173f230, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f230;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f230*);
    virtual void release(Static173f230*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f230*);
struct Static173f230 {
    void* value;
    Static173f230();
    ~Static173f230() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
