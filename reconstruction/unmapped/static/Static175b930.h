// Source exposure: binary-analysis; no external implementation source reused.
// Static175b930, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b930;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b930*);
    virtual void release(Static175b930*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b930*);
struct Static175b930 {
    void* value;
    Static175b930();
    ~Static175b930() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
