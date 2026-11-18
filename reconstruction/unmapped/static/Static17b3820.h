// Source exposure: binary-analysis; no external implementation source reused.
// Static17b3820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b3820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b3820*);
    virtual void release(Static17b3820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b3820*);
struct Static17b3820 {
    void* value;
    Static17b3820();
    ~Static17b3820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
