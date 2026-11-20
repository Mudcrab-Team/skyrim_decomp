// Source exposure: binary-analysis; no external implementation source reused.
// Static175e900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175e900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175e900*);
    virtual void release(Static175e900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175e900*);
struct Static175e900 {
    void* value;
    Static175e900();
    ~Static175e900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
