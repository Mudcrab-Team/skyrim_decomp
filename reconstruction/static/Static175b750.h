// Source exposure: binary-analysis; no external implementation source reused.
// Static175b750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b750*);
    virtual void release(Static175b750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b750*);
struct Static175b750 {
    void* value;
    Static175b750();
    ~Static175b750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
