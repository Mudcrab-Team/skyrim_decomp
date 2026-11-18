// Source exposure: binary-analysis; no external implementation source reused.
// Static17c1410, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c1410;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c1410*);
    virtual void release(Static17c1410*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c1410*);
struct Static17c1410 {
    void* value;
    Static17c1410();
    ~Static17c1410() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
