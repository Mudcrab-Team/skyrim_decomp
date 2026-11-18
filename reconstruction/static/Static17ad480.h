// Source exposure: binary-analysis; no external implementation source reused.
// Static17ad480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ad480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ad480*);
    virtual void release(Static17ad480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ad480*);
struct Static17ad480 {
    void* value;
    Static17ad480();
    ~Static17ad480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
