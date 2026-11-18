// Source exposure: binary-analysis; no external implementation source reused.
// Static178ce20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ce20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ce20*);
    virtual void release(Static178ce20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ce20*);
struct Static178ce20 {
    void* value;
    Static178ce20();
    ~Static178ce20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
