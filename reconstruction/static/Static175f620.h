// Source exposure: binary-analysis; no external implementation source reused.
// Static175f620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f620*);
    virtual void release(Static175f620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f620*);
struct Static175f620 {
    void* value;
    Static175f620();
    ~Static175f620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
