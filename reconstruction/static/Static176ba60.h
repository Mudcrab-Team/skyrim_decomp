// Source exposure: binary-analysis; no external implementation source reused.
// Static176ba60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ba60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ba60*);
    virtual void release(Static176ba60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ba60*);
struct Static176ba60 {
    void* value;
    Static176ba60();
    ~Static176ba60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
