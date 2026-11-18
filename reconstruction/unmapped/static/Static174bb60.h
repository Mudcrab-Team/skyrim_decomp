// Source exposure: binary-analysis; no external implementation source reused.
// Static174bb60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174bb60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174bb60*);
    virtual void release(Static174bb60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174bb60*);
struct Static174bb60 {
    void* value;
    Static174bb60();
    ~Static174bb60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
