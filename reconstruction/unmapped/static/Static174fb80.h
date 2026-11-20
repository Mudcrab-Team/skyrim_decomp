// Source exposure: binary-analysis; no external implementation source reused.
// Static174fb80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174fb80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174fb80*);
    virtual void release(Static174fb80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174fb80*);
struct Static174fb80 {
    void* value;
    Static174fb80();
    ~Static174fb80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
