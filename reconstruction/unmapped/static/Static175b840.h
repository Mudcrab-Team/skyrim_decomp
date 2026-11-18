// Source exposure: binary-analysis; no external implementation source reused.
// Static175b840, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175b840;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175b840*);
    virtual void release(Static175b840*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175b840*);
struct Static175b840 {
    void* value;
    Static175b840();
    ~Static175b840() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
