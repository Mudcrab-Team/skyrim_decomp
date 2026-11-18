// Source exposure: binary-analysis; no external implementation source reused.
// Static176b010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b010*);
    virtual void release(Static176b010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b010*);
struct Static176b010 {
    void* value;
    Static176b010();
    ~Static176b010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
