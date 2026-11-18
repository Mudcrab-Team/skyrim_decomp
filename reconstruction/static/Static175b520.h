// Source exposure: binary-analysis; no external implementation source reused.
// Static175b520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b520*);
    virtual void release(Static175b520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b520*);
struct Static175b520 {
    void* value;
    Static175b520();
    ~Static175b520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
