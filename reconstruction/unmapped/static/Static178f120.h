// Source exposure: binary-analysis; no external implementation source reused.
// Static178f120, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f120;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f120*);
    virtual void release(Static178f120*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f120*);
struct Static178f120 {
    void* value;
    Static178f120();
    ~Static178f120() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
