// Source exposure: binary-analysis; no external implementation source reused.
// Static178da20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178da20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178da20*);
    virtual void release(Static178da20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178da20*);
struct Static178da20 {
    void* value;
    Static178da20();
    ~Static178da20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
