// Source exposure: binary-analysis; no external implementation source reused.
// Static175b390, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b390;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b390*);
    virtual void release(Static175b390*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b390*);
struct Static175b390 {
    void* value;
    Static175b390();
    ~Static175b390() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
