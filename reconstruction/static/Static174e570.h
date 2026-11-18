// Source exposure: binary-analysis; no external implementation source reused.
// Static174e570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174e570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174e570*);
    virtual void release(Static174e570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174e570*);
struct Static174e570 {
    void* value;
    Static174e570();
    ~Static174e570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
