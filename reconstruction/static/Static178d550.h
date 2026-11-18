// Source exposure: binary-analysis; no external implementation source reused.
// Static178d550, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178d550;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178d550*);
    virtual void release(Static178d550*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178d550*);
struct Static178d550 {
    void* value;
    Static178d550();
    ~Static178d550() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
