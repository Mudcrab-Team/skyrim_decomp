// Source exposure: binary-analysis; no external implementation source reused.
// Static17b3200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b3200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b3200*);
    virtual void release(Static17b3200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b3200*);
struct Static17b3200 {
    void* value;
    Static17b3200();
    ~Static17b3200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
