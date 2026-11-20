// Source exposure: binary-analysis; no external implementation source reused.
// Static17c7110, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c7110;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c7110*);
    virtual void release(Static17c7110*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c7110*);
struct Static17c7110 {
    void* value;
    Static17c7110();
    ~Static17c7110() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
