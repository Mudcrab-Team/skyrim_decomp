// Source exposure: binary-analysis; no external implementation source reused.
// Static179b010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179b010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179b010*);
    virtual void release(Static179b010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179b010*);
struct Static179b010 {
    void* value;
    Static179b010();
    ~Static179b010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
