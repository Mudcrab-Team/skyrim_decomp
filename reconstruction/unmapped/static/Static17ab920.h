// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab920*);
    virtual void release(Static17ab920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab920*);
struct Static17ab920 {
    void* value;
    Static17ab920();
    ~Static17ab920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
