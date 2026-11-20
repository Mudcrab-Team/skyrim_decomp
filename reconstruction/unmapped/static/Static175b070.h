// Source exposure: binary-analysis; no external implementation source reused.
// Static175b070, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b070;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b070*);
    virtual void release(Static175b070*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b070*);
struct Static175b070 {
    void* value;
    Static175b070();
    ~Static175b070() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
