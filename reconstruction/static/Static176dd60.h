// Source exposure: binary-analysis; no external implementation source reused.
// Static176dd60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176dd60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176dd60*);
    virtual void release(Static176dd60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176dd60*);
struct Static176dd60 {
    void* value;
    Static176dd60();
    ~Static176dd60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
