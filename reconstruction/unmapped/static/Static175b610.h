// Source exposure: binary-analysis; no external implementation source reused.
// Static175b610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b610*);
    virtual void release(Static175b610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b610*);
struct Static175b610 {
    void* value;
    Static175b610();
    ~Static175b610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
