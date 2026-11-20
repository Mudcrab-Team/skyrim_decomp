// Source exposure: binary-analysis; no external implementation source reused.
// Static175b570, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b570;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b570*);
    virtual void release(Static175b570*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b570*);
struct Static175b570 {
    void* value;
    Static175b570();
    ~Static175b570() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
