// Source exposure: binary-analysis; no external implementation source reused.
// Static173f000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f000*);
    virtual void release(Static173f000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f000*);
struct Static173f000 {
    void* value;
    Static173f000();
    ~Static173f000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
