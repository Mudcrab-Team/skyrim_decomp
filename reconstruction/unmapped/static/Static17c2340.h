// Source exposure: binary-analysis; no external implementation source reused.
// Static17c2340, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c2340;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c2340*);
    virtual void release(Static17c2340*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c2340*);
struct Static17c2340 {
    void* value;
    Static17c2340();
    ~Static17c2340() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
