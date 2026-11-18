// Source exposure: binary-analysis; no external implementation source reused.
// Static175ac60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ac60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ac60*);
    virtual void release(Static175ac60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ac60*);
struct Static175ac60 {
    void* value;
    Static175ac60();
    ~Static175ac60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
