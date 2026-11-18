// Source exposure: binary-analysis; no external implementation source reused.
// Static175b020, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b020;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b020*);
    virtual void release(Static175b020*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b020*);
struct Static175b020 {
    void* value;
    Static175b020();
    ~Static175b020() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
