// Source exposure: binary-analysis; no external implementation source reused.
// Static176ec60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ec60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ec60*);
    virtual void release(Static176ec60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ec60*);
struct Static176ec60 {
    void* value;
    Static176ec60();
    ~Static176ec60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
