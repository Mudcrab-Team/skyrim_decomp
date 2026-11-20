// Source exposure: binary-analysis; no external implementation source reused.
// Static178c470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c470*);
    virtual void release(Static178c470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c470*);
struct Static178c470 {
    void* value;
    Static178c470();
    ~Static178c470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
