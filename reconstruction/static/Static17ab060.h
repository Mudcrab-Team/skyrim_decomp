// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab060*);
    virtual void release(Static17ab060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab060*);
struct Static17ab060 {
    void* value;
    Static17ab060();
    ~Static17ab060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
