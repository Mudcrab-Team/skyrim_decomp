// Source exposure: binary-analysis; no external implementation source reused.
// Static174cb10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174cb10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174cb10*);
    virtual void release(Static174cb10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174cb10*);
struct Static174cb10 {
    void* value;
    Static174cb10();
    ~Static174cb10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
