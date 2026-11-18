// Source exposure: binary-analysis; no external implementation source reused.
// Static176fb60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176fb60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176fb60*);
    virtual void release(Static176fb60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176fb60*);
struct Static176fb60 {
    void* value;
    Static176fb60();
    ~Static176fb60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
