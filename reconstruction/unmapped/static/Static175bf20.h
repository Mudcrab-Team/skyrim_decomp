// Source exposure: binary-analysis; no external implementation source reused.
// Static175bf20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175bf20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175bf20*);
    virtual void release(Static175bf20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175bf20*);
struct Static175bf20 {
    void* value;
    Static175bf20();
    ~Static175bf20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
