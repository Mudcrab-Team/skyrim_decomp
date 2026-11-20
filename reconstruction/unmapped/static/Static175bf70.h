// Source exposure: binary-analysis; no external implementation source reused.
// Static175bf70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175bf70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175bf70*);
    virtual void release(Static175bf70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175bf70*);
struct Static175bf70 {
    void* value;
    Static175bf70();
    ~Static175bf70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
