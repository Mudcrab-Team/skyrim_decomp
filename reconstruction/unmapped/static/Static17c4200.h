// Source exposure: binary-analysis; no external implementation source reused.
// Static17c4200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c4200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c4200*);
    virtual void release(Static17c4200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c4200*);
struct Static17c4200 {
    void* value;
    Static17c4200();
    ~Static17c4200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
