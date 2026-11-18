// Source exposure: binary-analysis; no external implementation source reused.
// Static173f840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f840*);
    virtual void release(Static173f840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f840*);
struct Static173f840 {
    void* value;
    Static173f840();
    ~Static173f840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
