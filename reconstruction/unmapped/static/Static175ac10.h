// Source exposure: binary-analysis; no external implementation source reused.
// Static175ac10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ac10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ac10*);
    virtual void release(Static175ac10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ac10*);
struct Static175ac10 {
    void* value;
    Static175ac10();
    ~Static175ac10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
