// Source exposure: binary-analysis; no external implementation source reused.
// Static174eb60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174eb60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174eb60*);
    virtual void release(Static174eb60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174eb60*);
struct Static174eb60 {
    void* value;
    Static174eb60();
    ~Static174eb60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
