// Source exposure: binary-analysis; no external implementation source reused.
// Static176ab60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ab60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ab60*);
    virtual void release(Static176ab60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ab60*);
struct Static176ab60 {
    void* value;
    Static176ab60();
    ~Static176ab60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
