// Source exposure: binary-analysis; no external implementation source reused.
// Static175b250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b250*);
    virtual void release(Static175b250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b250*);
struct Static175b250 {
    void* value;
    Static175b250();
    ~Static175b250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
