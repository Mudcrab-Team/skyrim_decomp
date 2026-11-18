// Source exposure: binary-analysis; no external implementation source reused.
// Static176ce60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ce60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ce60*);
    virtual void release(Static176ce60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ce60*);
struct Static176ce60 {
    void* value;
    Static176ce60();
    ~Static176ce60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
