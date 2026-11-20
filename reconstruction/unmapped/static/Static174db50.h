// Source exposure: binary-analysis; no external implementation source reused.
// Static174db50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174db50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174db50*);
    virtual void release(Static174db50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174db50*);
struct Static174db50 {
    void* value;
    Static174db50();
    ~Static174db50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
